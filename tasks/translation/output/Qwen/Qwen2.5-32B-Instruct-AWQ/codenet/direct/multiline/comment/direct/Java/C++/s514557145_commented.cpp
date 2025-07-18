#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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

struct S {
    static const S E;
    long long sum;
    int l, r;

    S(long long sum, int l, int r) : sum(sum), l(l), r(r) {}

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

const S S::E(0, INT_MAX / 2, INT_MIN / 2);

struct F {
    static const F I;
    long long D;
    int N;

    F(long long D, int N) : D(D), N(N) {}

    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

const F F::I(0, 0);

class LazySegTree {
private:
    vector<S> dat;
    vector<F> laz;
    int N;
    int Log;
    function<S(const S&, const S&)> op;
    S E;
    function<S(const F&, const S&)> mapping;
    function<F(const F&, const F&)> composition;
    F Id;

    void push(int k) {
        if (laz[k] == Id) return;
        int lk = k << 1, rk = k << 1 | 1;
        dat[lk] = mapping(laz[k], dat[lk]);
        dat[rk] = mapping(laz[k], dat[rk]);
        if (lk < N) laz[lk] = composition(laz[k], laz[lk]);
        if (rk < N) laz[rk] = composition(laz[k], laz[rk]);
        laz[k] = Id;
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
            dat[k] = op(dat[k << 1], dat[k << 1 | 1]);
            k >>= 1;
        }
    }

    void updateFrom(int lk, int rk) {
        for (int i = 1; i <= Log; i++) {
            if (((lk >> i) << i) != lk) {
                int lki = lk >> i;
                dat[lki] = op(dat[lki << 1], dat[lki << 1 | 1]);
            }
            if (((rk >> i) << i) != rk) {
                int rki = (rk - 1) >> i;
                dat[rki] = op(dat[rki << 1], dat[rki << 1 | 1]);
            }
        }
    }

public:
    LazySegTree(vector<S>& dat, function<S(const S&, const S&)> op, S E, function<S(const F&, const S&)> mapping, function<F(const F&, const F&)> composition, F Id)
        : dat(dat.size() * 2, E), laz(dat.size(), Id), N(dat.size()), Log(32 - __builtin_clz(dat.size())), op(op), E(E), mapping(mapping), composition(composition), Id(Id) {
        copy(dat.begin(), dat.end(), this->dat.begin() + N);
        for (int i = N - 1; i > 0; i--) dat[i] = op(dat[i << 1], dat[i << 1 | 1]);
    }

    S allProd() {
        return dat[1];
    }

    void apply(int l, int r, const F& f) {
        if (l > r) throw invalid_argument("Invalid range");
        l += N; r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2;) {
            if ((l2 & 1) == 1) {
                dat[l2] = mapping(f, dat[l2]);
                if (l2 < N) laz[l2] = composition(f, laz[l2]);
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                dat[r2] = mapping(f, dat[r2]);
                if (r2 < N) laz[r2] = composition(f, laz[r2]);
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
    for (int i = 0; i < N; i++) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }

    LazySegTree lazySegTree(dat, S::op, S::E, S::map, F::composite, F::I);

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
