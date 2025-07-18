#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr long long MOD1 = 1e9 + 7;
constexpr long long MOD2 = 998244353;

vector<long long> tenmod;

struct S {
    long long sum;
    int l, r;
    static const S E;
    static S op(const S& a, const S& b);
    static S map(const F& f, const S& s);
};

const S S::E = {0, INT_MAX / 2, INT_MIN / 2};

struct F {
    long long D;
    int N;
    static F composite(const F& f, const F& g);
    static const F I;
};

const F F::I = {0, 0};

long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

const long long inv9 = modInv(9, MOD2);

S S::op(const S& a, const S& b) {
    long long new_sum = (a.sum + b.sum) % MOD2;
    int new_l = min(a.l, b.l);
    int new_r = max(a.r, b.r);
    return {new_sum, new_l, new_r};
}

S S::map(const F& f, const S& s) {
    int n = f.N;
    int l = s.l, r = s.r;
    long long c = (tenmod[n - l] - tenmod[n - r - 1]) % MOD2;
    if (c < 0) c += MOD2;
    long long res = (f.D * c) % MOD2;
    res = (res * inv9) % MOD2;
    return {res, s.l, s.r};
}

F F::composite(const F& f, const F& g) {
    return {f.D, f.N};
}

class FastInput {
private:
    istream& in;
    char buf[1 << 15];
    size_t ptr = 0, len = 0;
public:
    FastInput(istream& is) : in(is) {}
    
    char nextChar() {
        if (ptr == len) {
            ptr = 0;
            len = in.readsome(buf, sizeof(buf));
            if (len == 0) return EOF;
        }
        return buf[ptr++];
    }
    
    int nextInt() {
        char c = nextChar();
        while (isspace(c)) c = nextChar();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = nextChar();
        }
        int res = 0;
        while (!isspace(c)) {
            res = res * 10 + (c - '0');
            c = nextChar();
        }
        return res * sign;
    }
    
    long long nextLong() {
        char c = nextChar();
        while (isspace(c)) c = nextChar();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = nextChar();
        }
        long long res = 0;
        while (!isspace(c)) {
            res = res * 10 + (c - '0');
            c = nextChar();
        }
        return res * sign;
    }
};

template<typename S, typename F>
class LazySegTree {
private:
    int N;
    int Log;
    vector<S> dat;
    vector<F> laz;
    S (*op)(const S&, const S&);
    S E;
    S (*mapping)(const F&, const S&);
    F (*composition)(const F&, const F&);
    F I;
    
    void push(int k) {
        if (laz[k] == I) return;
        int left = (k << 1);
        int right = (k << 1) | 1;
        dat[left] = mapping(laz[k], dat[left]);
        dat[right] = mapping(laz[k], dat[right]);
        if (left < N) {
            laz[left] = composition(laz[k], laz[left]);
        }
        if (right < N) {
            laz[right] = composition(laz[k], laz[right]);
        }
        laz[k] = I;
    }
    
    void pushTo(int l, int r) {
        for (int i = Log; i > 0; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
    }
    
public:
    LazySegTree(const vector<S>& initial, S (*op_func)(const S&, const S&), S E_val, S (*map_func)(const F&, const S&), F (*comp_func)(const F&, const F&), F I_val) :
        op(op_func), E(E_val), mapping(map_func), composition(comp_func), I(I_val) {
        int n = initial.size();
        N = 1;
        while (N < n) N <<= 1;
        Log = 32 - __builtin_clz(N);
        dat.resize(2 * N, E_val);
        laz.resize(N, I_val);
        for (int i = 0; i < n; ++i) {
            dat[N + i] = initial[i];
        }
        for (int i = N - 1; i >= 1; --i) {
            dat[i] = op(dat[2 * i], dat[2 * i + 1]);
        }
    }
    
    S allProd() const {
        return dat[1];
    }
    
    void apply(int l, int r, const F& f) {
        if (l >= r) return;
        l += N;
        r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2;) {
            if ((l2 & 1) == 1) {
                dat[l2] = mapping(f, dat[l2]);
                if (l2 < N) {
                    laz[l2] = composition(f, laz[l2]);
                }
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                dat[r2] = mapping(f, dat[r2]);
                if (r2 < N) {
                    laz[r2] = composition(f, laz[r2]);
                }
            }
            l2 >>= 1;
            r2 >>= 1;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    FastInput in(cin);
    int N = in.nextInt();
    int Q = in.nextInt();
    
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; ++j) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    
    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = {tenmod[N - i - 1], i, i};
    }
    
    LazySegTree<S, F> segTree(dat, &S::op, S::E, &S::map, &F::composite, F::I);
    
    for (int q = 0; q < Q; ++q) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        long long D = in.nextLong();
        F f = {D, N};
        segTree.apply(l, r + 1, f);
        cout << segTree.allProd().sum << endl;
    }
    
    return 0;
}
// End of Code
