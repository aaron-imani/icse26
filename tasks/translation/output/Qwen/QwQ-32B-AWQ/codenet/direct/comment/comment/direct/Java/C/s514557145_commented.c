/* 
 * This is a C translation of the given Java code implementing a lazy segment tree for handling range updates and queries with specific mathematical operations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD2 998244353

struct S {
    long long sum;
    int l;
    int r;
};

struct F {
    long long D;
    int N;
};

struct S S_E = {0, INT_MAX/2, INT_MIN/2};
struct F F_I = {0, 0};

struct S S_op(struct S s1, struct S s2) {
    long long sum = s1.sum + s2.sum;
    if (sum >= MOD2) sum -= MOD2;
    int new_l = (s1.l < s2.l) ? s1.l : s2.l;
    int new_r = (s1.r > s2.r) ? s1.r : s2.r;
    struct S res = {sum, new_l, new_r};
    return res;
}

struct S S_map(struct F f, struct S s) {
    int a = f.N - s.l;
    int b = f.N - s.r - 1;
    long long c = (tenmod[a] - tenmod[b]);
    if (c < 0) c += MOD2;
    c %= MOD2;
    long long res = (f.D * c) % MOD2;
    res = (res * inv9) % MOD2;
    struct S new_s = {res, s.l, s.r};
    return new_s;
}

struct F F_composite(struct F f, struct F g) {
    return (struct F) {f.D, f.N};
}

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, int y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD2;
        }
        x = (x * x) % MOD2;
        y /= 2;
    }
    return res;
}

typedef struct {
    int MAX;
    int N;
    int Log;
    struct S (*Op)(struct S, struct S);
    struct S E;
    struct S (*Mapping)(struct F, struct S);
    struct F (*Composition)(struct F, struct F);
    struct F Id;
    struct S *Dat;
    struct F *Laz;
} LazySegTree;

void LazySegTree_init(LazySegTree *tree, int max, struct S (*op)(struct S, struct S), struct S e, struct S (*mapping)(struct F, struct S), struct F (*composition)(struct F, struct F), struct F id) {
    int n = 1;
    while (n < max) n <<= 1;
    tree->MAX = max;
    tree->N = n;
    int Log = 0;
    while ((1 << Log) < n) Log++;
    tree->Log = Log;
    tree->Op = op;
    tree->E = e;
    tree->Mapping = mapping;
    tree->Composition = composition;
    tree->Id = id;
    tree->Dat = (struct S*)malloc((tree->N * 2) * sizeof(struct S));
    tree->Laz = (struct F*)malloc((tree->N) * sizeof(struct F));
    for (int i = 0; i < tree->N * 2; i++) {
        tree->Dat[i] = e;
    }
    for (int i = 0; i < tree->N; i++) {
        tree->Laz[i] = id;
    }
}

void LazySegTree_init_with_data(LazySegTree *tree, struct S *dat, int size, struct S (*op)(struct S, struct S), struct S e, struct S (*mapping)(struct F, struct S), struct F (*composition)(struct F, struct F), struct F id) {
    LazySegTree_init(tree, size, op, e, mapping, composition, id);
    for (int i = 0; i < size; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = tree->Op(tree->Dat[2*i], tree->Dat[2*i + 1]);
    }
}

void LazySegTree_push(LazySegTree *tree, int k) {
    if (tree->Laz[k].D == F_I.D && tree->Laz[k].N == F_I.N) return;
    int l = 2 * k;
    int r = 2 * k + 1;
    tree->Dat[l] = tree->Mapping(tree->Laz[k], tree->Dat[l]);
    tree->Dat[r] = tree->Mapping(tree->Laz[k], tree->Dat[r]);
    if (l < tree->N) {
        tree->Laz[l] = tree->Composition(tree->Laz[k], tree->Laz[l]);
    }
    if (r < tree->N) {
        tree->Laz[r] = tree->Composition(tree->Laz[k], tree->Laz[r]);
    }
    tree->Laz[k] = F_I;
}

void LazySegTree_apply(LazySegTree *tree, int l, int r, struct F f) {
    if (l >= r) return;
    if (l < 0) l = 0;
    if (r > tree->MAX) r = tree->MAX;
    l += tree->N;
    r += tree->N;
    for (int i = tree->Log; i > 0; i--) {
        int k = l >> i;
        LazySegTree_push(tree, k);
        k = (r - 1) >> i;
        LazySegTree_push(tree, k);
    }
    int l_orig = l, r_orig = r;
    while (l < r) {
        if (l % 2 == 1) {
            tree->Dat[l] = tree->Mapping(f, tree->Dat[l]);
            if (l < tree->N) {
                tree->Laz[l] = tree->Composition(f, tree->Laz[l]);
            }
            l++;
        }
        if (r % 2 == 1) {
            r--;
            tree->Dat[r] = tree->Mapping(f, tree->Dat[r]);
            if (r < tree->N) {
                tree->Laz[r] = tree->Composition(f, tree->Laz[r]);
            }
        }
        l >>= 1;
        r >>= 1;
    }
    for (int i = 1; i <= tree->Log; i++) {
        int l_part = l_orig >> i;
        if (((l_part << i) != l_orig)) {
            int k = l_part;
            tree->Dat[k] = tree->Op(tree->Dat[2*k], tree->Dat[2*k + 1]);
        }
        int r_part = (r_orig - 1) >> i;
        if (((r_part << i) != (r_orig - 1))) {
            int k = r_part;
            tree->Dat[k] = tree->Op(tree->Dat[2*k], tree->Dat[2*k + 1]);
        }
    }
}

struct S LazySegTree_allProd(LazySegTree *tree) {
    return tree->Dat[1];
}

int main() {
    long long *tenmod;
    int N, Q;
    scanf("%d %d", &N, &Q);
    tenmod = (long long*)malloc((N + 1) * sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    long long inv9 = modInv(9);

    struct S *dat = (struct S*)malloc(N * sizeof(struct S));
    for (int i = 0; i < N; i++) {
        dat[i].sum = tenmod[N - i - 1];
        dat[i].l = i;
        dat[i].r = i;
    }

    LazySegTree seg;
    LazySegTree_init_with_data(&seg, dat, N, S_op, S_E, S_map, F_composite, F_I);

    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        struct F f = {D, N};
        LazySegTree_apply(&seg, l, r + 1, f);
        struct S res = LazySegTree_allProd(&seg);
        printf("%lld\n", res.sum);
    }

    free(tenmod);
    free(dat);
    free(seg.Dat);
    free(seg.Laz);

    return 0;
}

// End of Code
