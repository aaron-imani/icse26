#include <iostream>
#include <vector>
#include <functional>
using namespace std;

const long long MOD1 = 1e9 +7;
const long long MOD2 = 998244353;
vector<long long> tenmod; // Global vector
long long inv9 = 0; // computed in main

struct S {
    long long sum;
    int l, r;
    static S E;
    S(long long s, int a, int b) : sum(s), l(a), r(b) {}
    static S op(const S& a, const S& b) {
        long long s = (a.sum + b.sum) % MOD2;
        if (s < 0) s += MOD2;
        return S(s, min(a.l, b.l), max(a.r, b.r));
    }
    static S map(const F& f, const S& s) {
        int N_f = f.N;
        long long term1 = tenmod[N_f - s.l];
        long long term2 = tenmod[N_f - s.r -1];
        long long c = (term1 - term2) % MOD2;
        if (c < 0) c += MOD2;
        long long new_sum = (f.D * c % MOD2) * inv9 % MOD2;
        return S(new_sum, s.l, s.r);
    }
};
S S::E = S(0, INT_MAX/2, INT_MIN/2);

struct F {
    long long D;
    int N;
    static F I;
    F(long long d, int n) : D(d), N(n) {}
    static F composite(const F& f, const F& g) {
        return F(f.D, f.N);
    }
};
F F::I = F(0,0);

long long modPow(long long a, long long b, long long mod) {
    long long res = 稍稍;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long modInv(long long a, long long mod) {
    return modPow(a, mod-2, mod);
}

template<typename S, typename F>
class LazySegTree {
private:
    int MAX;
    int N;
    int Log;
    vector<S> Dat;
    vector<F> Laz;
public:
    LazySegTree(const vector<S>& initial) {
        MAX = initial.size();
        N = 1;
        while (N < MAX) N <<=1;
        Log = 31 - __builtin_clz(N);
        Dat.resize(2*N, S::E);
        Laz.resize(N, F::I);
        for (int i=0; i<MAX; i++) {
            Dat[N+i] = initial[i];
        }
        for (int i = N-1; i>=1; i--) {
            Dat[i] = S::op(Dat[2*i], Dat[2*i+1]);
        }
    }

    void apply(int l, int r, const F& f) {
        if (l >= r) return;
        l += N; r += N;
        for (int i = Log; i>0; --i) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }
        int l_orig = l, r_orig = r;
        while (l < r) {
            if (l % 2 == 1) {
                Dat[l] = S::map(f, Dat[l]);
                if (l < N) Laz[l] = F::composite(f, Laz[l]);
                l++;
            }
            if (r % 2 == 1) {
                r--;
                Dat[r] = S::map(f, Dat[r]);
                if (r < N) Laz[r] = F::composite(f, Laz[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        l = l_orig; r = r_orig;
        while (l > 1) {
            l >>= 1;
            r >>= 1;
            Dat[l] = S::op(Dat[2*l], Dat[2*l+1]);
        }
    }

    S allProd() const {
        return Dat[1];
    }

private:
    void push(int k) {
        if (Laz[k] == F::I) return;
        int lk = 2*k, rk = 2*k +1;
        Dat[lk] = S::map(Laz[k], Dat[lk]);
        Dat[rk] = S::map(Laz[k], Dat[rk]);
        if (lk < N) {
            Laz[lk] = F::composite(Laz[k], Laz[lk]);
        }
        if (rk < N) {
            Laz[rk] = F::composite(Laz[k], Laz[rk]);
        }
        Laz[k] = F::I;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    tenmod.resize(N+1);
    tenmod[0] = 1;
    for (int j =1; j<=N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    inv9 = modInv(9, MOD2);

    vector<S> dat(N);
    for (int i=0; i<N; i++) {
        int pow10 = N - i -1;
        long long sum_val = tenmod[pow10];
        dat[i] = S(sum_val, i, i);
    }

    LazySegTree<S, F> segTree(dat);

    for (int q=0; q<Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        long long D;
        cin >> D;
        F f(D, N);
        segTree.apply(l, r+1, f);
        cout << segTree.allProd().sum << '\n';
    }

    return 0;
}
// End of Code
