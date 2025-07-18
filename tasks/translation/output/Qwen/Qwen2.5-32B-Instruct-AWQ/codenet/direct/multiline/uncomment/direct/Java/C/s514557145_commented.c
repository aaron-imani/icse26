#include <stdio.h>
#include <stdlib.h>

#define MOD1 1000000007
#define MOD2 998244353

typedef struct {
    long long sum;
    int l;
    int r;
} S;

typedef struct {
    long long D;
    int N;
} F;

S S_E = {0, INT_MAX / 2, INT_MIN / 2};
F F_I = {0, 0};

S S_op(S s1, S s2) {
    long long sum = s1.sum + s2.sum;
    if (sum >= MOD2) {
        sum -= MOD2;
    }
    return (S){sum, (s1.l < s2.l) ? s1.l : s2.l, (s1.r > s2.r) ? s1.r : s2.r};
}

S S_map(F f, S s) {
    long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) {
        c += MOD2;
    }
    return (S){((f.D * c) % MOD2 * modInv(9)) % MOD2, s.l, s.r};
}

F F_composite(F f, F g) {
    return (F){f.D, f.N};
}

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

long long tenmod[100001];

void build(S *dat, int n) {
    for (int i = n - 1; i > 0; i--) {
        dat[i] = S_op(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
}

void push(int k, S *dat, F *laz, int N) {
    if (laz[k] == F_I) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    dat[lk] = S_map(laz[k], dat[lk]);
    dat[rk] = S_map(laz[k], dat[rk]);
    if (lk < N) laz[lk] = F_composite(laz[k], laz[lk]);
    if (rk < N) laz[rk] = F_composite(laz[k], laz[rk]);
    laz[k] = F_I;
}

void pushTo(int k, int Log, S *dat, F *laz, int N) {
    for (int i = Log; i > 0; i--) push(k >> i, dat, laz, N);
}

void pushTo(int lk, int rk, int Log, S *dat, F *laz, int N) {
    for (int i = Log; i > 0; i--) {
        if (((lk >> i) << i) != lk) push(lk >> i, dat, laz, N);
        if (((rk >> i) << i) != rk) push(rk >> i, dat, laz, N);
    }
}

void updateFrom(int k, S *dat, int N) {
    k >>= 1;
    while (k > 0) {
        dat[k] = S_op(dat[k << 1 | 0], dat[k << 1 | 1]);
        k >>= 1;
    }
}

void updateFrom(int lk, int rk, S *dat, int Log, int N) {
    for (int i = 1; i <= Log; i++) {
        if (((lk >> i) << i) != lk) {
            int lki = lk >> i;
            dat[lki] = S_op(dat[lki << 1 | 0], dat[lki << 1 | 1]);
        }
        if (((rk >> i) << i) != rk) {
            int rki = (rk - 1) >> i;
            dat[rki] = S_op(dat[rki << 1 | 0], dat[rki << 1 | 1]);
        }
    }
}

void set(int p, S x, S *dat, F *laz, int N, int Log) {
    p += N;
    pushTo(p, Log, dat, laz, N);
    dat[p] = x;
    updateFrom(p, dat, N);
}

S get(int p, S *dat, F *laz, int N, int Log) {
    p += N;
    pushTo(p, Log, dat, laz, N);
    return dat[p];
}

S allProd(S *dat) {
    return dat[1];
}

void apply(int p, F f, S *dat, F *laz, int N, int Log) {
    p += N;
    pushTo(p, Log, dat, laz, N);
    dat[p] = S_map(f, dat[p]);
    updateFrom(p, dat, N);
}

void apply(int l, int r, F f, S *dat, F *laz, int N, int Log) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(EXIT_FAILURE);
    }
    l += N; r += N;
    pushTo(l, r, Log, dat, laz, N);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            dat[l2] = S_map(f, dat[l2]);
            if (l2 < N) laz[l2] = F_composite(f, laz[l2]);
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            dat[r2] = S_map(f, dat[r2]);
            if (r2 < N) laz[r2] = F_composite(f, laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    updateFrom(l, r, dat, Log, N);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    S *dat = malloc(sizeof(S) * (N + 1));
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    build(dat, N + 1);

    F *laz = malloc(sizeof(F) * (N + 1));
    memset(laz, 0, sizeof(F) * (N + 1));

    int Log = 32 - __builtin_clz(N);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--; r--;
        F f = {D, N};
        apply(l, r + 1, f, dat, laz, N + 1, Log);
        printf("%lld\n", allProd(dat).sum);
    }

    free(dat);
    free(laz);
    return 0;
}
// End of Code
