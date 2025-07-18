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

long long tenmod[100005]; // Assuming N up to 1e5.

struct S S_E = {0, (INT_MAX / 2), (INT_MIN / 2)};
struct F F_I = {0, 0};

long long inv9 = 0; // To be initialized in main.

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

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

int next_pow2(int n) {
    int res = 1;
    while (res < n) res <<= 1;
    return res;
}

struct LazySegTree {
    struct S *dat;
    struct F *laz;
    int N;
    int Log;
};

struct S op_S(struct S s1, struct S s2) {
    struct S res;
    res.sum = (s1.sum + s2.sum) % MOD2;
    if (res.sum < 0) res.sum += MOD2;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

struct S map_F_S(struct F f, struct S s) {
    long long term1 = tenmod[f.N - s.l];
    long long term2 = tenmod[f.N - s.r - 1];
    long long c = (term1 - term2) % MOD2;
    if (c < 0) c += MOD2;
    long long new_sum = (f.D * c) % MOD2;
    new_sum = (new_sum * inv9) % MOD2;
    struct S res = {new_sum, s.l, s.r};
    return res;
}

struct F composite_F(struct F f, struct F g) {
    return (struct F) {f.D, f.N};
}

void push(struct LazySegTree *tree, int k) {
    if (tree->laz[k] == F_I) return;
    int lk = 2 * k;
    int rk = 2 * k + 1;
    tree->dat[lk] = map_F_S(tree->laz[k], tree->dat[lk]);
    tree->dat[rk] = map_F_S(tree->laz[k], tree->dat[rk]);
    if (lk < tree->N) {
        tree->laz[lk] = composite_F(tree->laz[k], tree->laz[lk]);
    }
    if (rk < tree->N) {
        tree->laz[rk] = composite_F(tree->laz[k], tree->laz[rk]);
    }
    tree->laz[k] = F_I;
}

void pushToRange(struct LazySegTree *tree, int l, int r) {
    int log_level = tree->Log;
    for (int i = log_level; i > 0; i--) {
        int k_l = l >> i;
        push(tree, k_l);
        int k_r = (r-1) >> i;
        push(tree, k_r);
    }
}

struct LazySegTree * create_LazySegTree(int n, struct S *initial) {
    int tree_size = next_pow2(n);
    struct LazySegTree *tree = (struct LazySegTree*)malloc(sizeof(struct LazySegTree));
    tree->N = tree_size;
    tree->Log = (int)log2(tree_size);
    tree->dat = (struct S*)calloc(2 * tree_size, sizeof(struct S));
    tree->laz = (struct F*)calloc(tree_size, sizeof(struct F));
    for (int i = 0; i < n; i++) {
        tree->dat[tree->N + i] = initial[i];
    }
    for (int i = n; i < tree->N; i++) {
        tree->dat[tree->N + i] = S_E;
    }
    for (int i = tree->N - 1; i >= 1; i--) {
        tree->dat[i] = op_S(tree->dat[2*i], tree->dat[2*i+1]);
    }
    for (int i = 0; i < tree->N; i++) {
        tree->laz[i] = F_I;
    }
    return tree;
}

void apply_range(struct LazySegTree *tree, int l, int r, struct F f) {
    if (l >= r) return;
    l += tree->N;
    r += tree->N;
    pushToRange(tree, l, r);
    for (int l2 = l, r2 = r; l2 < r2; ) {
        if ( (l2 & 1) == 1 ) {
            tree->dat[l2] = map_F_S(f, tree->dat[l2]);
            if ( l2 < tree->N ) {
                struct F new_laz = composite_F(f, tree->laz[l2]);
                tree->laz[l2] = new_laz;
            }
            l2++;
        }
        if ( (r2 & 1) == 1 ) {
            r2--;
            tree->dat[r2] = map_F_S(f, tree->dat[r2]);
            if ( r2 < tree->N ) {
                struct F new_laz = composite_F(f, tree->laz[r2]);
                tree->laz[r2] = new_laz;
            }
        }
        l2 >>= 1;
        r2 >>= 1;
    }
}

void updateFrom(struct LazySegTree *tree, int l, int r) {
    for (int i = 1; i <= tree->Log; i++) {
        int l2 = l >> i;
        if ( ( (l2 >> i) << i ) != l2 ) {
            int parent = l2 >> 1;
            tree->dat[parent] = op_S(tree->dat[parent*2], tree->dat[parent*2+1]);
        }
        int r2 = (r-1) >> i;
        if ( ( (r2 >> i) << i ) != r2 ) {
            int parent = r2 >> 1;
            tree->dat[parent] = op_S(tree->dat[parent*2], tree->dat[parent*2+1]);
        }
    }
}

void free_LazySegTree(struct LazySegTree *tree) {
    free(tree->dat);
    free(tree->laz);
    free(tree);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    // Precompute tenmod
    tenmod[0] = 1;
    for (int j=1; j<=N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    
    // Initialize the initial array of S structs
    struct S *initial = (struct S*)malloc(N * sizeof(struct S));
    for (int i=0; i<N; i++) {
        initial[i].sum = tenmod[N - i - 1];
        initial[i].l = i;
        initial[i].r = i;
    }
    
    struct LazySegTree *tree = create_LazySegTree(N, initial);
    
    inv9 = modInv(9);
    
    for (int q=0; q<Q; q++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        struct F f = {D, N};
        apply_range(tree, l, r+1, f);
        printf("%lld\n", tree->dat[1].sum);
    }
    
    free(initial);
    free_LazySegTree(tree);
    
    return 0;
}

// End of Code
