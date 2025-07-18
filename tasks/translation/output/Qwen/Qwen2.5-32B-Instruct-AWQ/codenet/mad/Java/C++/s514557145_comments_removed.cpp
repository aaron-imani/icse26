#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;

long long tenmod[100005];
long long inv9;

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

struct S {
    long long sum;
    int l, r;
    static S E;
    S(long long sum = 0, int l = INT_MAX / 2, int r = INT_MIN / 2) : sum(sum), l(l), r(r) {}
    static S op(const S& s1, const S& s2) {
        long long sum = s1.sum + s2.sum;
        if (sum >= MOD2) sum -= MOD2;
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r));
    }
    static S map(const F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        return S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
    }
};

S S::E(0, INT_MAX / 2, INT_MIN / 2);

struct F {
    long long D;
    int N;
    static F I;
    F(long long D = 0, int N = 0) : D(D), N(N) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

F F::I(0, 0);

template <typename S, typename F>
class LazySegTree {
public:
    vector<S> Dat;
    vector<F> Laz;
    int N, Log;
    S E;
    F Id;
    function<S(S, S)> Op;
    function<S(F, S)> Mapping;
    function<F(F, F)> Composition;

    LazySegTree(int n, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id) : N(1), Log(0), E(e), Id(id), Op(op), Mapping(mapping), Composition(composition) {
        while (N < n) N <<= 1, Log++;
        Dat.resize(2 * N, E);
        Laz.resize(N, Id);
    }

    LazySegTree(vector<S>& dat, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id) : N(1), Log(0), E(e), Id(id), Op(op), Mapping(mapping), Composition(composition) {
        while (N < dat.size()) N <<= 1, Log++;
        Dat.resize(2 * N, E);
        Laz.resize(N, Id);
        build(dat);
    }

private:
    void build(vector<S>& dat) {
        for (int i = 0; i < dat.size(); i++) Dat[N + i] = dat[i];
        for (int i = N - 1; i > 0; i--) Dat[i] = Op(Dat[i << 1 | 0], Dat[i << 1 | 1]);
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
        if (l == N) return N;
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
        return N;
    }

    int minLeft(int r, function<bool(S)> g) {
        inclusiveRangeCheck(r);
        if (!g(E)) {
            throw invalid_argument("Identity element must satisfy the condition.");
        }
        if (r == 0) return  0;
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
        if (p < 0 || p >= N) {
            throw out_of_range("Index " + to_string(p) + " is not in [" + to_string(0) + ", " + to_string(N) + ").");
        }
    }

    void inclusiveRangeCheck(int p) {
        if (p < 0 || p > N) {
            throw out_of_range("Index " + to_string(p) + " is not in [" + to_string(0) + ", " + to_string(N) + "].");
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    inv9 = modInv(9);

    vector<S> dat(N);
    for (int i = 0; i < N; i++) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }

    LazySegTree<S, F> lazySegTree(dat, S::op, S::E, S::map, F::composite, F::I);

    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--;
        lazySegTree.apply(l, r, F(D, N));
        cout << lazySegTree.allProd().sum << '\n';
    }

    return 0;
}
// End of Code
