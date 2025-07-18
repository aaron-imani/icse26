#include <stdio.h>
#include <stdlib.h>

#define MOD1 1000000007
#define MOD2 998244353

long modInv(long x) {
    long y = MOD2 - 2;
    long z = 1;
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

typedef struct {
    long sum;
    int l;
    int r;
} S;

typedef struct {
    long D;
    int N;
} F;

S op(S s1, S s2) {
    long sum = s1.sum + s2.sum;
    if (sum >= MOD2) {
        sum -= MOD2;
    }
    return (S){sum, s1.l < s2.l ? s1.l : s2.l, s1.r > s2.r ? s1.r : s2.r};
}

S map(F f, S s, long* tenmod, long inv9) {
    long c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]);
    if (c < 0) {
        c += MOD2;
    }
    return (S){((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r};
}

F composite(F f, F g) {
    return (F){f.D, f.N};
}

typedef struct {
    int MAX;
    int N;
    int Log;
    S* Dat;
    F* Laz;
    S (*Op)(S, S);
    S E;
    S (*Mapping)(F, S, long*, long);
    F (*Composition)(F, F);
    F Id;
} LazySegTree;

void build(LazySegTree* lst, S* dat) {
    int l = lst->MAX;
    for (int i = 0; i < l; i++) {
        lst->Dat[lst->N + i] = dat[i];
    }
    for (int i = lst->N - 1; i > 0; i--) {
        lst->Dat[i] = lst->Op(lst->Dat[i << 1], lst->Dat[(i << 1) + 1]);
    }
}

void push(LazySegTree* lst, int k, long* tenmod, long inv9) {
    if (lst->Laz[k].D == lst->Id.D && lst->Laz[k].N == lst->Id.N) return;
    int lk = k << 1, rk = k << 1 | 1;
    lst->Dat[lk] = lst->Mapping(lst->Laz[k], lst->Dat[lk], tenmod, inv9);
    lst->Dat[rk] = lst->Mapping(lst->Laz[k], lst->Dat[rk], tenmod, inv9);
    if (lk < lst->N) lst->Laz[lk] = lst->Composition(lst->Laz[k], lst->Laz[lk]);
    if (rk < lst->N) lst->Laz[rk] = lst->Composition(lst->Laz[k], lst->Laz[rk]);
    lst->Laz[k] = lst->Id;
}

void pushTo(LazySegTree* lst, int k, long* tenmod, long inv9) {
    for (int i = lst->Log; i > 0; i--) push(lst, k >> i, tenmod, inv9);
}

void pushToRange(LazySegTree* lst, int lk, int rk, long* tenmod, long inv9) {
    for (int i = lst->Log; i > 0; i--) {
        if (((lk >> i) << i) != lk) push(lst, lk >> i, tenmod, inv9);
        if (((rk >> i) << i) != rk) push(lst, rk >> i, tenmod, inv9);
    }
}

void updateFrom(LazySegTree* lst, int k) {
    k >>= 1;
    while (k > 0) {
        lst->Dat[k] = lst->Op(lst->Dat[k << 1], lst->Dat[(k << 1) + 1]);
        k >>= 1;
    }
}

void updateFromRange(LazySegTree* lst, int lk, int rk) {
    for (int i = 1; i <= lst->Log; i++) {
        if (((lk >> i) << i) != lk) {
            int lki = lk >> i;
            lst->Dat[lki] = lst->Op(lst->Dat[lki << 1], lst->Dat[(lki << 1) + 1]);
        }
        if (((rk >> i) << i) != rk) {
            int rki = (rk - 1) >> i;
            lst->Dat[rki] = lst->Op(lst->Dat[rki << 1], lst->Dat[(rki << 1) + 1]);
        }
    }
}

void set(LazySegTree* lst, int p, S x, long* tenmod, long inv9) {
    if (p < 0 || p >= lst->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, lst->MAX);
        exit(1);
    }
    p += lst->N;
    pushTo(lst, p, tenmod, inv9);
    lst->Dat[p] = x;
    updateFrom(lst, p);
}

