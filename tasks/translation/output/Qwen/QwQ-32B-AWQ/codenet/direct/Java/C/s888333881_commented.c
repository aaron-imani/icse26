#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node0n {
    int* next_vs;
    int size;
    int capacity;
};

struct Graph0n {
    int size;
    struct Node0n* nodes;
};

struct Edge {
    int from;
    int v2;
    long long weight;
};

struct Edge2 {
    int v2;
    long long cost1;
    long long cost2;
};

struct Vector {
    int x;
    int y;
};

struct Graph0n* create_graph(int sz) {
    struct Graph0n* g = malloc(sizeof(struct Graph0n));
    g->size = sz;
    g->nodes = malloc(sz * sizeof(struct Node0n));
    for (int i = 0; i < sz; i++) {
        g->nodes[i].next_vs = malloc(16 * sizeof(int));
        g->nodes[i].size = 0;
        g->nodes[i].capacity = 16;
    }
    return g;
}

void graph_add(struct Graph0n* g, int vn, int val) {
    struct Node0n* node = &g->nodes[vn];
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->next_vs = realloc(node->next_vs, node->capacity * sizeof(int));
    }
    node->next_vs[node->size++] = val;
}

void graph_add2(struct Graph0n* g, int vn, int val) {
    graph_add(g, vn, val);
    graph_add(g, val, vn);
}

int graph_get(struct Graph0n* g, int vn, int index) {
    return g->nodes[vn].next_vs[index];
}

int graph_sizeOf(struct Graph0n* g, int vn) {
    return g->nodes[vn].size;
}

void graph_clear(struct Graph0n* g) {
    for (int i = 0; i < g->size; i++) {
        free(g->nodes[i].next_vs);
        g->nodes[i].size = 0;
        g->nodes[i].capacity = 0;
    }
}

void free_graph(struct Graph0n* g) {
    for (int i = 0; i < g->size; i++) {
        free(g->nodes[i].next_vs);
    }
    free(g->nodes);
    free(g);
}

int compare_edge(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge*)a;
    struct Edge *e2 = (struct Edge*)b;
    if (e1->weight > e2->weight) return -1;
    else if (e1->weight < e2->weight) return 1;
    else return e2->v2 - e1->v2;
}

long long pow_mod(long long base, long long exponent, long long mod) {
    if (mod == 1) return 0;
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int countFlaged(long long dw) {
    int count = 0;
    while (dw != 0) {
        if (dw % 2 == 1) count++;
        dw >>= 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    char flaged[n];
    for (int i = 0; i < n; i++) {
        flaged[i] = 0;
    }
    int pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % (pop1st + 1);
        if (flaged[i]) {
            surp1 = (surp1 + 1) % (pop1st + 1);
        }
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2) % (pop1st - 1);
            if (flaged[i]) {
                surp9 = (surp9 + 1) % (pop1st - 1);
            }
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;
            long long dif = pow_mod(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            if (dw < 0) dw += (pop1st - 1);
            int ans = 1;
            while (dw != 0) {
                int count = countFlaged(dw);
                if (count == 0) break;
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long dif = pow_mod(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);
            int ans = 1;
            while (dw != 0) {
                int count = countFlaged(dw);
                if (count == 0) break;
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
} // End of Code
