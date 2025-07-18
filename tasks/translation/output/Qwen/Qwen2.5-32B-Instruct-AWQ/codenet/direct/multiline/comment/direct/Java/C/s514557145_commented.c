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

void initTenmod(int N) {
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10LL) % MOD2;
    }
}

typedef struct {
    S *dat;
    F *laz;
    int N;
    int Log;
    S (*Op)(S, S);
    S E;
    S (*Mapping)(F, S);
    F (*Composition)(F, F);
    F Id;
} LazySegTree;

LazySegTree *createLazySegTree(int n, S (*op)(S, S), S e, S (*mapping)(F, S), F (*composition)(F, F), F id) {
    LazySegTree *tree = (LazySegTree *)malloc(sizeof(LazySegTree));
    tree->N = 1;
    while (tree->N < n) tree->N <<= 1;
    tree->Log = 32 - __builtin_clz(tree->N);
    tree->Op = op;
    tree->E = e;
    tree->Mapping = mapping;
    tree->Composition = composition;
    tree->Id = id;
    tree->dat = (S *)calloc(tree->N * 2, sizeof(S));
    tree->laz = (F *)calloc(tree->N, sizeof(F));
    return tree;
}

void buildLazySegTree(LazySegTree *tree, S *dat, int n) {
    for (int i = 0; i < n; i++) {
        tree->dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->dat[i] = tree->Op(tree->dat[i << 1 | 0], tree->dat[i << 1 | 1]);
    }
}

void push(LazySegTree *tree, int k) {
    if (tree->laz[k] == tree->Id) return;
    int lk = k << 1 | 0, rk = k << 1 | 1;
    tree->dat[lk] = tree->Mapping(tree->laz[k], tree->dat[lk]);
    tree->dat[rk] = tree->Mapping(tree->laz[k], tree->dat[rk]);
    if (lk < tree->N) tree->laz[lk] = tree->Composition(tree->laz[k], tree->laz[lk]);
    if (rk < tree->N) tree->laz[rk] = tree->Composition(tree->laz[k], tree->laz[rk]);
    tree->laz[k] = tree->Id;
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
        tree->dat[k] = tree->Op(tree->dat[k << 1 | 0], tree->dat[k << 1 | 1]);
        k >>= 1;
    }
}

void updateFromRange(LazySegTree *tree, int lk, int rk) {
    for (int i = 1; i <= tree->Log; i++) {
        if (((lk >> i) << i) != lk) {
            int lki = lk >> i;
            tree->dat[lki] = tree->Op(tree->dat[lki << 1 | 0], tree->dat[lki << 1 | 1]);
        }
        if (((rk >> i) << i) != rk) {
            int rki = (rk - 1) >> i;
            tree->dat[rki] = tree->Op(tree->dat[rki << 1 | 0], tree->dat[rki << 1 | 1]);
        }
    }
}

void set(LazySegTree *tree, int p, S x) {
    p += tree->N;
    pushTo(tree, p);
    tree->dat[p] = x;
    updateFrom(tree, p);
}

S get(LazySegTree *tree, int p) {
    p += tree->N;
    pushTo(tree, p);
    return tree->dat[p];
}

S allProd(LazySegTree *tree) {
    return tree->dat[1];
}

void apply(LazySegTree *tree, int p, F f) {
    p += tree->N;
    pushTo(tree, p);
    tree->dat[p] = tree->Mapping(f, tree->dat[p]);
    updateFrom(tree, p);
}

void applyRange(LazySegTree *tree, int l, int r, F f) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(EXIT_FAILURE);
    }
    l += tree->N; r += tree->N;
    pushToRange(tree, l, r);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            tree->dat[l2] = tree->Mapping(f, tree->dat[l2]);
            if (l2 < tree->N) tree->laz[l2] = tree->Composition(f, tree->laz[l2]);
            l2++;
        }
        if ((r2 & 1) == _Bool) {
            r2--;
            tree->dat[r2] = tree->Mapping(f, tree->dat[r2]);
            if (r2 < tree->N) tree->laz[r2] = tree->Composition(f, tree->laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    updateFromRange(tree, l, r);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    initTenmod(N);
    S *dat = (S *)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    LazySegTree *lazySegTree = createLazySegTree(N, S_op, S_E, S_map, F_composite, F_I);
    buildLazySegTree(lazySegTree, dat, N);

    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--; r--;
        F f = {D, N};
        applyRange(lazySegTree, l, r + 1, f);
        printf("%lld\n", allProd(lazySegTree).sum);
    }

    free(dat);
    free(lazySegTree->dat);
    free(lazySegTree->laz);
    free(lazySegTree);
    return 0;
}
// End of Code
