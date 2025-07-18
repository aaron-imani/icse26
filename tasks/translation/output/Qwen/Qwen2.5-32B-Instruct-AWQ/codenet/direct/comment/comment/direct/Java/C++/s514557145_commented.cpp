#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;

class S {
public:
    static const S E;
    long long sum;
    int l, r;

    S(long long sum = 0, int l = INT_MAX / 2, int r = INT_MIN / 2) : sum(sum), l(l), r(r) {}

    static S op(const S& s1, const S& s2) {
        long long sum = s1.sum + s2.sum;
        if (sum >= MOD2) sum -= MOD2;
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r));
    }

    static S map(const F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        return S(((f.D * c) % MOD2 * modInv(9)) % MOD2, s.l, s.r);
    }
};

const S S::E;

class F {
public:
    static const F I;
    long long D;
    int N;

    F(long long D = 0, int N = 0) : D(D), N(N) {}

    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

const F F::I;

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

template<typename S, typename F>
class LazySegTree {
private:
    int MAX, N, Log;
    function<S(S, S)> Op;
    S E;
    function<S(F, S)> Mapping;
    function<F(F, F)> Composition;
    F Id;
    vector<S> Dat;
    vector<F> Laz;

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
        : MAX(n), N(1), Log(0), Op(op), E(e), Mapping(mapping), Composition(composition), Id(id) {
        while (N < n) N <<= 1;
        Log = __builtin_ctz(N);
        Dat.resize(N << 1, E);
        Laz.resize(N, Id);
    }

    LazySegTree(vector<S>& dat, function<S(S, S)> op, S e, function<S(F, S)> mapping, function<F(F, F)> composition, F id)
        : LazySegTree(dat.size(), op, e, mapping, composition, id) {
        build(dat);
    }

    void build(vector<S>& dat) {
        int l = dat.size();
        copy(dat.begin(), dat.begin() + l, Dat.begin() + N);
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<long long> tenmod(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    vector<S> dat(N);
    for (int j = 0; j < N; j++) {
        dat[j] = S(tenmod[N - j - 1], j, j);
    }

    LazySegTree<S, F> lazySegTree(dat, S::op, S::E, S::map, F::composite, F::I);

    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--; r--;
        lazySegTree.apply(l, r + 1, F(D, N));
        cout << lazySegTree.allProd().sum << '\n';
    }

    return 0;
}
// End of Code
