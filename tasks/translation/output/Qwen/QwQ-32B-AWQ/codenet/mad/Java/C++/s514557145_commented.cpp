#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;
long long inv9;
vector<long long> tenmod;

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long z = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            z = z * x % MOD2;
            y--;
        } else {
            x = x * x % MOD2;
            y /= 2;
        }
    }
    return z;
}

struct S {
    static S E;
    long long sum;
    int l, r;
    S(long long s, int a, int b) : sum(s), l(a), r(b) {}
    static S op(const S& s1, const S& s2) {
        long long s = s1.sum + s2.sum;
        if (s >= MOD2) s -= MOD2;
        return S(s, min(s1.l, s2.l), max(s1.r, s2.r));
    }
    static S map(const F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        long long val = (f.D * c % MOD2) * inv9 % MOD2;
        return S(val, s.l, s.r);
    }
};
S S::E = S(0, INT_MAX/2, INT_MIN/2);

struct F {
    static F I;
    long long D;
    int N;
    F(long long d, int n) : D(d), N(n) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};
F F::I = F(0, 0);

struct InputReader {
    char buffer[1024];
    int curbuf, lenbuf;
    
    InputReader() : curbuf(0), lenbuf(0) {}
    
    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf =  gebruiken 0;
            lenbuf = fread(buffer, 1, 1024, stdin);
            if (lenbuf <= 0) return false;
        }
        return true;
    }
    
    int readByte() {
        if (hasNextByte()) return buffer[curbuf++];
        else return -1;
    }
    
    bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
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
            if (c < '0' || c > '9') throw runtime_error("Invalid input");
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
            if (c < '0' || c > '9') throw runtime_error("Invalid input");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
};

template<typename S, typename F>
class LazySegTree {
public:
    int MAX;
    int N;
    int Log;
    S E;
    F Id;
    vector<S> Dat;
    vector<F> Laz;
    
    LazySegTree(int n, S e, F id) {
        E = e;
        Id = id;
        int k = 1;
        while (k < n) k <<= 1;
        N = k;
        MAX = n;
        Log = __builtin_ctz(N);
        Dat.resize(N * 2);
        Laz.resize(N);
        for (int i = 0; i < Dat.size(); i++) Dat[i] = E;
        for (int i = 0; i < Laz.size(); i++) Laz[i] = Id;
    }
    
    LazySegTree(const vector<S>& dat, S e, F id) : LazySegTree(dat.size(), e, id) {
        build(dat);
    }
    
    void build(const vector<S>& dat) {
        int l = dat.size();
        for (int i = 0; i < l; i++) Dat[N + i] = dat[i];
        for (int i = N - 1; i > 0; i--) {
            Dat[i] = S::op(Dat[i << 1 | 0], Dat[i << 1 | 1]);
        }
    }
    
    void push(int k) {
        if (Laz[k] == Id) return;
        int lk = (k << 1) | 0;
        int rk = (k << 1) | 1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = F::composite(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = F::composite(Laz[k], Laz[rk]);
        }
        Laz[k] = Id;
    }
    
    void pushTo(int k) {
        for (int i = Log; i > 0; i--) {
            push(k >> i);
        }
    }
    
    void pushTo(int lk, int rk) {
        for (int i = Log; i > 0; i--) {
            if (((lk >> i) << i) != lk) push(lk >> i);
            if (((rk >> i) << i) != rk) push(rk >> i);
        }
    }
    
    void set(int p, S x) {
        exclusiveRangeCheck(p);
        p += N;
        pushTo(p);
        Dat[p] = x;
        updateFrom(p);
    }
    
    S get(int p) {
        exclusiveRangeCheck(p);
        p += N;
        pushTo(p);
        return Dat[p];
    }
    
    S allProd() {
        return Dat[1];
    }
    
    void apply(int p, const F& f) {
        exclusiveRangeCheck(p);
        p += N;
        pushTo(p);
        Dat[p] = S::map(f, Dat[p]);
        updateFrom(p);
    }
    
    void apply(int l, int r, const F& f) {
        if (l > r) throw runtime_error("Invalid range");
        inclusiveRangeCheck(l);
        inclusiveRangeCheck(r);
        if (l == r) return;
        l += N;
        r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2; ) {
            if ((l2 & 1) == 1) {
                Dat[l2] = S::map(f, Dat[l2]);
                if (l2 < N) {
                    Laz[l2] = F::composite(f, Laz[l2]);
                }
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                Dat[r2] = S::map(f, Dat[r2]);
                if (r2 < N) {
                    Laz[r2] = F::composite(f, Laz[r2]);
                }
            }
            l2 >>= 1;
            r2 >>= 1;
        }
        updateFrom(l, r);
    }
    
    int maxRight(int l, function<bool(const S&)> g) {
        inclusiveRangeCheck(l);
        if (!g(E)) throw runtime_error("Identity element must satisfy the condition.");
        if (l == MAX) return MAX;
        l += N;
        pushTo(l);
        S sum = E;
        do {
            l >>= __builtin_ctz(l);
            if (!g(S::op(sum, Dat[l]))) {
                while (l < N) {
                    push(l);
                    l <<= 1;
                    if (g(S::op(sum, Dat[l]))) {
                        sum = S::op(sum, Dat[l]);
                        l++;
                    }
                }
                return l - N;
            }
            sum = S::op(sum, Dat[l]);
            l++;
        } while ((l & -l) != l);
        return MAX;
    }
    
    int minLeft(int r, function<bool(const S&)> g) {
        inclusiveRangeCheck(r);
        if (!g(E)) throw runtime_error("Identity element must satisfy the condition.");
        if (r == 0) return 0;
        r += N;
        pushTo(r - 1);
        S sum = E;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!g(S::op(Dat[r], sum))) {
                while (r < N) {
                    push(r);
                    r = (r << 1) | 1;
                    if (g(S::op(Dat[r], sum))) {
                        sum = S::op(Dat[r], sum);
                        r--;
                    }
                }
                return r + 1 - N;
            }
            sum = S::op(Dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
    
    void exclusiveRangeCheck(int p) {
        if (p < 0 || p >= MAX) {
            throw runtime_error("Index out of bounds");
        }
    }
    
    void inclusiveRangeCheck(int p) {
        if (p < 0 || p > MAX) {
            throw runtime_error("Index out of bounds");
        }
    }
    
    void updateFrom(int k) {
        k >>= 1;
        while (k > 0) {
            Dat[k] = S::op(Dat[k << 1 | 0], Dat[k << 1 | 1]);
            k >>= 1;
        }
    }
    
    void updateFrom(int lk, int rk) {
        for (int i = 1; i <= Log; i++) {
            if (((lk >> i) << i) != lk) {
                int lki = lk >> i;
                Dat[lki] = S::op(Dat[lki << 1 | 0], Dat[lki << 1 | 1]);
            }
            if (((rk >> i) << i) != rk) {
                int rki = (rk - 1) >> i;
                Dat[rki] = S::op(Dat[rki << 1 | 0], Dat[rki << 1 | 1]);
            }
        }
    }
};

int main() {
    inv9 = modInv(9);
    InputReader sc;
    int N = sc.nextInt();
    int Q = sc.nextInt();
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }
    LazySegTree<S, F> lazySegTree(dat, S::E, F::I);
    for (int j = 0; j < Q; j++) {
        int l = sc.nextInt() - 1;
        int r = sc.nextInt() - 1;
        long long D = sc.nextLong();
        lazySegTree.apply(l, r + 1, F(D, N));
        cout << lazySegTree.allProd().sum << '\n';
    }
    return 0;
}
// End of Code
