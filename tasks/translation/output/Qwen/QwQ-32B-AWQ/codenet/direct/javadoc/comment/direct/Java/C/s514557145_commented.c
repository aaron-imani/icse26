#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>

#define MOD2 998244353
#define MOD1 1000000007
#define MAX_N 100005 // Adjust as needed

typedef struct {
    int64_t sum;
    int l;
    int r;
} S;

typedef struct {
    int64_t D;
    int N;
} F;

// Global variables
S S_E = {0, INT_MAX / 2, INT_MIN / 2};
F F_I = {0, 0};
int64_t tenmod[MAX_N];
int64_t inv9;

// Functions corresponding to the Java methods

S S_op(S s1, S s2) {
    S res;
    res.sum = (s1.sum + s2.sum) % MOD2;
    if (res.sum < 0) res.sum += MOD2;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

S S_map(F f, S s) {
    int64_t c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) c += MOD2;
    int64_t new_sum = (f.D * c) % MOD2;
    new_sum = (new_sum * inv9) % MOD2;
    return (S) {new_sum, s.l, s.r};
}

F F_composite(F f, F g) {
    return (F) {f.D, f.N};
}

// The LazySegTree struct
typedef struct {
    int size;
    int N;
    int Log;
    S *Dat;
    F *Laz;
} LazySegTree;

void LazySegTree_init(LazySegTree *tree, int n, S *dat) {
    int N = 1;
    while (N < n) N <<= 1;
    tree->size = n;
    tree->N = N;
    tree->Log = (int) log2(N);
    tree->Dat = (S *) malloc(2 * N * sizeof(S));
    tree->Laz = (F *) malloc(N * sizeof(F));
    
    for (int i = 0; i < n; i++) {
        tree->Dat[N + i] = dat[i];
    }
    for (int i = n; i < N; i++) {
        tree->Dat[N + i] = S_E;
    }
    for (int i = N - 1; i >= 1; i--) {
        tree->Dat[i] = S_op(tree->Dat[2*i], tree->Dat[2*i+1]);
    }
    for (int i = 0; i < N; i++) {
        tree->Laz[i] = F_I;
    }
}

void push(LazySegTree *tree, int k) {
    if (tree->Laz[k] == F_I) return;
    int lk = 2 * k, rk = 2 * k + 1;
    tree->Dat[lk] = S_map(tree->Laz[k], tree->Dat[lk]);
    tree->Dat[rk] = S_map(tree->Laz[k], tree->Dat[rk]);
    if (lk < tree->N) {
        tree->Laz[lk] = F_composite(tree->Laz[k], tree->Laz[lk]);
    }
    if (rk < tree->N) {
        tree->Laz[rk]也知道 F_composite(tree->Laz[k], tree->Laz[rk]);
    }
    tree->Laz[k] = F_I;
}

void pushTo(LazySegTree *tree, int k) {
    for (int i = tree->Log; i > 0; i--) {
        push(tree, k >> i);
    }
}

void update_parents(LazySegTree *tree, int l, int r) {
    while (l > 1 || r > 1) {
        if (l > 1) {
            l >>= 1;
            tree->Dat[l] = S_op(tree->Dat[2*l], tree->Dat[2*l+1]);
        }
        if (r > 1) {
            r >>= 1;
            tree->Dat[r] = S_op(tree->Dat[2*r], tree->Dat[2*r+1]);
        }
    }
}

void LazySegTree_apply_range(LazySegTree *tree, int l, int r, F f) {
    if (l >= r) return;
    int left = l + tree->N;
    int right = r + tree->N;
    
    for (int i = tree->Log; i > 0; i--) {
        if (((left >> i) << i) != left) push(tree, left >> i);
        if (((right >> i) << i) != right) push(tree, (right - 1) >> i);
    }
    
    int l_ptr = left, r_ptr = right;
    while (l_ptr < r_ptr) {
        if (l_ptr & 1) {
            tree->Dat[l_ptr] = S_map(f, tree->Dat[l_ptr]);
            if (l_ptr < tree->N) {
                tree->Laz[l_ptr] = F_composite(f, tree->Laz[l_ptr]);
            }
            l_ptr++;
        }
        if (r_ptr & 1) {
            r_ptr--;
            tree->Dat[r_ptr] = S_map(f, tree->Dat[r_ptr]);
            if (r_ptr < tree->N) {
                tree->Laz[r_ptr] = F_composite(f, tree->Laz[r_ptr]);
            }
        }
        l_ptr >>= 1;
        r_ptr >>= 1;
    }
    
    update_parents(tree, l_ptr, r_ptr);
}

int64_t LazySegTree_allProd(LazySegTree *tree) {
    return tree->Dat[1].sum;
}

int64_t modInv(int64_t x) {
    return modPow(x, MOD2 - 2);
}

int64_t modPow(int64_t x, int64_t y) {
    int64_t z = 1;
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

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10) % MOD2;
    }
    
    inv9 = modInv(9);
    
    S *dat = (S *) malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i].sum = tenmod[N - i - 1];
        dat[i].l = i;
        dat[i].r = i;
    }
    
    LazySegTree tree;
    LazySegTree_init(&tree, N, dat);
    
    for (int j = 0; j < Q; j++) {
        int l, r;
        int64_t D;
        scanf("%d %d %" SCNd64, &l, &r, &D);
        l--;
        r--;
        F f = {D, N};
        
        LazySegTree_apply_range(&tree, l, r+1, f);
        int64_t sum = LazySegTree_allProd(&tree);
        printf("%" PRId64 "\n", sum);
    }
    
    free(dat);
    free(tree.Dat);
    free(tree.Laz);
    return 0;
}
// End of Code
