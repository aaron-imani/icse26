#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000000
#define INFL 1000000000000000000LL
#define e97 1000000007LL

typedef struct {
    int x, y;
} Vector;

typedef struct {
    int v2;
    long long cost1, cost2;
} Edge2;

typedef struct {
    int from, v2;
    long long weight;
} Edge;

typedef struct {
    int *next_vs;
    int size;
} Node0n;

typedef struct {
    Node0n *dt;
    int size;
} Graph0n;

Graph0n *create_graph(int sz) {
    Graph0n *graph = (Graph0n *)malloc(sizeof(Graph0n));
    graph->dt = (Node0n *)malloc(sz * sizeof(Node0n));
    graph->size = sz;
    for (int i = 0; i < sz; i++) {
        graph->dt[i].next_vs = NULL;
        graph->dt[i].size = 0;
    }
    return graph;
}

void add_node(Graph0n *graph, int vn, int val) {
    graph->dt[vn].next_vs = realloc(graph->dt[vn].next_vs, (graph->dt[vn].size + 1) * sizeof(int));
    graph->dt[vn].next_vs[graph->dt[vn].size++] = val;
}

void add_bidirectional_edge(Graph0n *graph, int vn, int val) {
    add_node(graph, vn, val);
    add_node(graph, val, vn);
}

int get_node_value(Graph0n *graph, int vn, int index) {
    return graph->dt[vn].next_vs[index];
}

int get_node_size(Graph0n *graph, int vn) {
    return graph->dt[vn].size;
}

void clear_graph(Graph0n *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->dt[i].next_vs);
        graph->dt[i].next_vs = NULL;
        graph->dt[i].size = 0;
    }
}

int abs(int a) {
    return (a >= 0) ? a : -a;
}

long long abs(long long a) {
    return (a >= 0) ? a : -a;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

long long min(long long a, long long b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

int min_ex_ad(int *dt, int ad) {
    int min = INF;
    for (int i = 0; i < ad; i++) {
        if ((dt[i] < min)) min = dt[i];
    }
    for (int i = ad + 1; i < ad; i++) {
        if ((dt[i] < min)) min = dt[i];
    }
    return min;
}

long long min_ex_ad(long long *dt, int ad) {
    long long min = INFL;
    for (int i = 0; i < ad; i++) {
        if ((dt[i] < min)) min = dt[i];
    }
    for (int i = ad + 1; i < ad; i++) {
        if ((dt[i] < min)) min = dt[i];
    }
    return min;
}

int sum_a(int *dt, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

long long sum_a(long long *dt, int len) {
    long long sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

int count_flaged(long long bit) {
    int ans = 0;
    for (int i = 0; i < 64; i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

long long pow10_e97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = 0;
    while ((1LL << d) <= soeji) d++;

    long long *ob_pow_2pow = (long long *)malloc(d * sizeof(long long));

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    int flaged[n];
    memset(flaged, 0, sizeof(flaged));

    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;

            long long dif = pow10_e97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = count_flaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;

            long long dif = pow10_e97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = count_flaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

// End of Code
