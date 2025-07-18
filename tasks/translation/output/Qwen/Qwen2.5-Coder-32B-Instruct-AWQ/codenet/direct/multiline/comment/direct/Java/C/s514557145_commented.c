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

long long modInv(long long x, long long mod) {
    long long y = mod - 2;
    long long z = 1;
    while (y > 0) {
        if (y % 2 == 0) {
            x = (x * x) % mod;
            y /= 2;
        } else {
            z = (z * x) % mod;
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
    return (S){sum, s1.l < s2.l ? s1.l : s2.l, s1.r > s2.r ? s1.r : s2.r};
}

S S_map(F f, S s, long long *tenmod) {
    long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) {
        c += MOD2;
    }
    long long inv9 = modInv(9, MOD2);
    return (S)(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r);
}

F F_composite(F f, F g) {
    return (F){f.D, f.N};
}

typedef struct {
    int MAX;
    int N;
    int Log;
    S (*Op)(S, S);
    S E;
    S (*Mapping)(F, S, long long *);
    F (*Composition)(F, F);
    F I;
    S *Dat;
    F *Laz;
    long long *tenmod;
} LazySegTree;

void LazySegTree_build(LazySegTree *tree, S *dat) {
    int l = tree->MAX;
    for (int i = 0; i < l; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = tree->Op(tree->Dat[i << 1 | 0], tree->Dat[i << 1 | 1]);
    }
}

void LazySegTree_push(LazySegTree *tree, int k) {
    if (tree->Laz[k].D == tree->I.D && tree->Laz[k].N == tree->I.N) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    tree->Dat[lk] = tree->Mapping(tree->Laz[k], tree->Dat[lk], tree->tenmod);
    tree->Dat[rk] = tree->Mapping(tree->Laz[k], tree->Dat[rk], tree->tenmod);
    if (lk < tree->N) tree->Laz[lk] = tree->Composition(tree->Laz[k], tree->Laz[lk]);
    if (rk < tree->N) tree->Laz[rk] = tree->Composition(tree->Laz[k], tree->Laz[rk]);
    tree->Laz[k] = tree->I;
}

void LazySegTree_pushTo(LazySegTree *tree, int k) {
    for (int i = tree->Log; i > 0; i--) LazySegTree_push(tree, k >> i);
}

void LazySegTree_pushToRange(LazySegTree *tree, int lk, int rk) {
    for (int i = tree->Log; i > 0; i--) {
        if (((lk >> i) << i) != lk) LazySegTree_push(tree, lk >> i);
        if (((rk >> i) << i) != rk) LazySegTree_push(tree, rk >> i);
    }
}

void LazySegTree_updateFrom(LazySegTree *tree, int k) {
    k >>= 1;
    while (k > 0) {
        tree->Dat[k] = tree->Op(tree->Dat[k << 1 | 0], tree->Dat[k << 1 | 1]);
        k >>= 1;
    }
}

void LazySegTree_updateFromRange(LazySegTree *tree, int lk, int rk) {
    for (int i = 1; i <= tree->Log; i++) {
        if (((lk >> i) << i) != lk) {
            int lki = lk >> i;
            tree->Dat[lki] = tree->Op(tree->Dat[lki << 1 | 0], tree->Dat[lki << 1 | 1]);
        }
        if (((rk >> i) << i) != rk) {
            int rki = (rk - 1) >> i;
            tree->Dat[rki] = tree->Op(tree->Dat[rki << 1 | 0], tree->Dat[rki << 1 | 1]);
        }
    }
}

void LazySegTree_set(LazySegTree *tree, int p, S x) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    LazySegTree_pushTo(tree, p);
    tree->Dat[p] = x;
    LazySegTree_updateFrom(tree, p);
}

S LazySegTree_get(LazySegTree *tree, int p) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    LazySegTree_pushTo(tree, p);
    return tree->Dat[p];
}

