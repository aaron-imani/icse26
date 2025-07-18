#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MOD2 998244353LL

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
long long inv9;

typedef struct S (*Op_S)(struct S a, struct S b);
typedef struct S (*Mapping_SF)(struct F f, struct S s);
typedef struct F (*Composite_FF)(struct F f, struct F g);

struct S S_op(struct S s1, struct S s2) {
    long long sum = (s1.sum + s2.sum) % MOD2;
    if (sum < 0) sum += MOD2;
    struct S res;
    res.sum = sum;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

struct S S_map(struct F f, struct S s) {
    int n = f.N;
    int len_l = n - s.l;
    int len_r = n - s.r - 1;
    long long c = (tenmod[len_l] - tenmod[len_r]) % MOD2;
    if (c < 0) c += MOD2;
    long long new_sum = (f.D * c) % MOD2;
    new_sum = (new_sum * inv9) % MOD2;
    struct S res;
    res.sum = new_sum;
    res.l = s.l;
    res.r = s.r;
    return res;
}

struct F F_composite(struct F f, struct F g) {
    struct F res;
    res.D = f.D;
    res.N = f.N;
    return res;
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

long long modInv(long long x) {
    return modPow(x, MOD2-2);
}

struct LazySegTree {
    int N;
    int Log;
    struct S *Dat;
    struct F *Laz;
    Op_S Op;
    struct S E;
    Mapping_SF Mapping;
    Composite_FF Composition;
    struct F Id;
};

void LazySegTree_push(struct LazySegTree *tree, int k) {
    if (tree->Laz[k-1] == tree->Id) return;
    int left = 2 * k;
    int right = 2 * k + 1;
    tree->Dat[left] = tree->Mapping(tree->Laz[k-1], tree->Dat[left]);
    tree->Dat[right] = tree->Mapping(tree->Laz[k-1], tree->Dat[right]);
    if (left < tree->N) {
        tree->Laz[left-1] = tree->Composition(tree->Laz[k-1], tree->Laz[left-1]);
    }
    if (right < tree->N) {
        tree->Laz[right-1] = tree->Composition(tree->Laz[k-1], tree->Laz[right-1]);
    }
    tree->Laz[k-1] = tree->Id;
}

void LazySegTree_pushTo(struct LazySegTree *tree, int l, int r) {
    int Log = tree->Log;
    for (int i = Log; i > 0; i--) {
        int k_l = l >> i;
        int k_r = r >> i;
        if ((k_l & (1 << (i-1))) != 0) {
            LazySegTree_push(tree, k_l);
        }
        if ((k_r & (1 << (i-1))) != 0) {
            LazySegTree_push(tree, k_r);
        }
    }
}

void LazySegTree_apply(struct LazySegTree *tree, int l, int r, struct F f) {
    if (l >= r) return;
    int a = l + tree->N;
    int b = r + tree->N;
    LazySegTree_pushTo(tree, a, b);
    int l2 = a, r2 = b;
    while (l2 < r2) {
        if ((l2 & 1) == 1) {
            tree->Dat[l2] = tree->Mapping(f, tree->Dat[l2]);
            if (l2 < tree->N) {
                tree->Laz[l2-1] = tree->Composition(f, tree->Laz[l2-1]);
            }
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            tree->Dat[r2] = tree->Mapping(f, tree->Dat[r2]);
            if (r2 < tree->N) {
                tree->Laz[r2-1] = tree->Composition(f, tree->Laz[r2-1]);
            }
        }
        l2 >>= 1;
        r2 >>= 1;
    }
    for (int i = 1; i <= tree->Log; i++) {
        if (((a >> i) << i) != a) {
            int lki = (a >> i);
            tree->Dat[lki] = tree->Op(tree->Dat[2*lki], tree->Dat[2*lki+1]);
        }
        if (((b-1) >> i) << i != (b-1)) {
            int rki = ((b-1) >> i);
            tree->Dat[rki] = tree->Op(tree->Dat[2*rki], tree->Dat[2*rki+1]);
        }
    }
}

long long LazySegTree_allProd(struct LazySegTree *tree) {
    return tree->Dat[1].sum;
}

int main() {
    inv9 = modInv(9LL);
    int N, Q;
    scanf("%d %d", &N, &Q);
    int next_pow2 = 1;
    while (next_pow2 < N) next_pow2 <<= 1;
    int Log = (int)log2(next_pow2);
    long long *tenmod = (long long*)malloc( (N+1)*sizeof(long long) );
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    
    struct S *dat = (struct S*)malloc(N * sizeof(struct S));
    for (int i = 0; i < N; i++) {
        dat[i].sum = tenmod[N - i - 1];
        dat[i].l = i;
        dat[i].r = i;
    }
    
    struct LazySegTree *tree = (struct LazySegTree*)malloc( sizeof(struct LazySegTree) );
    tree->N = next_pow2;
    tree->Log = Log;
    tree->Dat = (struct S*)malloc( (2 * next_pow2) * sizeof(struct S) );
    tree->Laz = (struct F*)malloc( next_pow2 * sizeof(struct F) );
    
    tree->Op = &S_op;
    tree->E = S_E;
    tree->Mapping = &S_map;
    tree->Composition = &F_composite;
    tree->Id = F_I;
    
    for (int i = 0; i < N; i++) {
        tree->Dat[tree->N + i] = dat[i];
    }
    for (int i = N; i < tree->N; i++) {
        tree->Dat[tree->N + i] = S_E;
    }
    
    for (int i = tree->N - 1; i >= 1; i--) {
        tree->Dat[i] = S_op( tree->Dat[2*i], tree->Dat[2*i+1] );
    }
    
    for (int i = 0; i < tree->N; i++) {
        tree->Laz[i] = F_I;
    }
    
    for (int q = 0; q < Q; q++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        struct F f = {D, N};
        LazySegTree_apply(tree, l, r+1, f);
        printf("%lld\n", LazySegTree_allProd(tree));
    }
    
    free(tenmod);
    free(dat);
    free(tree->Dat);
    free(tree->Laz);
    free(tree);
    return 0;
}

// End of Code
