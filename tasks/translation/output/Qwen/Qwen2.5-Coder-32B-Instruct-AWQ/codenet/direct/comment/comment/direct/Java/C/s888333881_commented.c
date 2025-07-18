#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000000
#define INFL 1000000000000000000L
#define e97 1000000007

typedef struct Node0n {
    int *next_vs;
    int size;
    int capacity;
} Node0n;

typedef struct Graph0n {
    Node0n *dt;
    int size;
} Graph0n;

typedef struct Edge {
    int from;
    int v2;
    long weight;
} Edge;

typedef struct Edge2 {
    int v2;
    long cost1;
    long cost2;
} Edge2;

typedef struct Vector {
    int x;
    int y;
} Vector;

void Node0n_init(Node0n *node) {
    node->next_vs = (int *)malloc(10 * sizeof(int));
    node->size = 0;
    node->capacity = 10;
}

void Node0n_add(Node0n *node, int val) {
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->next_vs = (int *)realloc(node->next_vs, node->capacity * sizeof(int));
    }
    node->next_vs[node->size++] = val;
}

int Node0n_get(Node0n *node, int ad) {
    return node->next_vs[ad];
}

int *Node0n_getAll(Node0n *node) {
    return node->next_vs;
}

int Node0n_size(Node0n *node) {
    return node->size;
}

void Node0n_clear(Node0n *node) {
    node->size = 0;
}

void Graph0n_init(Graph0n *graph, int sz) {
    graph->dt = (Node0n *)malloc(sz * sizeof(Node0n));
    graph->size = sz;
    for (int i = 0; i < sz; i++) {
        Node0n_init(&graph->dt[i]);
    }
}

void Graph0n_add(Graph0n *graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
}

void Graph0n_add2(Graph0n *graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
    Node0n_add(&graph->dt[val], vn);
}

int Graph0n_get(Graph0n *graph, int vn, int index) {
    return Node0n_get(&graph->dt[vn], index);
}

int *Graph0n_getAll(Graph0n *graph, int vn) {
    return Node0n_getAll(&graph->dt[vn]);
}

int Graph0n_sizeOf(Graph0n *graph, int vn) {
    return Node0n_size(&graph->dt[vn]);
}

void Graph0n_clear(Graph0n *graph) {
    for (int i = 0; i < graph->size; i++) {
        Node0n_clear(&graph->dt[i]);
    }
}

int compare_Edge(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return eb->v2 - ea->v2;
}

int V2Comp(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->v2 > eb->v2) return -1;
    else if (ea->v2 < eb->v2) return 1;
    else if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return 0;
}

int antiV2(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->v2 > eb->v2) return 1;
    else if (ea->v2 < eb->v2) return -1;
    else if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return 0;
}

void fill(bool *flaged, bool value, int n) {
    for (int i = 0; i < n; i++) {
        flaged[i] = value;
    }
}

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = 0;
    long cf = 1;
    while (soeji >= cf) {
        d++;
        cf <<= 1;
    }

    long *ob_pow_2pow = (long *)malloc(d * sizeof(long));
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1L << i)) {
            soeji -= (1L << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

int countFlaged(long bit) {
    int ans = 0;
    for (int i = 0; i < 64; i++) {
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
    fill(flaged, false, n);

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
                if (dw < 0) printf("%d\n", 1 / 0);
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
                if (dw < 0) printf("%d\n", 1 / 0);
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
