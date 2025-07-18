#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Vector;

typedef struct {
    int v2;
    long cost1, cost2;
} Edge2;

typedef struct {
    int from, v2;
    long weight;
} Edge;

typedef struct {
    int *next_vs;
    int size;
} Node0n;

typedef struct {
    Node0n *dt;
    int size;
} Graph0n;

Graph0n* createGraph0n(int sz) {
    Graph0n *graph = (Graph0n*)malloc(sizeof(Graph0n));
    graph->size = sz;
    graph->dt = (Node0n*)malloc(sz * sizeof(Node0n));
    for (int i = 0; i < sz; i++) {
        graph->dt[i].next_vs = NULL;
        graph->dt[i].size = 0;
    }
    return graph;
}

void addNode0n(Graph0n *graph, int vn, int val) {
    graph->dt[vn].next_vs = realloc(graph->dt[vn].next_vs, (graph->dt[vn].size + 1) * sizeof(int));
    graph->dt[vn].next_vs[graph->dt[vn].size++] = val;
}

void addNode0nBidirectional(Graph0n *graph, int vn, int val) {
    addNode0n(graph, vn, val);
    addNode0n(graph, val, vn);
}

int getNode0n(Graph0n *graph, int vn, int index) {
    return graph->dt[vn].next_vs[index];
}

int getSizeOfNode0n(Graph0n *graph, int vn) {
    return graph->dt[vn].size;
}

void clearGraph0n(Graph0n *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->dt[i].next_vs);
        graph->dt[i].next_vs = NULL;
        graph->dt[i].size = 0;
    }
}

bool is_prime(long a) {
    if (a == 1) return false;
    for (long i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

long lcm(long m, long n) {
    long ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

long modinv(long a, long p) {
    long b = p, u = 1, v = 0;
    while (b > 0) {
        long t = a / b;
        long pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

long pow(long n, int k) {
    long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2(int in) {
    return in * in;
}

long pow2(long in) {
    return in * in;
}

double pow2(double in) {
    return in * in;
}

int getDigit2(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1L << d);
    }
    return d;
}

int getDigit10(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d;
}

bool isINF(int in) {
    if (((long)in * 20) > 100000000) return true;
    else return false;
}

bool isINFL(long in) {
    if ((in * 10000) > 10000000000000000) return true;
    else return false;
}

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    long *ob_pow_2pow = (long*)malloc(d * sizeof(long));

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (long)(1 << i)) {
            soeji -= (long)(1 << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

int countFlaged(long bit) {
    int ans = 0;
    for (long i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1L << i)) > 0) ans++;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    bool flaged[n];
    for (int i = 0; i < n; i++) {
        flaged[i] = false;
    }

    long pop1st = 0L;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2L;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1L);
    }

    long surp9 = 0L;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2L;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1L);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long dw = surp9;

            long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1L);
            dw %= (pop1st - 1L);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;

            long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1L);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

// End of Code
