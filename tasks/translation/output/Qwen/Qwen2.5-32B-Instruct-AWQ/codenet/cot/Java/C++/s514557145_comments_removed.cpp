#include <iostream>
#include <vector>
#include <algorithm>

const long MOD1 = 1000000007;
const long MOD2 = 998244353;
std::vector<long> tenmod;
const long inv9 = modInv(9);

int main() {
    std::ostream& out = std::cout;
    std::istream& sc = std::cin;
    int N;
    sc >> N;
    int Q;
    sc >> Q;
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10L) % MOD2;
    }
    std::vector<S> dat(N);
    std::transform(dat.begin(), dat.end(), dat.begin(), [&](const S& s) { return S(tenmod[N - s.i - 1], s.i, s.i); });
    LazySegTree<S, F> lazySegTree(dat, S::op, S::E, S::map, F::composite, F::I);
    for (int j = 0; j < Q; j++) {
        int l;
        sc >> l;
        int r;
        sc >> r;
        long D;
        sc >> D;
        lazySegTree.apply(l - 1, r, new F(D, N));
        out << lazySegTree.allProd().sum << std::endl;
    }
    out.flush();
}

class S {
public:
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
        return S(sum, std::min(s1.l, s2.l), std::max(s1.r, s2.r));
    }
    static S map(const F& f, const S& s) {
        long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) {
            c += MOD2;
        }
        return S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
    }
};

const S S::E(0, std::numeric_limits<int>::max() / 2, std::numeric_limits<int>::min() / 2);

class F {
public:
    static const F I;
    long D;
    int N;
    F(long D, int N) : D(D), N(N) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

const F F::I(0, 0);

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
public:
    int MAX;
    int N;
    int Log;
    std::function<S(S, S)> Op;
    S E;
    std::function<S(F, S)> Mapping;
    std::function<F(F, F)> Composition;
    F Id;
    std::vector<S> Dat;
    std::vector<F> Laz;

    LazySegTree(int n, std::function<S(S, S)> op, S e, std::function<S(F, S)> mapping, std::function<F(F, F)> composition, F id) : MAX(n), N(1), Log(0), Op(op), E(e), Mapping(mapping), Composition(composition), Id(id), Dat(n * 2, E), Laz(n, Id) {
        while (N < n) N <<= 1;
        Log = 32 - __builtin_clz(N);
    }

    LazySegTree(std::vector<S>& dat, std::function<S(S, S)> op, S e, std::function<S(F, S)> mapping, std::function<F(F, F)> composition, F id) : LazySegTree(dat.size(), op, e, mapping, composition, id) {
        build(dat);
    }

    void build(std::vector<S>& dat) {
        int l = dat.size();
        std::copy(dat.begin(), dat.begin() + l, Dat.begin() + N);
        for (int i = N - 1; i > 0; i--) {
            Dat[i] = Op(Dat[i << 1 | 0], Dat[i << 1 | 1]);
        }
    }

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

    void apply(int p, F f) {
        exclusiveRangeCheck(p);
        p += N;
        pushTo(p);
        Dat[p] = Mapping(f, Dat[p]);
        updateFrom(p);
    }

    void apply(int l, int r, F f) {
        if (l > r) {
            throw std::invalid_argument("Invalid range: [" + std::to_string(l) + ", " + std::to_string(r) + ")");
        }
        inclusiveRangeCheck(l);
        inclusiveRangeCheck(r);
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

    int maxRight(int l, std::function<bool(S)> g) {
        inclusiveRangeCheck(l);
        if (!g(E)) {
            throw std::invalid_argument("Identity element must satisfy the condition.");
        }
        if (l == MAX) return MAX;
        l += N;
        pushTo(l);
        S sum = E;
        do {
            l >>= __builtin_ctz(l);
            if (!g(Op(sum, Dat[l]))) {
                while (l < N) {
                    push(l);
                    l = l << 1;
                    if (g(Op(sum, Dat[l]))) {
                        sum = Op(sum, Dat[l]);
                        l++;
                    }
                }
                return l - N;
            }
            sum = Op(sum, Dat[l]);
            l++;
        } while ((l & -l) != l);
        return MAX;
    }

    int minLeft(int r, std::function<bool(S)> g) {
        inclusiveRangeCheck(r);
        if (!g(E)) {
            throw std::invalid_argument("Identity element must satisfy the condition.");
        }
        if (r == 0) return 0;
        r += N;
        pushTo(r - 1);
        S sum = E;
        do {
            r--;
            while (r > 1 && (r & 1) == 1) r >>= 1;
            if (!g(Op(Dat[r], sum))) {
                while (r < N) {
                    push(r);
                    r = r << 1 | 1;
                    if (g(Op(Dat[r], sum))) {
                        sum = Op(Dat[r], sum);
                        r--;
                    }
                }
                return r + 1 - N;
            }
            sum = Op(Dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }

    void exclusiveRangeCheck(int p) {
        if (p < 0 || p >= MAX) {
            throw std::out_of_range("Index " + std::to_string(p) + " is not in [" + std::to_string(0) + ", " + std::to_string(MAX) + ").");
        }
    }

    void inclusiveRangeCheck(int p) {
        if (p < 0 || p > MAX) {
            throw std::out_of_range("Index " + std::to_string(p) + " is not in [" + std::to_string(0) + ", " + std::to_string(MAX) + "].");
        }
    }

    int indent = 6;

    void setIndent(int newIndent) {
        this->indent = newIndent;
    }

    std::string toString() {
        return toString(1, 0);
    }

    std::string toString(int k, int sp) {
        if (k >= N) return indent(sp) + std::to_string(Dat[k]);
        std::string s = "";
        s += toString(k << 1 | 1, sp + indent);
        s += "\n";
        s += indent(sp) + std::to_string(Dat[k]) + "/" + std::to_string(Laz[k]);
        s += "\n";
        s += toString(k << 1 | 0, sp + indent);
        return s;
    }

    static std::string indent(int n) {
        std::string sb;
        while (n-- > 0) sb += ' ';
        return sb;
    }
};

class InputReader {
private:
    std::istream& in;
    std::vector<char> buffer;
    int curbuf;
    int lenbuf;

public:
    InputReader(std::istream& in) : in(in), buffer(1024), curbuf(0), lenbuf(0) {}

    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            in.read(buffer.data(), buffer.size());
            lenbuf = in.gcount();
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

    std::string next() {
        if (!hasNext()) throw std::out_of_range("No more elements to read.");
        std::string sb;
        int b = readByte();
        while (!isSpaceChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    int nextInt() {
        if (!hasNext()) throw std::out_of_range("No more elements to read.");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') throw std::invalid_argument("Invalid integer format.");
            res = res * 10 + c - '0';
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }

    long nextLong() {
        if (!hasNext()) throw std::out_of_range("No more elements to read.");
        int c = readByte();
        while (isSpaceChar(c)) c = readByte();
        bool minus = false;
        if (c == '-') {
            minus = true;
            c = readByte();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') throw std::invalid_argument("Invalid long format.");
            res = res * 10 + c - '0';
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }

    double nextDouble() {
        return std::stod(next());
    }

    std::vector<int> nextIntArray(int n) {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    std::vector<long> nextLongArray(int n) {
        std::vector<long> a(n);
        for (int i = 0; i < n; i++) a[i] = nextLong();
        return a;
    }

    std::vector<std::vector<char>> nextCharMap(int n, int m) {
        std::vector<std::vector<char>> map(n, std::vector<char>(m));
        for (int i = 0; i < n; i++) map[i] = std::vector<char>(next().begin(), next().end());
        return map;
    }
};

// End of Code
