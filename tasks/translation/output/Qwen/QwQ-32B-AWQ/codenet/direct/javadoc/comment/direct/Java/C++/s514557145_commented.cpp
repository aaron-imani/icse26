#include <iostream>
#include <vector>
#include <functional>
using namespace std;

const long long MOD2 = 998244353;
long long modPow(long long x, long long y) {
    x %= MOD2;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = res * x % MOD2;
        x = x * x % MOD2;
        y /= 2;
    }
    return res;
}

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

const long long inv9 = modInv(9);

struct S {
    long long sum;
    int l, r;
    static const S E;
    static S op(const S& a, const S& b) {
        long long s = (a.sum + b.sum) % MOD2;
        return {s, min(a.l, b.l), max(a.r, b.r)};
    }
    static S map(const F& f, const S& s);
};

const S S::E = {0, INT_MAX/2, INT_MIN/2};

struct F {
    long long D;
    int N;
    static const F I;
    static F composite(const F& f, const F& g) {
        return {f.D, f.N};
    }
};

const F F::I = {0, 0};

vector<long long> tenmod;

S S::map(const F& f, const S& s) {
    int N_val = f.N;
    long long c = (tenmod[N_val - s.l] - tenmod[N_val - s.r - 1]) % MOD2;
    if (c < 0) c += MOD2;
    return {(c * f.D % MOD2 * inv9) % MOD2, s.l, s.r};
}

template <typename S, typename F>
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
        int lk = 2 * k, rk = 2 * k + 1;
        Dat[lk] = Mapping(Laz[k], Dat[lk]);
        Dat[rk] = Mapping(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = Composition(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = Composition(Laz[k], Laz[rk]);
        }
        Laz[k] = Id;
    }

    void pushTo(int lk, int rk) {
        for (int i = Log; i > 0; --i) {
            if (((lk >> i) << i) != lk) push(lk >> i);
            if (((rk >> i) << i) != rk) push(rk >> i);
        }
    }

    void updateFrom(int l, int r) {
        for (int i = 1; i <= Log; ++i) {
            if (((l >> i) << i) != l) {
                int pos = l >> i;
                Dat[pos] = Op(Dat[2 * pos], Dat[2 * pos + 1]);
            }
            if (((r >> i) << i) != r) {
                int pos = (r - 1) >> i;
                Dat[pos] = Op(Dat[2 * pos], Dat[2 * pos + 1]);
            }
        }
    }

public:
    LazySegTree(int n, function<S(S, S)> op, S e,
                function<S(F, S)> mapping,
                function<F(F, F)> composition,
                F id) : Op(op), E(e), Mapping(mapping), Composition(composition), Id(id) {
        MAX = n;
        N = 1;
        while (N < MAX) N <<= 1;
        Log = 31 - __builtin_clz(N);
        Dat.resize(2 * N, E);
        Laz.resize(N, Id);
    }

    LazySegTree(const vector<S>& dat, function<S(S, S)> op, S e,
                function<S(F, S)> mapping,
                function<F(F, F)> composition,
                F id)
        : LazySegTree(dat.size(), op, e, mapping, composition, id) {
        int l = dat.size();
        for (int i = 0; i < l; ++i) {
            Dat[N + i] = dat[i];
        }
        for (int i = N - 1; i >= 1; --i) {
            Dat[i] = Op(Dat[2 * i], Dat[2 * i + 1]);
        }
    }

    S allProd() const {
        return Dat[1];
    }

    void apply(int l, int r, const F& f) {
        if (l > r) return;
        l += N; r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2; ) {
            if (l2 & 1) {
                Dat[l2] = Mapping(f, Dat[l2]);
                if (l2 < N) Laz[l2] = Composition(f, Laz[l2]);
                l2++;
            }
            if (r2 & 1) {
                r2--;
                Dat[r2] = Mapping(f, Dat[r2]);
                if (r2 < N) Laz[r2] = Composition(f, Laz[r2]);
            }
            l2 >>= 1;
            r2 >>= 1;
        }
        updateFrom(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; ++j) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = {tenmod[N - i - 1], i, i};
    }

    auto op = S::op;
    auto mapping = S::map;
    auto composition = F::composite;
    F identity = F::I;

    LazySegTree<S, F> segTree(dat, op, S::E, mapping, composition, identity);

    for (int j = 0; j < Q; ++j) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--;
        r--;
        F f(D, N);
        segTree.apply(l, r + 1, f);
        cout << segTree.allProd().sum << '\n';
    }
}

// End of Code
