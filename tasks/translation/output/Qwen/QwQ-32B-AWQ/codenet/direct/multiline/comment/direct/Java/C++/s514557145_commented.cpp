#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const long long MOD2 = 998244353;
vector<long long> tenmod;

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = res * x % MOD2;
        x = x * x % MOD2;
        y /= 2;
    }
    return res;
}

struct S {
    long long sum;
    int l;
    int r;
    static S E;
    static S op(const S& s1, const S& s2);
    static S map(const F& f, const S& s);
};

S S::E = {0, numeric_limits<int>::max() / 2, numeric_limits<int>::min() / 2};

S S::op(const S& s1, const S& s2) {
    long long sum = s1.sum + s2.sum;
    if (sum >= MOD2) sum -= MOD2;
    return {sum, min(s1.l, s2.l), max(s1.r, s2.r)};
}

S S::map(const F& f, const S& s) {
    long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) c += MOD2;
    return {(f.D * c % MOD2 * modInv(9)) % MOD2, s.l, s.r};
}

struct F {
    long long D;
    int N;
    static F I;
    static F composite(const F& f, const F& g);
};

F F::I = {0, 0};

F F::composite(const F& f, const F& g) {
    return F(f.D, f.N);
}

template<typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    S E;
    F Id;
    vector<S> Dat;
    vector<F> Laz;

    void build(const vector<S>& dat) {
        int l = dat.size();
        copy(dat.begin(), dat.end(), Dat.begin() + N);
        for (int i = N - 1; i > 0; --i)
            Dat[i] = S::op(Dat[2 * i], Dat[2 * i + 1]);
    }

public:
    LazySegTree(int n, S e, F id) : E(e), Id(id) {
        MAX = n;
        N = 1;
        while (N < MAX) N <<= 1;
        Log = 32 - __builtin_clz(N);
        Dat.resize(2 * N);
        Laz.resize(N);
        fill(Dat.begin(), Dat.end(), E);
        fill(Laz.begin(), Laz.end(), F::I);
    }

    LazySegTree(const vector<S>& dat, S e, F id) : LazySegTree(dat.size(), e, id) {
        build(dat);
    }

    void apply(int l, int r, const F& f) {
        if (l > r) return;
        if (l == r) return;
        inclusiveRangeCheck(l);
        inclusiveRangeCheck(r);
        l += N;
        r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2; ) {
            if ((l2 & 1) == 1) {
                Dat[l2] = S::map(f, Dat[l2]);
                if (l2 < N) Laz[l2] = F::composite(f, Laz[l2]);
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                Dat[r2] = S::map(f, Dat[r2]);
                if (r2 < N) Laz[r2] = F::composite(f, Laz[r2]);
            }
            l2 >>= 1;
            r2 >>= 1;
        }
        updateFrom(l, r);
    }

    S allProd() const {
        return Dat[1];
    }

private:
    void push(int k) {
        if (Laz[k] == F::I) return;
        int lk = 2 * k;
        int rk = 2 * k + 1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) Laz[lk] = F::composite(Laz[k], Laz[lk]);
        if (rk < N) Laz[rk] = F::composite(Laz[k], Laz[rk]);
        Laz[k] = F::I;
    }

    void pushTo(int k) {
        for (int i = Log; i > 0; --i)
            push(k >> i);
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
                int lki = l >> i;
                Dat[lki] = S::op(Dat[2 * lki], Dat[2 * lki + 1]);
            }
            if (((r >> i) << i) != r) {
                int rki = (r - 1) >> i;
                Dat[rki] = S::op(Dat[2 * rki], Dat[2 * rki + 1]);
            }
        }
    }

    void inclusiveRangeCheck(int p) const {
        if (p < 0 || p > MAX) throw invalid_argument("Index out of range");
    }
};

struct InputReader {
    istream& in;
    streambuf* sb;
    char buffer[1024];
    int curbuf, lenbuf;

    InputReader(istream& in) : in(in), sb(in.rdbuf()), curbuf(0), lenbuf(0) {}

    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            lenbuf = sb->sgetn(buffer, sizeof(buffer));
            if (lenbuf <= 0) return false;
        }
        return true;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[curbuf++]);
        else return -1;
    }

    bool isSpaceChar(int c) {
        return c < 33 || c > 126;
    }

    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf])) curbuf++;
    }

    bool hasNext() {
        skip();
        return hasNextByte();
    }

    int nextInt() {
        if (!hasNext()) throw runtime_error("No input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        do {
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long long res = 0;
        do {
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    InputReader in(cin);

    int N = in.nextInt();
    int Q = in.nextInt();

    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; ++j)
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;

    long long inv9 = modInv(9);

    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i].sum = tenmod[N - i - 1];
        dat[i].l = i;
        dat[i].r = i;
    }

    LazySegTree<S, F> lazySegTree(dat, S::E, F::I);

    for (int q = 0; q < Q; ++q) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        long long D = in.nextLong();
        F f(D, N);
        lazySegTree.apply(l, r+1, f);
        cout << lazySegTree.allProd().sum << '\n';
    }

    return 0;
}
// End of Code
