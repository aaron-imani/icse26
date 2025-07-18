#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MOD1 1000000007
#define MOD2 998244353

long long *tenmod;
long long inv9;

typedef struct {
    long long sum;
    int l;
    int r;
} S;

typedef struct {
    long long D;
    int N;
} F;

S S_E = {0, INT_MAX/2, INT_MIN/2};
F F_I = {0, 0};

long long modPow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

S S_op(S s1, S s2) {
    S res;
    res.sum = (s1.sum + s2.sum) % MOD2;
    if (res.sum < 0) res.sum += MOD2;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

S S_map(F f, S s) {
    int term1 = f.N - s.l;
    int term2 = f.N - s.r - 1;
    long long c = (tenmod[term1] - tenmod[term2]);
    if (c < 0) c += MOD2;
    long long val = (f.D * c) % MOD2;
    val = (val * inv9) % MOD2;
    S res;
    res.sum = val;
    res.l = s.l;
    res.r = s.r;
    return res;
}

F F_composite(F f, F g) {
    F res;
    res.D = f.D;
    res.N = f.N;
    return res;
}

typedef struct {
    int size;
    int capacity;
    int height;
    S *dat;
    F *laz;
    S (*op)(S, S);
    S e;
    S (*map_f)(F, S);
    F (*compose_f)(F, F);
    F id;
} LazySegTree;

LazySegTree *createLazySegTree(S *initial_data, int N, S (*op)(S,S), S e, S (*map_f)(F,S), F (*compose_f)(F,F), F id) {
    int capacity = 1;
    while (capacity < N) capacity <<= 1;
    int height = log2(capacity);
    LazySegTree *tree = (LazySegTree*)malloc(sizeof(LazySegTree));
    tree->size = N;
    tree->capacity = capacity;
    tree->height = height;
    tree->dat = (S*)malloc(2 * capacity * sizeof(S));
    tree->laz = (F*)malloc(capacity * sizeof(F));
    for (int i = 0; i < 2 * capacity; i++) {
        tree->dat[i] = e;
    }
    for (int i = 0; i < capacity; i++) {
        tree->laz[i] = id;
    }
    for (int i = 0; i < N; i++) {
        tree->dat[capacity + i] = initial_data[i];
    }
    for (int i = capacity - 1; i >= 1; i--) {
        tree->dat[i] = op(tree->dat[2*i], tree->dat[2*i+1]);
    }
    tree->op = op;
    tree->e = e;
    tree->map_f = map_f;
    tree->compose_f = compose_f;
    tree->id = id;
    return tree;
}

void push(LazySegTree *tree, int k) {
    if (tree->laz[k] == tree->id) return;
    F f = tree->laz[k];
    tree->dat[2*k] = tree->map_f(f, tree->dat[2*k]);
    tree->dat[2*k+1] = tree->map_f(f, tree->dat[2*k+1]);
    if (k < tree->capacity) {
        tree->laz[2*k] = tree->compose_f(f, tree->laz[2*k]);
        tree->laz[2*k+1] = tree->compose_f(f, tree->laz[2*k+1]);
    }
    tree->laz[k] = tree->id;
}

void applyRange(LazySegTree *tree, int l, int r, F f) {
    l += tree->capacity;
    r += tree->capacity;
    for (int i = tree->height; i > 0; i--) {
        push(tree, l >> i);
        push(tree, (r-1) >> i);
    }
    while (l < r) {
        if (l % 2 == 1) {
            tree->dat[l] = tree->map_f(f, tree->dat[l]);
            if (l < tree->capacity) {
                tree->laz[l] = tree->compose_f(f, tree->laz[l]);
            }
            l++;
        }
        if (r % 2 == 1) {
            r--;
            tree->dat[r] = tree->map_f(f, tree->dat[r]);
            if (r < tree->capacity) {
                tree->laz[r] = tree->compose_f(f, tree->laz[r]);
            }
        }
        l >>= 1;
        r >>= 1;
    }
    while (l > 1) l >>= 1;
    while (r > 1) r >>= 1;
    while (l <= tree->capacity) {
        tree->dat[l] = tree->op(tree->dat[2*l], tree->dat[2*l+1]);
        l++;
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    inv9 = modInv(9, MOD2);
    
    tenmod = (long long*)malloc((N + 1) * sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    
    S *dat = (S*)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        int term = N - i - 1;
        dat[i].sum = tenmod[term];
        dat[i].l = i;
        dat[i].r = i;
    }
    
    LazySegTree *tree = createLazySegTree(dat, N, S_op, S_E, S_map, F_composite, F_I);
    
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        F f = {D, N};
        applyRange(tree, l, r + 1, f);
        printf("%lld\n", tree->dat[1].sum);
    }
    
    free(tenmod);
    free(dat);
    free(tree->dat);
    free(tree->laz);
    free(tree);
    return 0;
}
// End of Code
