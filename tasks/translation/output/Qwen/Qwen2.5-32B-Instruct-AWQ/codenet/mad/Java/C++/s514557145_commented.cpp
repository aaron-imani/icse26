#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long z = 1;
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

class S {
public:
    static S E;
    long long sum;
    int l;
    int r;

    S(long long sum, int l, int r) : sum(sum), l(l), r(r) {}

    static S op(const S& s1, const S& s2) {
        long long sum = s1.sum + s2.sum;
        if (sum >= MOD2) {
            sum -= MOD2;
        }
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r));
    }

    static S map(const F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) {
            c += MOD2;
        }
        return S(((f.D * c) % MOD2 * modInv(9)) % MOD2, s.l, s.r);
    }
};

S S::E(0, INT_MAX / 2, INT_MIN / 2);

class F {
public:
    static F I;
    long long D;
    int N;

    F(long long D, int N) : D(D), N(N) {}

    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

F F::I(0, 0);

class LazySegTree {
public:
    int MAX;
    int N;
    int Log;
    function<S(S, S)> Op;
    S E;
    function<S(F, S)> Mapping;
    function<F(F, F)> Composition;
    F Id;
    vector<S> Dat;
    vector<F> Laz;

    LazySegTree(int n, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id) : MAX(n), Op(op), E(e), Mapping(mapping), Composition(composition), Id(id) {
        int k = 1;
        while (k < n) k <<= 1;
        N = k;
        Log = __builtin_ctz(N);
        Dat.resize(N << 1, E);
        Laz.resize(N, Id);
    }

    LazySegTree(vector<S>& dat, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id) : LazySegTree(dat.size(), op, e, mapping, composition, id) {
        build(dat);
    }

private:
    void build(const vector<S>& dat) {
        int l = dat.size();
        copy(dat.begin(), dat.end(), Dat.begin() + N);
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

public:
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
            throw invalid_argument("Invalid range: [" + to_string(l) + ", " + to_string(r) + ")");
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

    int maxRight(int l, function<bool(S)> g) {
        inclusiveRangeCheck(l);
        if (!g(E)) {
            throw invalid_argument("Identity element must satisfy the condition.");
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

    int minLeft(int r, function<bool(S)> g) {
        inclusiveRangeCheck(r);
        if (!g(E)) {
            throw invalid_argument("Identity element must satisfy the condition.");
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

private:
    void exclusiveRangeCheck(int p) {
        if (p < 0 || p >= MAX) {
            throw out_of_range("Index " + to_string(p) + " is not in [" + to_string(0) + ", " + to_string(MAX) + ").");
        }
    }

    void inclusiveRangeCheck(int p) {
        if (p < 0 || p > MAX) {
            throw out_of_range("Index " + to_string(p) + " is not in [" + to_string(0) + ", " + to_string(MAX) + "].");
        }
    }
};

vector<long long> tenmod;

class InputReader {
public:
    istream& in;
    vector<char> buffer;
    int curbuf;
    int lenbuf;

    InputReader(istream& in) : in(in), buffer(1024), curbuf(0), lenbuf(0) {}

    bool hasNextByte() {
        if (curbuf >= lenbuf) {
            curbuf = 0;
            lenbuf = in.readsome(buffer.data(), buffer.size());
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
        string sb;
        int b = readByte();
        while (!isSpaceChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
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
            res = res * 10 + c - '0';
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
            res = res * 10 + c - '0';
            c = readByte();
        } while (!isSpaceChar(c));
        return minus ? -res : res;
    }

    double nextDouble() {
        return stod(next());
    }

    vector<int> nextIntArray(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    vector<long long> nextLongArray(int n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) a[i] = nextLong();
        return a;
    }

    vector<vector<char>> nextCharMap(int n, int m) {
        vector<vector<char>> map(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            string s = next();
            for (int j = 0; j < m; j++) map[i][j] = s[j];
        }
        return map;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    InputReader sc(cin);
    int N = sc.nextInt();
    int Q = sc.nextInt();
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    vector<S> dat(N);
    for (int i = 0; i < N; i++) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }

    LazySegTree lazySegTree(dat, S::op, S::E, S::map, F::composite, F::I);

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