S get(LazySegTree* lst, int p, long* tenmod, long inv9) {
    if (p < 0 || p >= lst->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, lst->MAX);
        exit(1);
    }
    p += lst->N;
    pushTo(lst, p, tenmod, inv9);
    return lst->Dat[p];
}

S allProd(LazySegTree* lst) {
    return lst->Dat[1];
}

void apply(LazySegTree* lst, int p, F f, long* tenmod, long inv9) {
    if (p < 0 || p >= lst->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d).\n", p, 0, lst->MAX);
        exit(1);
    }
    p += lst->N;
    pushTo(lst, p, tenmod, inv9);
    lst->Dat[p] = lst->Mapping(f, lst->Dat[p], tenmod, inv9);
    updateFrom(lst, p);
}

void applyRange(LazySegTree* lst, int l, int r, F f, long* tenmod, long inv9) {
    if (l > r) {
        fprintf(stderr, "Invalid range: [%d, %d)\n", l, r);
        exit(1);
    }
    if (l < 0 || l > lst->MAX || r < 0 || r > lst->MAX) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(1);
    }
    if (l == r) return;
    l += lst->N; r += lst->N;
    pushToRange(lst, l, r, tenmod, inv9);
    for (int l2 = l, r2 = r; l2 < r2;) {
        if ((l2 & 1) == 1) {
            lst->Dat[l2] = lst->Mapping(f, lst->Dat[l2], tenmod, inv9);
            if (l2 < lst->N) lst->Laz[l2] = lst->Composition(f, lst->Laz[l2]);
            l2++;
        }
        if ((r2 & 1) == 1) {
            r2--;
            lst->Dat[r2] = lst->Mapping(f, lst->Dat[r2], tenmod, inv9);
            if (r2 < lst->N) lst->Laz[r2] = lst->Composition(f, lst->Laz[r2]);
        }
        l2 >>= 1; r2 >>= 1;
    }
    updateFromRange(lst, l, r);
}

int maxRight(LazySegTree* lst, int l, int (*g)(S), long* tenmod, long inv9) {
    if (l < 0 || l > lst->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d].\n", l, 0, lst->MAX);
        exit(1);
    }
    if (!g(lst->E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(1);
    }
    if (l == lst->MAX) return lst->MAX;
    l += lst->N;
    pushTo(lst, l, tenmod, inv9);
    S sum = lst->E;
    do {
        l >>= __builtin_ctz(l);
        if (!g(lst->Op(sum, lst->Dat[l]))) {
            while (l < lst->N) {
                push(lst, l, tenmod, inv9);
                l = l << 1;
                if (g(lst->Op(sum, lst->Dat[l]))) {
                    sum = lst->Op(sum, lst->Dat[l]);
                    l++;
                }
            }
            return l - lst->N;
        }
        sum = lst->Op(sum, lst->Dat[l]);
        l++;
    } while ((l & -l) != l);
    return lst->MAX;
}

int minLeft(LazySegTree* lst, int r, int (*g)(S), long* tenmod, long inv9) {
    if (r < 0 || r > lst->MAX) {
        fprintf(stderr, "Index %d is not in [%d, %d].\n", r, 0, lst->MAX);
        exit(1);
    }
    if (!g(lst->E)) {
        fprintf(stderr, "Identity element must satisfy the condition.\n");
        exit(1);
    }
    if (r == 0) return 0;
    r += lst->N;
    pushTo(lst, r - 1, tenmod, inv9);
    S sum = lst->E;
    do {
        r--;
        while (r > 1 && (r & 1) == 1) r >>= 1;
        if (!g(lst->Op(lst->Dat[r], sum))) {
            while (r < lst->N) {
                push(lst, r, tenmod, inv9);
                r = r << 1 | 1;
                if (g(lst->Op(lst->Dat[r], sum))) {
                    sum = lst->Op(lst->Dat[r], sum);
                    r--;
                }
            }
            return r + 1 - lst->N;
        }
        sum = lst->Op(lst->Dat[r], sum);
    } while ((r & -r) != r);
    return 0;
}

