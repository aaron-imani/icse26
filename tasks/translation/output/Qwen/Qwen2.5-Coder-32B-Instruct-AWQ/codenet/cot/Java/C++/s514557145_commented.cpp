#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const long MOD1 = 1000000007;
const long MOD2 = 998244353;
long tenmod[100005];
const long inv9 = modInv(9);

struct S {
    static const S E;
    long sum;
    int l;
    int r;
    S(long sum, int l, int r) : sum(sum), l(l), r(r) {}
    static S op(const S& s1, const S& s2) {
        long sum = s1.sum + s2.sum;
        if (sum >= MOD2) {
            sum -= MOD2;
        }
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r));
    }
    static S map(const struct F& f, const S& s) {
        long c = (tenmod[(f.N - s.l)] - tenmod[(f.N - s.r - 1)]);
        if (c < 0) {
            c += MOD2;
        }
        return S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
    }
};

const S S::E = S(0, numeric_limits<int>::max() / 2, numeric_limits<int>::min() / 2);

struct F {
    static const F I;
    long D;
    int N;
    F(long D, int N) : D(D), N(N) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

const F F::I = F(0, 0);

long modInv(long x) {
    return modPow(x, MOD2 - 2);
}

long modPow(long x, long y) {
    long z = 1;
    while (y > 0) {
        if (y % 2 == 0) {
            x = (x * x) % MOD2;
            y /= 2;
        } else {
            z = (z * x) % MOD2;
            y--;
        }
    }
    return z;
}

template <typename S, typename F>
class LazySegTree {
    const int MAX;
    const int N;
    const int Log;
    const function<S(S, S)> Op;
    const S E;
    const function<S(F, S)> Mapping;
    const function<F(F, F)> Composition;
    const F Id;
    S Dat[2 * 100005];
    F Laz[100005];

    void push(int k) {
        if (Laz[k] == Id) return;
        int lk = k << 1 | 0, rk = k << 1 | 1;
        Dat[lk] = Mapping(Laz[k], Dat[lk]);
        Dat[rk] = Mapping(Laz[k], Dat[rk]);
        if (lk < N) Laz[lk] = Composition(Laz[k], Laz[lk]);
        if (rk < N) Laz[rk] = Composition(Laz[k], Laz[rk]);
        Laz[k] = Id;
    }

    void pushTo(int k) {
        for (int i = Log; i > 0; i--) push(k >> i);
    }

    void pushTo(int lk, int rk) {
        for (int i = Log; i > 0; i--) {
            if (((lk >> i) << i) != lk) push(lk >> i);
            if (((rk >> i) << i) != rk) push(rk >> i);
        }
    }

    void updateFrom(int k) {
        k >>= 1;
        while (k > 0) {
            Dat[k] = Op(Dat[k << 1 | 0], Dat[k << 1 | 1]);
            k >>= 1;
        }
    }

    void updateFrom(int lk, int rk) {
        for (int i = 1; i <= Log; i++) {
            if (((lk >> i) << i) != lk) {
                int lki = lk >> i;
                Dat[lki] = Op(Dat[lki << 1 | 0], Dat[lki << 1 | 1]);
            }
            if (((rk >> i) << i) != rk) {
                int rki = (rk - 1) >> i;
                Dat[rki] = Op(Dat[rki << 1 | 0], Dat[rki << 1 | 1]);
            }
        }
    }

public:
    LazySegTree(int n, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id)
        : MAX(n), Op(op), E(e), Mapping(mapping), Composition(composition), Id(id) {
        int k = 1;
        while (k < n) k <<= 1;
        this->N = k;
        this->Log = 32 - __builtin_clz(N);
        fill(Dat, Dat + 2 * N, E);
        fill(Laz, Laz + N, Id);
    }

    LazySegTree(S* dat, int n, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id)
        : LazySegTree(n, op, e, mapping, composition, id) {
        build(dat);
    }

    void build(S* dat) {
        int l = MAX;
        copy(dat, dat + l, Dat + N);
        for (int i = N - 1; i > 0; i--) {
            Dat[i] = Op(Dat[i << 1 | 0], Dat[i << 1 | 1]);
        }
    }

    void set(int p, S x) {
        if (p < 0 || p >= MAX) throw out_of_range("Index out of range");
        p += N;
        pushTo(p);
        Dat[p] = x;
        updateFrom(p);
    }

    S get(int p) {
        if (p < 0 || p >= MAX) throw out_of_range("Index out of range");
        p += N;
        pushTo(p);
        return Dat[p];
    }

    S allProd() {
        return Dat[1];
    }

    void apply(int p, F f) {
        if (p < 0 || p >= MAX) throw out_of_range("Index out of range");
        p += N;
        pushTo(p);
        Dat[p] = Mapping(f, Dat[p]);
        updateFrom(p);
    }

    void apply(int l, int r, F f) {
        if (l > r) throw invalid_argument("Invalid range");
        if (l < 0 || l > MAX || r < 0 || r > MAX) throw out_of_range("Index out of range");
        if (l == r) return;
        l += N; r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2;) {
            if ((l2 & 1) == 1) {
                Dat[l2] = Mapping(f, Dat[l2]);
                if (l2 < N) Laz[l2] = Composition(f, Laz[l2]);
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                Dat[r2] = Mapping(f, Dat[r2]);
                if (r2 < N) Laz[r2] = Composition(f, Laz[r2]);
            }
            l2 >>= 1; r2 >>= 1;
        }
        updateFrom(l, r);
    }
};

class InputReader {
private:
    istream& in;
    char buffer[1024];
    int curbuf;
    int lenbuf;

public:
    InputReader(istream& in) : in(in), curbuf(0), lenbuf(0) {}

    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            in.read(buffer, sizeof(buffer));
            lenbuf = in.gcount();
            if (lenbuf <= 0)
                return false;
        }
        return true;
    }

    int readByte() {
        if (hasNextByte())
            return buffer[curbuf++];
        else
            return -1;
    }

    bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf]))
            curbuf++;
    }

    bool hasNext() {
        skip();
        return hasNextByte();
    }

    string next() {
        if (!hasNext())
            throw runtime_error("No more elements in input");
        string sb;
        int b = readByte();
        while (!isSpaceChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    int nextInt() {
        if (!hasNext())
            throw runtime_error("No more elements in input");
        int c = readByte();
        while (isSpaceChar(c))
            c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw runtime_error("Invalid integer");
            res = res * 10 + c - '0';
            c = readByte();
        } while (!isSpaceChar(c));
        return (minus) ? -res : res;
    }

    long long nextLong() {
        if (!hasNext())
            throw runtime_error("No more elements in input");
        int c = readByte();
        while (isSpaceChar(c))
            c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long long res = 0;
        do {
            if (c < '0' || c > '9')
                throw runtime_error("Invalid integer");
            res = res * 10 + c - '0';
            c = readByte();
        } while (!isSpaceChar(c));
        return (minus) ? -res : res;
    }

    double nextDouble() {
        return stod(next());
    }
};

int main() {
    InputReader sc(cin);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    S dat[N];
    for (int i = 0; i < N; i++) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }
    LazySegTree<S, F> lazySegTree(dat, N, S::op, S::E, S::map, F::composite, F::I);
    for (int j = 0; j < Q; j++) {
        int l = sc.nextInt() - 1;
        int r = sc.nextInt() - 1;
        long long D = sc.nextLong();
        lazySegTree.apply(l, r + 1, F(D, N));
        cout << lazySegTree.allProd().sum << "\n";
    }
    cout.flush();
    // End of Code
}
