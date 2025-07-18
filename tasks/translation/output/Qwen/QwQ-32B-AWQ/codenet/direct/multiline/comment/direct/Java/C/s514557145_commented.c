#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

const long long inv9 = modInv(9);

S S_op(S s1, S s2) {
    S res;
    res.sum = (s1.sum + s2.sum) % MOD2;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

S S_map(F f, S s) {
    int a = f.N - s.l;
    int b = f.N - s.r - 1;
    long long c = (tenmod[a] - tenmod[b]);
    if (c < 0) c += MOD2;
    long long temp = (f.D * c) % MOD2;
    temp = (temp * inv9) % MOD2;
    S res;
    res.sum = temp;
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

int next_pow2(int n) {
    int res = 1;
    while (res < n) res <<= 1;
    return res;
}

typedef struct {
    int size;
    int tree_size;
    int Log;
    S *Dat;
    F *Laz;
    S E;
    F Id;
    S (*Op)(S, S);
    S (*Mapping)(F, S);
    F (*Composition)(F, F);
} LazySegTree;

LazySegTree *create_LazySegTree(int n, S *initial_data, S (*op)(S, S), S E, S (*mapping)(F, S), F (*comp)(F, F), F Id) {
    LazySegTree *l = (LazySegTree *)malloc(sizeof(LazySegTree));
    l->size = n;
    l->tree_size = next_pow2(n);
    l->Log = 0;
    while ((1 << l->Log) < l->tree_size) l->Log++;
    l->Dat = (S *)malloc(2 * l->tree_size * sizeof(S));
    l->Laz = (F *)malloc(l->tree_size * sizeof(F));

    for (int i = 0; i < n; i++) {
        l->Dat[l->tree_size + i] = initial_data[i];
    }
    for (int i = n; i < l->tree_size; i++) {
        l->Dat[l->tree_size + i] = E;
    }

    for (int i = l->tree_size - 1; i >= 1; i--) {
        l->Dat[i] = op(l->Dat[2 * i], l->Dat[2 * i + 1]);
    }

    for (int i = 0; i < l->tree_size; i++) {
        l->Laz[i] = Id;
    }

    l->Op = op;
    l->Mapping = mapping;
    l->Composition = comp;
    l->E = E;
    l->Id = Id;

    return l;
}

void push(LazySegTree *l, int k) {
    if (l->Laz[k].D == 0 && l->Laz[k].N == 0) return;

    F f = l->Laz[k];
    S new_left = l->Mapping(f, l->Dat[2 * k]);
    S new_right = l->Mapping(f, l->Dat[2 * k + 1]);
    l->Dat[2 * k] = new_left;
    l->Dat[2 * k + 1] = new_right;

    if (2 * k < l->tree_size) {
        l->Laz[2 * k] = l->Composition(f, l->Laz[2 * k]);
        l->Laz[2 * k + 1] = l->Composition(f, l->Laz[2 * k + 1]);
    }

    l->Laz[k] = (F) {0, 0};
}

void pushTo(LazySegTree *l, int k) {
    for (int i = l->Log; i > 0; i--) {
        int node = k >> i;
        push(l, node);
    }
}

void apply_range(LazySegTree *l, int a, int b, F f) {
    if (a >= b) return;

    int n = l->tree_size;
    int l_start = a + n;
    int r_end = b + n;

    for (int i = l->Log; i > 0; i--) {
        int node_a = l_start >> i;
        if ((node_a << i) != l_start) push(l, node_a);
        int node_b = (r_end - 1) >> i;
        if ((node_b << i) != (r_end - 1)) push(l, node_b);
    }

    while (l_start < r_end) {
        if ( (l_start & 1) == 1 ) {
            l->Dat[l_start] = l->Mapping(f, l->Dat[l_start]);
            if (l_start < l->tree_size) {
                l->Laz[l_start] = l->Composition(f, l->Laz[l_start]);
            }
            l_start++;
        }
        if ( (r_end & 1) == 1 ) {
            r_end--;
            l->Dat[r_end] = l->Mapping(f, l->Dat[r_end]);
            if (r_end < l->tree_size) {
                l->Laz[r_end] = l->Composition(f, l->Laz[r_end]);
            }
        }
        l_start >>= 1;
        r_end >>= 1;
    }

    // Update the parents
    for (int i = 1; i <= l->Log; i++) {
        if ( ( (l_start >> i) << i ) != l_start ) {
            int node = l_start >> i;
            l->Dat[node] = l->Op(l->Dat[2 * node], l->Dat[2 * node + 1]);
        }
        if ( ( (r_end >> i) << i ) != r_end ) {
            int node = (r_end - 1) >> i;
            l->Dat[node] = l->Op(l->Dat[2 * node], l->Dat[2 * node + 1]);
        }
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    long long *tenmod = (long long *)malloc((N + 1) * sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10) % MOD2;
    }

    S *initial_data = (S *)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        initial_data[i].sum = tenmod[N - i - 1];
        initial_data[i].l = i;
        initial_data[i].r = i;
    }

    S E_S = {0, (1 << 30), -(1 << 30)};
    F Id_F = {0, 0};
    LazySegTree *seg_tree = create_LazySegTree(N, initial_data, S_op, E_S, S_map, F_composite, Id_F);

    for (int q = 0; q < Q; q++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        F f = {D, N};
        apply_range(seg_tree, l, r + 1, f);
        printf("%lld\n", seg_tree->Dat[1].sum);
    }

    free(initial_data);
    free(tenmod);
    free(seg_tree->Dat);
    free(seg_tree->Laz);
    free(seg_tree);

    return 0;
}
// End of Code
