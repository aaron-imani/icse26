#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD2 998244353
#define MAX_N 100000

typedef struct {
    long long sum;
    int l;
    int r;
} S;

typedef struct {
    long long D;
    int N;
} F;

long long tenmod[MAX_N + 1];
long long inv9;

S S_E = {0, (int)(0x7FFFFFFF / 2), (int)(-0x7FFFFFFF / 2)};

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long z = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            z = (z * x) % MOD2;
        }
        x = (x * x) % MOD2;
        y /= 2;
    }
    return z % MOD2;
}

S S_op(S s1, S s2) {
    long long sum = (s1.sum + s2.sum) % MOD2;
    S res;
    res.sum = sum;
    res.l = (s1.l < s2.l) ? s1.l : s2.l;
    res.r = (s1.r > s2.r) ? s1.r : s2.r;
    return res;
}

S S_map(F f, S s) {
    int N_val = f.N;
    int l = s.l;
    int r_val = s.r;
    long long c = (tenmod[N_val - l] - tenmod[N_val - r_val - 1]);
    if (c < 0) c += MOD2;
    long long new_sum = (((f.D * c) % MOD2) * inv9) % MOD2;
    S res;
    res.sum = new_sum;
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
    int MAX;
    int N;
    S *Dat;
    F *Laz;
} LazySegTree;

void build(LazySegTree *tree, S *dat, int dat_size) {
    memcpy(tree->Dat + tree->N, dat, dat_size * sizeof(S));
    for (int i = tree->N - 1; i > 0; i--) {
        tree->Dat[i] = S_op(tree->Dat[2*i], tree->Dat[2*i+1]);
    }
}

void push(LazySegTree *tree, int k) {
    if (tree->Laz[k].D == _done
}
