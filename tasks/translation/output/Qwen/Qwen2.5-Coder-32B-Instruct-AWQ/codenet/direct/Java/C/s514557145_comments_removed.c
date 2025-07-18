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

long long tenmod[100001];
long long inv9;

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

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

S S_op(S s1, S s2) {
    long long sum = s1.sum + s2.sum;
    if (sum >= MOD2) {
        sum -= MOD2;
    }
    return (S){sum, s1.l < s2.l ? s1.l : s2.l, s1.r > s2.r ? s1.r : s2.r};
}

S S_map(F f, S s) {
    long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) {
        c += MOD2;
    }
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
    S (*Mapping)(F, S);
    F (*Composition)(F, F);
    F Id;
    S *Dat;
    F *Laz;
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
    if (tree->Laz[k].D == tree->Id.D && tree->Laz[k].N == tree->Id.N) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    tree->Dat[lk] = tree->Mapping(tree->Laz[k], tree->Dat[lk]);
    tree->Dat[rk] = tree->Mapping(tree->Laz[k], tree->Dat[rk]);
    if (lk < tree->N) tree->Laz[lk] = tree->Composition(tree->Laz[k], tree->Laz[lk]);
    if (rk < tree->N) tree->Laz[rk] = tree->Composition(tree->Laz[k], tree->Laz[rk]);
    tree->Laz[k] = tree->Id;
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
    tree->Dat[p] = tree->Mapping(f, tree->Dat[p]);
    LazySegTree_updateFrom(tree, p);
}

void LazySegTree_applyRange(LazySegTree *tree, int l, int r, F f) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(EXIT_FAILURE);
    }
    if (l < 0 || l > tree->MAX || r < 0 || r > tree->MAX) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    if (l == r) return;
    l += tree->N; r += tree->N;
    LazySegTree_pushToRange(tree, l, r);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            tree->Dat[l2] = tree->Mapping(f, tree->Dat[l2]);
            if (l2 < tree->N) tree->Laz[l2] = tree->Composition(f, tree->Laz[l2]);
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            tree->Dat[r2] = tree->Mapping(f, tree->Dat[r2]);
            if (r2 < tree->N) tree->Laz[r2] = tree->Composition(f, tree->Laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    LazySegTree_updateFromRange(tree, l, r);
}

LazySegTree LazySegTree_init(int n, S (*op)(S, S), S e, S (*mapping)(F, S), F (*composition)(F, F), F id) {
    int k = 1;
    while (k < n) k <<= 1;
    LazySegTree tree = {
        .MAX = n,
        .N = k,
        .Log = 32 - __builtin_clz(k),
        .Op = op,
        .E = e,
        .Mapping = mapping,
        .Composition = composition,
        .Id = id,
        .Dat = (S *)calloc(k << 1, sizeof(S)),
        .Laz = (F *)calloc(k, sizeof(F))
    };
    for (int i = 0; i < k; i++) {
        tree.Dat[i] = e;
        tree.Laz[i] = id;
    }
    return tree;
}

int main() {
    inv9 = modInv(9);
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int j = 0; j <= N; j++) {
        if (j == 0) {
            tenmod[j] = 1;
        } else {
            tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
        }
    }
    S dat[N];
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    LazySegTree lazySegTree = LazySegTree_init(N, S_op, S_E, S_map, F_composite, F_I);
    LazySegTree_build(&lazySegTree, dat);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        LazySegTree_applyRange(&lazySegTree, l - 1, r, (F){D, N});
        printf("%lld\n", lazySegTree.allProd().sum);
    }
    free(lazySegTree.Dat);
    free(lazySegTree.Laz);
    return 0;
}
// End of Code
