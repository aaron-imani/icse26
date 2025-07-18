#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr long long MOD2 = 998244353;
vector<long long> tenmod;
long long inv9;

struct S {
    long long sum;
    int l, r;
    static S E() {
        return {0, INT_MAX / 2, INT_MIN / 2};
    }
    static S op(const S& s1, const S& s2) {
        long long sum = s1.sum + s2.sum;
        if (sum >= MOD2) sum -= MOD2;
        return {sum, min(s1.l, s2.l), max(s1.r, s2.r)};
    }
    static S map(const F& f, const S& s) {
        int N = f.N;
        long long c = (tenmod[N - s.l] - tenmod[N - s.r - 1]);
        if (c < 0) c += MOD2;
        long long new_sum = (f.D * c) % MOD2;
        new_sum = (new_sum * inv9) % MOD2;
        return {new_sum, s.l, s.r};
    }
};

struct F {
    long long D;
    int N;
    static F I() { return {0, 0}; }
    static F composite(const F& f, const F& g) { return {f.D, f.N}; }
};

struct FastReader {
    FILE* in;
    char buffer[1024];
    int curbuf, lenbuf;
    FastReader() : in(stdin), curbuf(0), lenbuf(0) {}
    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            lenbuf = fread(buffer, 1, 1024, in);
        }
        return lenbuf > 0;
    }
    int readByte() {
        if (!hasNextByte()) return -1;
        return buffer[curbuf++];
    }
    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf])) curbuf++;
    }
    bool hasNext() {
        skip();
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (!isSpaceChar(b)) {
            s += (char)b;
            b = readByte();
        }
        return s;
    }
    int nextInt() {
        if (!hasNext()) throw runtime_error("No more input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw invalid_argument("Invalid integer");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long long res = 0;
        do {
            if (c < '0' || c > '9') throw invalid_argument("Invalid integer");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
    static bool isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    }
};

template<typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    vector<S> Dat;
    vector<F> Laz;
public:
    LazySegTree(int n) : MAX(n) {
        int k = 1;
        while (k < MAX) k <<= 1;
        N = k;
        Log = 31 - __builtin_clz(N);
        Dat.resize(2 * N);
        Laz.resize(N, F::I());
        for (int i = 0; i < N; ++i) {
            Dat[N + i] = S::E();
        }
        for (int i = N - 1; i >= 1; --i) {
            Dat[i] = S::op(Dat[2 * i], Dat[2 * i + 1]);
        }
    }
    
    LazySegTree(const vector<S>& dat) : MAX(dat.size()) {
        int n = dat.size();
        int k = 1;
        while (k < MAX) k <<= 1;
        N = k;
        Log = 31 - __builtin_clz(N);
        Dat.resize(2 * N);
        Laz.resize(N, F::I());
        for (int i = 0; i < n; ++i) {
            Dat[N + i] = dat[i];
        }
        for (int i = n; i < N; ++i) {
            Dat[N + i] = S::E();
        }
        for (int i = N - 1; i >= 1; --i) {
            Dat[i] = S::op(Dat[2 * i], Dat[2 * i + 1]);
        }
    }
    
    void apply(int l, int r, const F& f) {
        if (l >= r) return;
        l += N;
        r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2; ) {
            if (l2 & 1) {
                Dat[l2] = S::map(f, Dat[l2]);
                if (l2 < N) Laz[l2] = F::composite(f, Laz[l2]);
                l2++;
            }
            if (r2 & 1) {
                r2--;
                Dat[r2] = S::map(f, Dat[r2]);
                if (r2 < N) Laz[r2] = F::composite(f, Laz[r2]);
            }
            l2 >>= 1;
            r2 >>= 1;
        }
        updateFrom(l, r);
    }
    
    S allProd() {
        return Dat[1];
    }
    
private:
    void push(int k) {
        if (Laz[k] == F::I()) return;
        int lk = 2 * k;
        int rk = 2 * k + 1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = F::composite(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = F::composite(Laz[k], Laz[rk]);
        }
        Laz[k] = F::I();
    }
    
    void pushTo(int k) {
        for (int i = Log; i > 0; --i) {
            push(k >> i);
        }
    }
    
    void pushTo(int l, int r) {
        for (int i = Log; i > 0; --i) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
    }
    
    void updateFrom(int l, int r) {
        for (int i = 1; i <= Log; ++i) {
            if (((l >> i) << i) != l) {
                int node = l >> i;
                Dat[node] = S::op(Dat[2 * node], Dat[2 * node + 1]);
            }
            if (((r >> i) << i) != r) {
                int node = (r - 1) >> i;
                Dat[node] = S::op(Dat[2 * node], Dat[2 * node + 1]);
            }
        }
    }
};

long long modPow(long long x, long long y) {
    x %= MOD2;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % MOD2;
        x = (x * x) % MOD2;
        y /= 2;
    }
    return res;
}

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

int main() {
    FastReader sc;
    int N = sc.nextInt();
    int Q = sc.nextInt();
    inv9 = modInv(9);
    
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; ++j) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    
    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = {tenmod[N - i - 1], i, i};
    }
    
    LazySegTree<S, F> lazySegTree(dat);
    
    for (int q = 0; q < Q; ++q) {
        int l = sc.nextInt() - 1;
        int r = sc.nextInt() - 1;
        long long D = sc.nextLong();
        F f{D, N};
        lazySegTree.apply(l, r + 1, f);
        cout << lazySegTree.allProd().sum << '\n';
    }
    
    return 0;
}
// End of Code