typedef struct {
    FILE* in;
    char buffer[1024];
    int curbuf;
    int lenbuf;
} InputReader;

int hasNextByte(InputReader* ir) {
    if (ir->curbuf >= ir->lenbuf) {
        ir->curbuf = 0;
        ir->lenbuf = fread(ir->buffer, 1, sizeof(ir->buffer), ir->in);
        if (ir->lenbuf <= 0)
            return 0;
    }
    return 1;
}

int readByte(InputReader* ir) {
    if (hasNextByte(ir))
        return ir->buffer[ir->curbuf++];
    else
        return -1;
}

int isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

void skip(InputReader* ir) {
    while (hasNextByte(ir) && isSpaceChar(readByte(ir)));
}

int hasNext(InputReader* ir) {
    skip(ir);
    return hasNextByte(ir);
}

char* next(InputReader* ir) {
    if (!hasNext(ir))
        exit(1);
    char* sb = (char*)malloc(1024);
    int b = readByte(ir);
    int i = 0;
    while (!isSpaceChar(b)) {
        sb[i++] = b;
        b = readByte(ir);
    }
    sb[i] = '\0';
    return sb;
}

int nextInt(InputReader* ir) {
    if (!hasNext(ir))
        exit(1);
    int c = readByte(ir);
    while (isSpaceChar(c))
        c = readByte(ir);
    int minus = 0;
    if (c == '-') {
        minus = 1;
        c = readByte(ir);
    }
    int res = 0;
    do {
        if (c < '0' || c > '9')
            exit(1);
        res = res * 10 + c - '0';
        c = readByte(ir);
    } while (!isSpaceChar(c));
    return (minus) ? -res : res;
}

long nextLong(InputReader* ir) {
    if (!hasNext(ir))
        exit(1);
    int c = readByte(ir);
    while (isSpaceChar(c))
        c = readByte(ir);
    int minus = 0;
    if (c == '-') {
        minus = 1;
        c = readByte(ir);
    }
    long res = 0;
    do {
        if (c < '0' || c > '9')
            exit(1);
        res = res * 10 + c - '0';
        c = readByte(ir);
    } while (!isSpaceChar(c));
    return (minus) ? -res : res;
}

int main() {
    FILE* out = stdout;
    InputReader sc = {stdin, {0}, 0, 0};
    int N = nextInt(&sc);
    int Q = nextInt(&sc);
    long* tenmod = (long*)malloc((N + 1) * sizeof(long));
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j - 1] * 10L) % MOD2;
    }
    S* dat = (S*)malloc(N * sizeof(S));
    for (int i = 0; i < N; i++) {
        dat[i] = (S){tenmod[N - i - 1], i, i};
    }
    LazySegTree lst = {
        N, 1, 0, (S*)malloc(2 * N * sizeof(S)), (F*)malloc(N * sizeof(F)),
        op, (S){0, INT_MAX / 2, INT_MIN / 2}, map, composite, (F){0, 0}
    };
    int k = 1;
    while (k < N) k <<= 1;
    lst.N = k;
    lst.Log = __builtin_ctz(lst.N);
    build(&lst, dat);
    long inv9 = modInv(9);
    for (int j = 0; j < Q; j++) {
        int l = nextInt(&sc) - 1;
        int r = nextInt(&sc) - 1;
        long D = nextLong(&sc);
        applyRange(&lst, l, r + 1, (F){D, N}, tenmod, inv9);
        fprintf(out, "%ld\n", allProd(&lst).sum);
    }
    fclose(out);
    free(tenmod);
    free(dat);
    free(lst.Dat);
    free(lst.Laz);
    return 0;
}
// End of Code
