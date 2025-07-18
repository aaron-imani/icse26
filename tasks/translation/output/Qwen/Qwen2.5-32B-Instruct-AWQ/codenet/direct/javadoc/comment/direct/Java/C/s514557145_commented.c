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

void build(LazySegTree *tree, S *dat, int n) {
    int l = n;
    for (int i = 0; i < l; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = tree->Op(tree->Dat[i << 1 | 0], tree->Dat[i << 1 | 1]);
    }
}

void push(LazySegTree *tree, int k) {
    if (tree->Laz[k] == tree->Id) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    tree->Dat[lk] = tree->Mapping(tree->Laz[k], tree->Dat[lk]);
    tree->Dat[rk] = tree->Mapping(tree->Laz[k], tree->Dat[rk]);
    if (lk < tree->N) tree->Laz[lk] = tree->Composition(tree->Laz[k], tree->Laz[lk]);
    if (rk < tree->N) tree->Laz[rk] = tree->Composition(tree->Laz[k], tree->Laz[rk]);
    tree->Laz[k] = tree->Id;
}

void pushTo(LazySegTree *tree, int k) {
    for (int i = tree->Log; i > 0; i--) push(tree, k >> i);
}

void pushToRange(LazySegTree *tree, int lk, int rk) {
    for (int i = tree->Log; i > 0; i--) {
        if (((lk >> i) << i) != lk) push(tree, lk >> i);
        if (((rk >> i) << i) != rk) push(tree, rk >> i);
    }
}

void updateFrom(LazySegTree *tree, int k) {
    k >>= 1;
    while (k > 0) {
        tree->Dat[k] = tree->Op(tree->Dat[k << 1 | 0], tree->Dat[k << 1 | 1]);
        k >>= 1;
    }
}

void updateFromRange(LazySegTree *tree, int lk, int rk) {
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

void set(LazySegTree *tree, int p, S x) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [0, %d).\n", p, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    pushTo(tree, p);
    tree->Dat[p] = x;
    updateFrom(tree, p);
}

S get(LazySegTree *tree, int p) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [0, %d).\n", p, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    pushTo(tree, p);
    return tree->Dat[p];
}

S allProd(LazySegTree *tree) {
    return tree->Dat[1];
}

void apply(LazySegTree *tree, int p, F f) {
    if (p < 0 || p >= tree->MAX) {
        fprintf(stderr, "Index %d is not in [0, %d).\n", p, tree->MAX);
        exit(EXIT_FAILURE);
    }
    p += tree->N;
    pushTo(tree, p);
    tree->Dat[p] = tree->Mapping(f, tree->Dat[p]);
    updateFrom(tree, p);
}

void applyRange(LazySegTree *tree, int l, int r, F f) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(EXIT_FAILURE);
    }
    if (l < 0 || r > tree->MAX) {
        fprintf(stderr, "Range [%d, %d) is not in [0, %d]\n", l, r, tree->MAX);
        exit(EXIT_FAILURE);
    }
    if (l == r) return;
    l += tree->N; r += tree->N;
    pushToRange(tree, l, r);
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
    updateFromRange(tree, l, r);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    long long *tenmod = malloc((N + 1) * sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }

    S *dat = malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }

    LazySegTree tree = {
        .MAX = N,
        .N = 1 << (int)ceil(log2(N)),
        .Log = (int)log2(tree.N),
        .Op = S_op,
        .E = S_E,
        .Mapping = S_map,
        .Composition = F_composite,
        .Id = F_I,
        .Dat = malloc((tree.N << 1) * sizeof(S)),
        .Laz = malloc(tree.N * sizeof(F))
    };
    build(&tree, dat, N);

    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--; r--;
        applyRange(&tree, l, r + 1, (F){D, N});
        printf("%lld\n", allProd(&tree).sum);
    }

    free(tenmod);
    free(dat);
    free(tree.Dat);
    free(tree.Laz);
    return 0;
}
// End of Code
