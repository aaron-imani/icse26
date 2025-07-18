#include <iostream>
#include <vector>
#include <algorithm>

const long MOD2 = 998244353;
long inv9;
std::vector<long> tenmod;

struct S {
    static S E;
    long sum;
    int l, r;
    S(long s = 0, int a = 0, int b = 0) : sum(s), l(a), r(b) {}
    static S op(const S& s1, const S& s2) {
        long sum = (s1.sum + s2.sum) % MOD2;
        int newl = std::min(s1.l, s2.l);
        int newr = std::max(s1.r, s2.r);
        return S(sum, newl, newr);
    }
    static S map(const struct F& f, const S& s) {
        long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        long new_sum = (f.D * c % MOD2) * inv9 % MOD2;
        return S(new_sum, s.l, s.r);
    }
};

S S::E = S(0, INT_MAX / 2, INT_MIN / 2);

struct F {
    static F I;
    long D;
    int N;
    F(long d = 0, int n = 0) : D(d), N(n) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

F F::I = F(0, 0);

long modInv(long x) {
    return modPow(x, MOD2 - 2);
}

long modPow(long x, long y) {
    long z = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            z = (z * x) % MOD2;
            y--;
        } else {
            x = (x * x) % MOD2;
            y /= 2;
        }
    }
    return z % MOD2;
}

struct InputReader {
    std::istream& in;
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    size_t curbuf, lenbuf;
    explicit InputReader(std::istream& in) : in(in), curbuf(0), lenbuf(0) {}
    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            lenbuf = in.readsome(buffer, BUFFER_SIZE);
            if (lenbuf == 0) return false;
        }
        return true;
    }
    int readByte() {
        if (hasNextByte()) return static_cast<int>(buffer[curbuf++]);
        else return -1;
    }
    bool isSpaceChar(int c) { return c < 33 || c > 126; }
    void skip() {
        while (hasNextByte() && isSpaceChar(buffer[curbuf])) curbuf++;
    }
    bool hasNext() { skip(); return hasNextByte(); }
    std::string next() {
        if (!hasNext()) throw std::runtime_error("No input");
        std::string s;
        int b = readByte();
        while (!isSpaceChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }
    int nextInt() {
        if (!hasNext()) throw std::runtime_error("No input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw std::runtime_error("Invalid input");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
    long nextLong() {
        if (!hasNext()) throw std::runtime_error("No input");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') throw std::runtime_error("Invalid input");
            res = res * 10 + (c - '0');
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }
};

template<typename S, typename F>
class LazySegTree {
private:
    int N;
    int Log;
    S* Dat;
    F* Laz;
    const S e;
    const F id;
public:
    LazySegTree(const S data[], int n) {
        N = 1;
        while (N < n) N <<= 1;
        Log = 31 - __builtin_clz(N);
        Dat = new S[2 * N];
        Laz = new F[N];
        e = S::E;
        id = F::I;
        // Initialize leaves
        for (int i = 0; i < n; ++i) {
            Dat[N + i] = data[i];
        }
        for (int i = n; i < N; ++i) {
            Dat[N + i] = e;
        }
        // Build upper levels
        for (int i = N - 1; i >= 1; --i) {
            Dat[i] = S::op(Dat[2 * i], Dat[2 * i + 1]);
        }
        // Initialize lazy to identity
        std::fill(Laz, Laz + N, id);
    }
    ~LazySegTree() {
        delete[] Dat;
        delete[] Laz;
    }
    void push(int k) {
        if (Laz[k] == id) return;
        int lk = 2 * k, rk = 2 * k + 1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = F::composite(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = F::composite(Laz[k], Laz[rk]);
        }
        Laz[k] = id;
    }
    void pushTo(int l, int r) {
        for (int i = Log; i > 0; --i) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
    }
    void apply(int l, int r, const F& f) {
        if (l >= r) return;
        l += N; r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2; ) {
            if (l2 % 2 == 1) {
                Dat[l2] = S::map(f, Dat[l2]);
                if (l2 < N) Laz[l2] = F::composite(f, Laz[l2]);
                l2++;
            }
            if (r2 % 2 == 1) {
                r2--;
                Dat[r2] = S::map(f, Dat[r2]);
                if (r2 < N) Laz[r2] = F::composite(f, Laz[r2]);
            }
            l2 >>= 1;
            r2 >>= 1;
        }
        updateFrom(l, r);
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
    S allProd() const {
        return Dat[1];
    }
};

int main() {
    inv9 = modInv(9);
    InputReader sc(std::cin);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; ++j) {
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2;
    }
    std::vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }
    LazySegTree<S, F> lazySegTree(dat.data(), N);
    for (int q = 0; q < Q; ++q) {
        int l = sc.nextInt() - 1;
        int r = sc.nextInt() - 1;
        long D = sc.nextLong();
        F f(D, N);
        lazySegTree.apply(l, r + 1, f);
        std::cout << lazySegTree.allProd().sum << std::endl;
    }
    return 0;
}
// End of Code
