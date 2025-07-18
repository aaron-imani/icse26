#include <stdio.h>
#include <stdlib.h>

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

long long *tenmod;
long long inv9;

S op_S(S a, S b) {
    long long sum = (a.sum + b.sum) % MOD2;
    if (sum < 0) sum += MOD2;
    int new_l = (a.l < b.l) ? a.l : b.l;
    int new_r = (a.r > b.r) ? a.r : b.r;
    return (S){sum, new_l, new_r};
}

S map_SF(F f, S s) {
    long long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) c += MOD2;
    long long res = (f.D * c) % MOD2;
    res = (res * inv9) % MOD2;
    return (S){res % MOD2, s.l, s.r};
}

F compose_FF(F f, F g) {
    return (F){f.D, f.N};
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

typedef struct {
    int N;
    int size;
    int log;
    S *dat;
    F *lazy;
    S e;
    F id;
    S (*op)(S, S);
    S (*mapping)(F, S);
    F (*composition)(F, F);
} LazySegTree;

void LazySegTree_init(LazySegTree *st, int n, S (*op)(S, S), S e, S (*mapping)(F, S), F (*composition)(F, F), F id) {
    st->N = n;
    st->size = 1;
    while (st->size < st->N) st->size <<= 1;
    st->log = 0;
    while ((1 << st->log) < st->size) st->log++;
    st->dat = (S*)malloc(2 * st->size * sizeof(S));
    st->lazy = (F*)malloc(st->size * sizeof(F));
    st->op = op;
    st->mapping = mapping;
    st->composition = composition;
    st->e = e;
    st->id = id;
    for (int i = 0; i < 2 * st->size; i++) {
        st->dat[i] = e;
    }
    for (int i = 0; i < st->size; i++) {
        st->lazy[i] = id;
    }
}

void LazySegTree_build(LazySegTree *st, S *dat_arr) {
    for (int i = 0; i < st->N; i++) {
        st->dat[st->size + i] = dat_arr[i];
    }
    for (int i = st->size - 1; i >= 1; i--) {
        st->dat[i] = st->op(st->dat[2*i], st->dat[2*i+1]);
    }
}

void LazySegTree_push(LazySegTree *st, int k) {
    if (st->lazy[k].D == 0 && st->lazy[k].N == 0) return;
    int left = 2 * k;
    int right_node = 2 * k + 1;
    st->dat[left] = st->mapping(st->lazy[k], st->dat[left]);
    st->dat[right_node] = st->mapping(st->lazy[k], st->dat[right_node]);
    if (k < st->size) {
        st->lazy[left] = st->composition(st->lazy[k], st->lazy[left]);
        st->lazy[right_node] = st->composition(st->lazy[k], st->lazy[right_node]);
    }
    st->lazy[k] = st->id;
}

void LazySegTree_push_ancestors(LazySegTree *st, int l, int r) {
    for (int i = st->log; i > 0; i--) {
        if (((l >> i) << i) != l) {
            LazySegTree_push(st, l >> i);
        }
        if (((r >> i) << i) != r) {
            LazySegTree_push(st, (r - 1) >> i);
        }
    }
}

void LazySegTree_update_from(LazySegTree *st, int l, int r) {
    for (int i = 1; i <= st->log; i++) {
        if (((l >> i) << i) != l) {
            int l_node = l >> i;
            st->dat[l_node] = st->op(st->dat[2*l_node], st->dat[2*l_node + 1]);
        }
        if ((( (r -1) >> i ) << i ) != (r -1)) {
            int r_node = (r - 1) >> i;
            st->dat[r_node] = st->op(st->dat[2*r_node], st->dat[2*r_node + 1]);
        }
    }
}

void LazySegTree_apply_range(LazySegTree *st, int l, int r, F f) {
    if (l >= r) return;
    int L = l + st->size;
    int R = r + st->size;
    LazySegTree_push_ancestors(st, L, R);
    for (int l2 = L, r2 = R; l2 < r2; ) {
        if (l2 % 2 == 1) {
            st->dat[l2] = st->mapping(f, st->dat[l2]);
            if (l2 < st->size) {
                st->lazy[l2] = st->composition(f, st->lazy[l2]);
            }
            l2++;
        }
        if (r2 % 2 == 1) {
            r2--;
            st->dat[r2] = st->mapping(f, st->dat[r2]);
            if (r2 < st->size) {
                st->lazy[r2] = st->composition(f, st->lazy[r2]);
            }
        }
        l2 >>= 1;
        r2 >>= 1;
    }
    LazySegTree_update_from(st, L, R);
}

int main() {
    S S_E = {0, (int)(1e9), -(int)(1e9)};
    F F_I = {0, 0};
    int N, Q;
    scanf("%d %d", &N, &Q);
    tenmod = (long long*)malloc((N + 1)*sizeof(long long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    inv9 = modPow(9, MOD2 - 2);
    
    S *dat = (S*)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    
    LazySegTree st;
    LazySegTree_init(&st, N, &op_S, S_E, &map_SF, &compose_FF, F_I);
    LazySegTree_build(&st, dat);
    
    for (int j = 0; j < Q; j++) {
        int l, r;
        long long D;
        scanf("%d %d %lld", &l, &r, &D);
        l--;
        r--;
        F f = {D, N};
        LazySegTree_apply_range(&st, l, r + 1, f);
        S total = st.dat[1];
        printf("%lld\n", total.sum);
    }
    
    free(tenmod);
    free(dat);
    free(st.dat);
    free(st.lazy);
    return 0;
}

// End of Code
