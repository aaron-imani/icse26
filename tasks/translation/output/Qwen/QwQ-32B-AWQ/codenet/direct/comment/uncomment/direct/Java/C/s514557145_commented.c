#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD2 998244353
#define MOD1 1000000007

struct S {
    long long sum;
    int l;
    int r;
};

struct F {
    long long D;
    int N;
};

struct LazySegTree {
    int N;
    int Log;
    struct S (*Op)(struct S, struct S);
    struct S E;
    struct S (*Mapping)(struct F, struct S);
    struct F (*Composition)(struct F, struct F);
    struct F Id;
    struct S *Dat;
    struct F *Laz;
    int MAX;
};

struct S S_E = {0, INT_MAX/2, INT_MIN/2};
struct F F_I = {0, 0};

struct S S_op(struct S s1, struct S s2) {
    long long sum = s1.sum + s2.sum;
    if (sum >= MOD2) sum -= MOD2;
    return (struct S) {.sum = sum, .l = (s1.l < s2.l) ? s1.l : s2.l, .r = (s1.r > s2.r) ? s1.r : s2.r};
}

struct S S_map(struct F f, struct S s) {
    int idx_l = f.N - s.l;
    int idx_r = f.N - s.r - 1;
    long long c = (global_tenmod[idx_l] - global_tenmod[idx_r]);
    if (c < 0) c += MOD2;
    long long result = (f.D * c) % MOD2;
    result = (result * inv9) % MOD2;
    return (struct S) {.sum = result, .l = s.l, .r = s.r};
}

struct F F_composite(struct F f, struct F g) {
    return (struct F) {.D = f.D, .N = f.N};
}

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
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

void LazySegTree_Init(struct LazySegTree *tree, int n, struct S (*op)(struct S, struct S), struct S E, struct S (*mapping)(struct F, struct S), struct F (*composition)(struct F, struct F), struct F Id) {
    tree->MAX = n;
    int k = 1;
    while (k < n) k <<= 1;
    tree->N = k;
    tree->Log = (int)log2(k);
    tree->Op = op;
    tree->E = E;
    tree->Mapping = mapping;
    tree->Composition = composition;
    tree->Id = Id;
    tree->Dat = (struct S*)malloc( (tree->N * 2) * sizeof(struct S) );
    tree->Laz = (struct F*)malloc( tree->N * sizeof(struct F) );
    for (int i = 0; i < tree->N * 2; i++) {
        tree->Dat[i] = E;
    }
    for (int i = 0; i < tree->N; i++) {
        tree->Laz[i] = Id;
    }
}

void LazySegTree_BuildFromArray(struct LazySegTree *tree, struct S *dat, int dat_len) {
    int l = dat_len;
    for (int i = 0; i < l; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = tree->Op(tree->Dat[2*i], tree->Dat[2*i+1]);
    }
}

void push(struct LazySegTree *tree, int k) {
    struct F *Laz = tree->Laz;
    struct S *Dat = tree->Dat;
    struct F f = Laz[k];
    if (f.D == tree->Id.D && f.N == tree->Id.N) return;
    int lk = (k << 1) | 0;
    int rk = (k << 1) | 1;
    Dat[lk] = tree->Mapping(f, Dat[lk]);
    Dat[rk] = tree->Mapping(f, Dat[rk]);
    if (lk < tree->N) {
        struct F composed = tree->Composition(f, Laz[lk]);
        Laz[lk] = composed;
    }
    if (rk < tree->N) {
        struct F composed = tree->Composition(f, Laz[rk]);
        Laz[rk] = composed;
    }
    Laz[k] = tree->Id;
}

void pushTo(struct LazySegTree *tree, int lk, int rk) {
    for (int i = tree->Log; i > 0; i--) {
        int k_l = lk >> i;
        if ( ((k_l << i) != lk) ) push(tree, k_l);
        int k_r = rk >> i;
        if ( ((k_r << i) != rk) ) push(tree, k_r);
    }
}

void updateFrom(struct LazySegTree *tree, int lk, int rk) {
    for (int i = 1; i <= tree->Log; i++) {
        int lki = lk >> i;
        if ( ( (lki << i) != lk ) ) {
            struct S left = tree->Dat[2*lki];
            struct S right = tree->Dat[2*lki + 1];
            tree->Dat[lki] = tree->Op(left, right);
        }
        int rki = (rk - 1) >> i;
        if ( ( (rki << i) != rk ) ) {
            struct S left = tree->Dat[2*rki];
            struct S right = tree->Dat[2*rki + 1];
            tree->Dat[rki] = tree->Op(left, right);
        }
    }
}

void LazySegTree_apply(struct LazySegTree *tree, int l, int r, struct F f) {
    if (l >= r) return;
    l += tree->N;
    r += tree->N;
    pushTo(tree, l, r);
    int l2 = l, r2 = r;
    while (l2 < r2) {
        if ( (l2 & 1) == 1 ) {
            struct S *dat = &tree->Dat[l2];
            *dat = tree->Mapping(f, *dat);
            if (l2 < tree->N) {
                struct F *lazy = &tree->Laz[l2];
                *lazy = tree->Composition(f, *lazy);
            }
            l2++;
        }
        if ( (r2 & 1) == 1 ) {
            r2--;
            struct S *dat = &tree->Dat[r2];
            *dat = tree->Mapping(f, *dat);
            if (r2 < tree->N) {
                struct F *lazy = &tree->Laz[r2];
                *lazy = tree->Composition(f, *lazy);
            }
        }
        l2 >>= 1;
        r2 >>= 1;
    }
    updateFrom(tree, l, r);
}

long long *global_tenmod;
int global_tenmod_size;
long long inv9;

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    global_tenmod_size = N+1;
    global_tenmod = (long long*)malloc( (global_tenmod_size) * sizeof(long long) );
    global_tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        global_tenmod[j] = (global_tenmod[j-1] * 10LL) % MOD2;
    }
    inv9 = modInv(9);
    struct S dat[N];
    for (int i = 0; i < N; i++) {
        dat[i].sum = global_tenmod[N - i -1];
        dat[i].l = i;
        dat[i].r = i;
    }
    struct LazySegTree tree;
    LazySegTree_Init(&tree, N, S_op, S_E, S_map, F_composite, F_I);
    LazySegTree_BuildFromArray(&tree, dat, N);
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        struct F f = {D, N};
        LazySegTree_apply(&tree, l, r+1, f);
        printf("%lld\n", tree.Dat[1].sum);
    }
    free(global_tenmod);
    free(tree.Dat);
    free(tree.Laz);
    return 0;
}
// End of Code
