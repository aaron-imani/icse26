#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;
vector<long long> tenmod;
const long long inv9 = modInverse(9, MOD2);

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

struct S {
    static const S E;
    long long sum;
    int l;
    int r;
    S(long long sum, int l, int r) : sum(sum), l(l), r(r) {}
    static S op(const S& s1, const S& s2) {
        long long sum = s1.sum + s2.sum;
        if (sum >= MOD2) sum -= MOD2;
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r));
    }
    static S map(const struct F& f, const S& s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        return S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
    }
};

const S S::E = S(0, INT_MAX / 2, INT_MIN / 2);

struct F {
    static const F I;
    long long D;
    int N;
    F(long long D, int N) : D(D), N(N) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};

const F F::I = F(0, 0);

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct LazySegTree {
    int MAX;
    int N;
    int Log;
    vector<S> Dat;
    vector<F> Laz;

    LazySegTree(int n) : MAX(n) {
        int k = 1;
        while (k < n) k <<= 1;
        this->N = k;
        this->Log = 32 - __builtin_clz(N);
        Dat.assign(N * 2, e());
        Laz.assign(N, id());
    }

    LazySegTree(const vector<S>& dat) : MAX(dat.size()) {
        int k = 1;
        while (k < MAX) k <<= 1;
        this->N = k;
        this->Log = 32 - __builtin_clz(N);
        Dat.assign(N * 2, e());
        Laz.assign(N, id());
        for (int i = 0; i < MAX; i++) Dat[N + i] = dat[i];
        for (int i = N - 1; i > 0; i--) Dat[i] = op(Dat[i * 2], Dat[i * 2 + 1]);
    }

    void push(int k) {
        if (Laz[k] == id()) return;
        Dat[k * 2] = mapping(Laz[k], Dat[k * 2]);
        Dat[k * 2 + 1] = mapping(Laz[k], Dat[k * 2 + 1]);
        if (k * 2 < N) Laz[k * 2] = composition(Laz[k], Laz[k * 2]);
        if (k * 2 + 1 < N) Laz[k * 2 + 1] = composition(Laz[k], Laz[k * 2 + 1]);
        Laz[k] = id();
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
            Dat[k] = op(Dat[k * 2], Dat[k * 2 + 1]);
            k >>= 1;
        }
    }

    void updateFrom(int lk, int rk) {
        for (int i = 1; i <= Log; i++) {
            if (((lk >> i) << i) != lk) {
                int lki = lk >> i;
                Dat[lki] = op(Dat[lki * 2], Dat[lki * 2 + 1]);
            }
            if (((rk >> i) << i) != rk) {
                int rki = (rk - 1) >> i;
                Dat[rki] = op(Dat[rki * 2], Dat[rki * 2 + 1]);
            }
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
        Dat[p] = mapping(f, Dat[p]);
        updateFrom(p);
    }

    void apply(int l, int r, F f) {
        if (l > r) throw invalid_argument("Invalid range");
        if (l < 0 || r > MAX) throw out_of_range("Index out of range");
        if (l == r) return;
        l += N; r += N;
        pushTo(l, r);
        for (int l2 = l, r2 = r; l2 < r2;) {
            if ((l2 & 1) == 1) {
                Dat[l2] = mapping(f, Dat[l2]);
                if (l2 < N) Laz[l2] = composition(f, Laz[l2]);
                l2++;
            }
            if ((r2 & 1) == 1) {
                r2--;
                Dat[r2] = mapping(f, Dat[r2]);
                if (r2 < N) Laz[r2] = composition(f, Laz[r2]);
            }
            l2 >>= 1; r2 >>= 1;
        }
        updateFrom(l, r);
    }

    int maxRight(int l, function<bool(S)> g) {
        if (l < 0 || l > MAX) throw out_of_range("Index out of range");
        if (!g(e())) throw invalid_argument("Identity element must satisfy the condition");
        if (l == MAX) return MAX;
        l += N;
        pushTo(l);
        S sum = e();
        do {
            l >>= __builtin_ctz(l);
            if (!g(op(sum, Dat[l]))) {
                while (l < N) {
                    push(l);
                    l = l * 2;
                    if (g(op(sum, Dat[l]))) {
                        sum = op(sum, Dat[l]);
                        l++;
                    }
                }
                return l - N;
            }
            sum = op(sum, Dat[l]);
            l++;
        } while ((l & -l) != l);
        return MAX;
    }

    int minLeft(int r, function<bool(S)> g) {
        if (r < 0 || r > MAX) throw out_of_range("Index out of range");
        if (!g(e())) throw invalid_argument("Identity element must satisfy the condition");
        if (r == 0) return 0;
        r += N;
        pushTo(r - 1);
        S sum = e();
        do {
            r--;
            while (r > 1 && (r & 1) == 1) r >>= 1;
            if (!g(op(Dat[r], sum))) {
                while (r < N) {
                    push(r);
                    r = r * 2 + 1;
                    if (g(op(Dat[r], sum))) {
                        sum = op(Dat[r], sum);
                        r--;
                    }
                }
                return r + 1 - N;
            }
            sum = op(Dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    vector<S> dat(N);
    for (int i = 0; i < N; i++) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }
    LazySegTree<S, S::op, S::E, F, S::map, F::composite, F::I> lazySegTree(dat);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--; r--;
        lazySegTree.apply(l, r + 1, F(D, N));
        cout << lazySegTree.allProd().sum << "\n";
    }
    return 0;
}
// End of Code