S LazySegTree_allProd(LazySegTree *tree) {
    return tree->Dat[1];
}

void LazySegTree_apply(LazySegTree *tree, int p, F f) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    LazySegTree_pushTo(tree, p);
    tree->Dat[p] = tree->Mapping(f, tree->Dat[p], tree->tenmod);
    LazySegTree_updateFrom(tree, p);
}

void LazySegTree_applyRange(LazySegTree *tree, int l, int r, F f) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(EXIT_FAILURE);
    }
    if (l < 0 || l > tree->MAX || r < 0 || r > tree->MAX) {
        fprintf(stderr, "Index is not in [%d, %d].\n", 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    if (l == r) return;
    l += tree->N; r += tree->N;
    LazySegTree_pushToRange(tree, l, r);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            tree->Dat[l2] = tree->Mapping(f, tree->Dat[l2], tree->tenmod);
            if (l2 < tree->N) tree->Laz[l2] = tree->Composition(f, tree->Laz[l2]);
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            tree->Dat[r2] = tree->Mapping(f, tree->Dat[r2], tree->tenmod);
            if (r2 < tree->N) tree->Laz[r2] = tree->Composition(f, tree->Laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    LazySegTree_updateFromRange(tree, l, r);
}

int LazySegTree_maxRight(LazySegTree *tree, int l, int (*g)(S)) {
    if (l < 0 || l > tree->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d].\n", l, 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    if (!g(tree->E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(EXIT_FAILURE);
    }
    if (l == tree->MAX) return tree->MAX;
    l += tree->N;
    LazySegTree_pushTo(tree, l);
    S sum = tree->E;
    do {
        l >>= __builtin_ctzl(l);
        if (!g(tree->Op(sum, tree->Dat[l]))) {
            while (l < tree->N) {
                LazySegTree_push(tree, l);
                l = l << 1;
                if (g(tree->Op(sum, tree->Dat[l]))) {
                    sum = tree->Op(sum, tree->Dat[l]);
                    l++;
                }
            }
            return l - tree->N;
        }
        sum = tree->Op(sum, tree->Dat[l]);
        l++;
    } while ((l & -l) != l);
    return tree->MAX;
}

int LazySegTree_minLeft(LazySegTree *tree, int r, int (*g)(S)) {
    if (r < 0 || r > tree->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d].\n", r, 0, tree->MAX);
        exit(EXIT_FAILURE);
    }
    if (!g(tree->E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(EXIT_FAILURE);
    }
    if (r == 0) return 0;
    r += tree->N;
    LazySegTree_pushTo(tree, r - 1);
    S sum = tree->E;
    do {
        r--;
        while (r > 1 && (r & 1) == 1) r >>= 1;
        if (!g(tree->Op(tree->Dat[r], sum))) {
            while (r < tree->N) {
                LazySegTree_push(tree, r);
                r = r << 1 | 1;
                if (g(tree->Op(tree->Dat[r], sum))) {
                    sum = tree->Op(tree->Dat[r], sum);
                    r--;
                }
            }
            return r + 1 - tree->N;
        }
        sum = tree->Op(tree->Dat[r], sum);
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
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    LazySegTree tree = {
        .MAX = N,
        .N = 1,
        .Log = 0,
        .Op = S_op,
        .E = S_E,
        .Mapping = S_map,
        .Composition = F_composite,
        .I = F_I,
        .Dat = (S *)calloc(N * 2, sizeof(S)),
        .Laz = (F *)calloc(N, sizeof(F)),
        .tenmod = tenmod
    };
    while (tree.N < N) {
        tree.N <<= 1;
        tree.Log++;
    }
    LazySegTree_build(&tree, dat);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        LazySegTree_applyRange(&tree, l - 1, r, (F){D, N});
        printf("%lld\n", tree.Dat[1].sum);
    }
    free(tenmod);
    free(dat);
    free(tree.Dat);
    free(tree.Laz);
    return 0;
}
// End of Code
