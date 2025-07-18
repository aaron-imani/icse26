#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD1 = 1e9 +7;
const long long MOD2 = 998244353;

vector<long long> tenmod;

struct S {
    long long sum;
    int l, r;
    static S E;
    S(long long s, int a, int b) : sum(s), l(a), r(b) {}
    static S op(const S& s1, const S& s2) {
        long long s = (s1.sum + s2.sum) % MOD2;
        return S(s, min(s1.l, s2.l), max(s1.r, s2.r));
    }
    static S map(const struct F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2;
        if (c < 0) c += MOD2;
        return S( ( (f.D * c) % MOD2 * inv9 ) % MOD2, s.l, s.r );
    }
};

S S::E(0, numeric_limits<int>::max()/2, numeric_limits<int>::min()/2);

struct F {
    long long D;
    int N;
    static F I;
    F(long long d, int n) : D(d), N(n) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

F F::I(0, 0);

long long modInv(long long x) {
    return modPow(x, MOD2 - 2, MOD2);
}

long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

long long inv9 = modInv(9);

template<typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    S E;
    vector<S> dat;
    vector<F> laz;

    void push(int k) {
        if (laz[k] == F::I) return;
        if (k < N) {
            F f = laz[k];
            dat[2*k] = S::map(f, dat[2*k]);
            dat[2*k+1] = S::map(f, dat[2*k+1]);
            laz[2*k] = F::composite(f, laz[2*k]);
            laz[2*k+1] = F::composite(f, laz[2*k+1]);
        }
        laz[k] = F::I;
    }

public:
    LazySegTree(const vector<S>& initial, S e_val) {
        MAX = initial.size();
        N = 1;
        while (N < MAX) N <<=1;
        Log = 32 - __builtin_clz(N);
        E = e_val;
        dat.resize(2*N, E);
        laz.resize(N, F::I);
        for (int i=0; i<MAX; ++i) dat[N+i] = initial[i];
        for (int i=N-1; i>0; --i) {
            dat[i] = S::op(dat[2*i], dat[2*i+1]);
        }
    }

    void apply(int l, int r, const F& f) {
        if (l >= r) return;
        l += N; r += N;
        for (int i = Log; i >0; --i) {
            push(l >> i);
            push((r-1) >> i);
        }
        for (int a=l, b=r; a < b; ) {
            if (a % 2 ==1) {
                F current_f = f;
                dat[a] = S::map(current_f, dat[a]);
                if (a < N) {
                    laz[a] = F::composite(current_f, laz[a]);
                }
                a++;
            }
            if (b %2 ==1) {
                b--;
                F current_f = f;
                dat[b] = S::map(current_f, dat[b]);
                if (b < N) {
                    laz[b] = F::composite(current_f, laz[b]);
                }
            }
            a >>=1;
            b >>=1;
        }
        for (int i = a; i >0; i >>=1) {
            dat[i] = S::op(dat[2*i], dat[2*i+1]);
        }
        for (int i = b; i >0; i >>=1) {
            dat[i] = S::op(dat[2*i], dat[2*i+1]);
        }
    }

    S allProd() const {
        return dat[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    tenmod.resize(N+1);
    tenmod[0] = 1;
    for (int j=1; j<=N; ++j) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    vector<S> dat(N);
    for (int i=0; i<N; ++i) {
        dat[i] = S(tenmod[N - i -1], i, i);
    }
    LazySegTree<S,F> seg(dat, S::E);
    for (int q=0; q<Q; ++q) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--;
        r--;
        seg.apply(l, r+1, F(D, N));
        cout << seg.allProd().sum << '\n';
    }
    return 0;
}
// End of Code
