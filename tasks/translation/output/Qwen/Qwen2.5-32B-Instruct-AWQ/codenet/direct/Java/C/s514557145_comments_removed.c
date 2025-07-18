#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void exclusiveRangeCheck(int p, int MAX) {
    if (p < 0 || p >= MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, MAX);
        exit(1);
    }
}

void inclusiveRangeCheck(int p, int MAX) {
    if (p < 0 || p > MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d].\n", p, 0, MAX);
        exit(1);
    }
}

void push(int k, S *Dat, F *Laz, int N, int Log) {
    if (Laz[k] == F_I) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    Dat[lk] = S_map(Laz[k], Dat[lk]);
    Dat[rk] = S_map(Laz[k], Dat[rk]);
    if (lk < N) Laz[lk] = F_composite(Laz[k], Laz[lk]);
    if (rk < N) Laz[rk] = F_composite(Laz[k], Laz[rk]);
    Laz[k] = F_I;
}

void pushTo(int k, int N, int Log, S *Dat, F *Laz) {
    for (int i = Log; i > 0; i--) push(k >> i, Dat, Laz, N, Log);
}

void pushTo(int lk, int rk, int N, int Log, S *Dat, F *Laz) {
    for (int i = Log; i > 0; i--) {
        if (((lk >> i) << i) != lk) push(lk >> i, Dat, Laz, N, Log);
        if (((rk >> i) << i) != rk) push(rk >> i, Dat, Laz, N, Log);
    }
}

void updateFrom(int k, S *Dat, int N) {
    k >>= 1;
    while (k > 0) {
        Dat[k] = S_op(Dat[k << 1 | 0], Dat[k << 1 | 1]);
        k >>= 1;
    }
}

void updateFrom(int lk, int rk, S *Dat, int N) {
    for (int i = 1; i <= Log; i++) {
        if (((lk >> i) << i) != lk) {
            int lki = lk >> i;
            Dat[lki] = S_op(Dat[lki << 1 | 0], Dat[lki << 1 | 1]);
        }
        if (((rk >> i) << i) != rk) {
            int rki = (rk - 1) >> i;
            Dat[rki] = S_op(Dat[rki << 1 | 0], Dat[rki << 1 | 1]);
        }
    }
}

void set(int p, S x, S *Dat, int N) {
    exclusiveRangeCheck(p, N);
    p += N;
    pushTo(p, N, Log, Dat, Laz);
    Dat[p] = x;
    updateFrom(p, Dat, N);
}

S get(int p, S *Dat, int N) {
    exclusiveRangeCheck(p, N);
    p += N;
    pushTo(p, N, Log, Dat, Laz);
    return Dat[p];
}

S allProd(S *Dat) {
    return Dat[1];
}

void apply(int p, F f, S *Dat, F *Laz, int N) {
    exclusiveRangeCheck(p, N);
    p += N;
    pushTo(p, N, Log, Dat, Laz);
    Dat[p] = S_map(f, Dat[p]);
    updateFrom(p, Dat, N);
}

void apply(int l, int r, F f, S *Dat, F *Laz, int N, int Log) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(1);
    }
    inclusiveRangeCheck(l, N);
    inclusiveRangeCheck(r, N);
    if (l == r) return;
    l += N; r += N;
    pushTo(l, r, N, Log, Dat, Laz);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            Dat[l2] = S_map(f, Dat[l2]);
            if (l2 < N) Laz[l2] = F_composite(f, Laz[l2]);
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            Dat[r2] = S_map(f, Dat[r2]);
            if (r2 < N) Laz[r2] = F_composite(f, Laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    updateFrom(l, r, Dat, N);
}

int maxRight(int l, S *Dat, int N, int Log, F *Laz, int (*g)(S)) {
    inclusiveRangeCheck(l, N);
    if (!g(S_E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(1);
    }
    if (l == N) return N;
    l += N;
    pushTo(l, N, Log, Dat, Laz);
    S sum = S_E;
    do {
        l >>= __builtin_ctz(l);
        if (!g(S_op(sum, Dat[l]))) {
            while (l < N) {
                push(l, Dat, Laz, N, Log);
                l = l << 1;
                if (g(S_op(sum, Dat[l]))) {
                    sum = S_op(sum, Dat[l]);
                    l++;
                }
            }
            return l - N;
        }
        sum = S_op(sum, Dat[l]);
        l++;
    } while ((l & -l) != l);
    return N;
}

int minLeft(int r, S *Dat, int N, int Log, F *Laz, int (*g)(S)) {
    inclusiveRangeCheck(r, N);
    if (!g(S_E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(1);
    }
    if (r == 0) return 0;
    r += N;
    pushTo(r - 1, N, Log, Dat, Laz);
    S sum = S_E;
    do {
        r--;
        while (r > 1 && (r & 1) == 1) r >>= 1;
        if (!g(S_op(Dat[r], sum))) {
            while (r < N) {
                push(r, Dat, Laz, N, Log);
                r = r << 1 | 1;
                if (g(S_op(Dat[r], sum))) {
                    sum = S_op(Dat[r], sum);
                    r--;
                }
            }
            return r + 1 - N;
        }
        sum = S_op(Dat[r], sum);
    } while ((r & -r) != r);
    return 0;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    long long *tenmod = (long long *)malloc((N + 1) * sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    S *dat = (S *)malloc(N * sizeof(S));
    for (int j = 0; j < N; j++) {
        dat[j] = (S){tenmod[N - j - 1], j, j};
    }
    S *Dat = (S *)malloc((N << 1) * sizeof(S));
    F *Laz = (F *)malloc(N * sizeof(F));
    for (int i = 0; i < N << 1; i++) {
        Dat[i] = S_E;
    }
    for (int i = 0; i < N; i++) {
        Laz[i] = F_I;
    }
    for (int i = N - 1; i > 0; i--) {
        Dat[i] = S_op(Dat[i << 1 | 0], Dat[i << 1 | 1]);
    }
    int Log = __builtin_ctz(N);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--; r--;
        F f = {D, N};
        apply(l, r + 1, f, Dat, Laz, N, Log);
        printf("%lld\n", allProd(Dat).sum);
    }
    free(tenmod);
    free(dat);
    free(Dat);
    free(Laz);
    return 0;
}
// End of Code
