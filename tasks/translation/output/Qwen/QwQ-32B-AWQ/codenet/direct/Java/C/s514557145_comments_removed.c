#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD2 998244353
#define MAX_N 100000

long long tenmod[MAX_N + 1];
long long inv9;

typedef struct {
    long long sum;
    int l;
    int r;
} S;

const S S_E = {0, INT_MAX / 2, INT_MIN / 2};

typedef struct {
    long long D;
    int N;
} F;

const F F_I = {0, 0};

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD2;
            if (res < 0) res += MOD2;
        }
        x = (x * x) % MOD2;
        if (x < 0) x += MOD2;
        y /= 2;
    }
    return res;
}

S S_op(S s1, S s2) {
    long long sum = (s1.sum + s2.sum) % MOD2;
    if (sum < 0) sum += MOD2;
    int new_l = (s1.l < s2.l) ? s1.l : s2.l;
    int new_r = (s1.r > s2.r) ? s1.r : s2.r;
    return (S) {sum, new_l, new_r};
}

S S_map(F f, S s) {
    int n_minus_l = f.N - s.l;
    int n_minus_r = f.N - s.r - 1;
    long long c = (tenmod[n_minus_l] - tenmod[n_minus_r]);
    if (c < 0) c += MOD2;
    long long new_sum = (f.D * c) % MOD2;
    new_sum = (new_sum * inv9) % MOD2;
    return (S) {new_sum, s.l, s.r};
}

F F_composite(F f, F g) {
    return (F) {f.D, f.N};
}

typedef struct {
    int MAX;
    int N;
    int Log;
    S (*Op)(S, S);
    S E;
    S (*Mapping)(F, S);
    F (*Composition)(F, F);
    F Id;
    S *Dat;
    F *Laz;
} LazySegTree;

void push(LazySegTree *tree, int k) {
    F f = tree->Laz[k];
    if (f.D == F_I.D && f.N == F_I.N) return;
    int lk = (k << 1);
    int rk = (k << 1) + 1;
    tree->Dat[lk] = (*tree->Mapping)(f, tree->Dat[lk]);
    tree->Dat[rk] = (*tree->Mapping)(f, tree->Dat[rk]);
    if (lk < tree->N) {
        tree->Laz[lk] = (*tree->Composition)(f, tree->Laz[lk]);
    }
    if (rk < tree->N) {
        tree->Laz[rk] = (*tree->Composition)(f, tree->Laz[rk]);
    }
    tree->Laz[k] = F_I;
}

void pushTo(LazySegTree *tree, int lk, int rk) {
    int log_n = tree->Log;
    for (int i = log_n; i > 0; i--) {
        int k_l = lk >> i;
        if (((k_l << i) != lk)) {
            push(tree, k_l);
        }
        int k_r = rk >> i;
        if (((k_r << i) != rk)) {
            push(tree, k_r);
        }
    }
}

void updateFrom(LazySegTree *tree, int lk, int rk) {
    int log_n = tree->Log;
    for (int i = 1; i <= log_n; i++) {
        int lki = lk >> i;
        if (((lki << i) != lk)) {
            tree->Dat[lki] = (*tree->Op)(tree->Dat[lki * 2], tree->Dat[lki * 2 + 1]);
        }
        int rki = (rk - 1) >> i;
        if (((rki << i) != (rk - 1))) {
            tree->Dat[rki] = (*tree->Op)(tree->Dat[rki * 2], tree->Dat[rki * 2 + 1]);
        }
    }
}

LazySegTree *LazySegTree_init(S *dat, int dat_len, S (*op)(S, S), S E, S (*mapping)(F, S), F (*composition)(F, F), F Id) {
    LazySegTree *tree = (LazySegTree*)malloc(sizeof(LazySegTree));
    int n = 1;
    while (n < dat_len) n <<= 1;
    tree->MAX = dat_len;
    tree->N = n;
    tree->Log = (int)log2(n);
    tree->Op = op;
    tree->E = E;
    tree->Mapping = mapping;
    tree->Composition = composition;
    tree->Id = Id;
    tree->Dat = (S*)malloc((tree->N << 1) * sizeof(S));
    tree->Laz = (F*)malloc(tree->N * sizeof(F));
    for (int i = 0; i < (tree->N << 1); i++) {
        tree->Dat[i] = E;
    }
    for (int i = 0; i < tree->N; i++) {
        tree->Laz[i] = Id;
    }
    for (int i = 0; i < dat_len; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = (*op)(tree->Dat[i * 2], tree->Dat[i * 2 + 1]);
    }
    return tree;
}

void LazySegTree_apply(LazySegTree *tree, int l, int r, F f) {
    if (l >= r) return;
    int N = tree->N;
    l += N;
    r += N;
    pushTo(tree, l, r);
    for (int l2 = l, r2 = r; l2 < r2; ) {
        if ((l2 & 1) == 1) {
            tree->Dat[l2] = (*tree->Mapping)(f, tree->Dat[l2]);
            if (l2 < N) {
                tree->Laz[l2] = (*tree->Composition)(f, tree->Laz[l2]);
            }
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            tree->Dat[r2] = (*tree->Mapping)(f, tree->Dat[r2]);
            if (r2 < N) {
                tree->Laz[r2] = (*tree->Composition)(f, tree->Laz[r2]);
            }
        }
        l2 >>= 1;
        r2 >>= 1;
    }
    updateFrom(tree, l, r);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    inv9 = modInv(9);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
    S *dat = (S*)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i].sum = tenmod[N - i - 1];
        dat[i].l = i;
        dat[i].r = i;
    }
    LazySegTree *tree = LazySegTree_init(dat, N, S_op, S_E, S_map, F_composite, F_I);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        F f = {D, N};
        LazySegTree_apply(tree, l, r + 1, f);
        printf("%lld\n", tree->Dat[1].sum);
    }
    free(dat);
    free(tree->Dat);
    free(tree->Laz);
    free(tree);
    return 0;
}
// End of Code
