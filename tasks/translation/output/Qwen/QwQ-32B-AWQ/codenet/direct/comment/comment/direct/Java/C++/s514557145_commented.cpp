Here's the translated C++ code:


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long MOD2 = 998244353;
vector<long long> tenmod;

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long res = 1;
    x %= MOD2;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % MOD2;
        x = (x * x) % MOD2;
        y /= 境
    }
    return res;
}

struct S {
    static S E;
    long long sum;
    int l, r;
    S() {}
    S(long long s, int a, int b) : sum(s), l(a), r(b) {}
    static S op(const S &a, const S &b) {
        long long s = a.sum + b.sum;
        if (s >= MOD2) s -= MOD2;
        return S(s, min(a.l, b.l), max(a.r, b.r));
    }
    static S map(const F &f, const S &s) {
        long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
        if (c < 0) c += MOD2;
        long long res = (f.D * c) % MOD2;
        res = (res * modInv(9)) % MOD2;
        return S(res, s.l, s.r);
    }
};

S S::E = S(0, numeric_limits<int>::max() / 2, numeric_limits<int>::min() / 2);

struct F {
    static F I;
    long long D;
    int N;
    F(long long d, int n) : D(d), N(n) {}
    static F composite(const F &f, const F &g) {
        return F(f.D, f.N);
    }
};

F F::I = F(0, 0);

template<typename S, typename F>
class LazySegTree {
private:
    int n;
    int N;
    int Log;
    vector<S> dat;
    vector<F> laz;

public:
    LazySegTree(const vector<S> &initial_dat) {
        n = initial_dat.size();
        N = 1;
        while (N < n) N <<= 1;
        Log = 31 - __builtin_clz(N);
        dat.resize(2 * N, S::E);
        laz.resize(N, F::I);
        for (int i = 0; i < n; ++i) {
            dat[N + i] = initial_dat[i];
        }
        for (int i = N - 1; i >= 1; --i) {
            dat[i] = S::op(dat[2 * i], dat[2 * i + 1]);
        }
    }

    void apply(int l, int r, const F &f) {
        if (l >= r) return;
        l += N;
        r += N;
        for (int i = Log; i > 0; --i) {
            push(l >> i);
            push((r - 1) >> i);
        }
        int l_orig = l, r_orig = r;
        while (l < r) {
            if (l % 2 == 1) {
                applySingle(l, f);
                l++;
            }
            if (r % 2 == 1) {
                r--;
                applySingle(r, f);
            }
            l >>= 1;
            r >>= 1;
        }
        update(l_orig - N, r_orig - N);
    }

    S allProd() const {
        return dat[1];
    }

private:
    void applySingle(int k, const F &f) {
        dat[k] = S::map(f, dat[k]);
        if (k < N) {
            laz[k] = F::composite(f, laz[k]);
        }
    }

    void update(int a, int b) {
        a += N;
        b += N;
        while (a >>= 1) {
            dat[a] = S::op(dat[2 * a], dat[2 * a + 1]);
        }
        while (b >>= 1) {
            dat[b] = S::op(dat[2 * b], dat[2 * b + 1]);
        }
    }

    void push(int k) {
        if (laz[k] == F::I) return;
        applySingle(2 * k, laz[k]);
        applySingle(2 * k + 1, laz[k]);
        laz[k] = F::I;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    tenmod.resize(N + 1);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    long long inv9 = modInv(9);

    vector<S> dat(N);
    for (int i = 0; i < N; ++i) {
        dat[i] = S(tenmod[N - i - 1], i, i);
    }

    LazySegTree<S, F> st(dat);

    for (int q = 0; q < Q; ++q) {
        int l, r;
        long long D;
        cin >> l >> r >> D;
        l--;
        r--;
        F f(D, N);
        st.apply(l, r + 1, f);
        cout << st.allProd().sum << '\n';
    }

    return 0;
}
// End of Code
