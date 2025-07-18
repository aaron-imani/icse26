#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void add(Graph0n *graph, int vn, int val) {
    graph->dt[vn].next_vs[graph->dt[vn].size++] = val;
}

void add2(Graph0n *graph, int vn, int val) {
    add(graph, vn, val);
    add(graph, val, vn);
}

int get(Graph0n *graph, int vn, int index) {
    return graph->dt[vn].next_vs[index];
}

int *get_all(Graph0n *graph, int vn) {
    return graph->dt[vn].next_vs;
}

int size_of(Graph0n *graph, int vn) {
    return graph->dt[vn].size;
}

void clear(Graph0n *graph) {
    for (int i = 0; i < graph->size; i++) {
        graph->dt[i].size = 0;
    }
}

int main() {
    int n;
    char s[100000];
    int *flaged;
    long pop1st = 0, surp1 = 0, surp9 = 0;

    scanf("%d", &n);
    scanf("%s", s);
    flaged = (int *)malloc(n * sizeof(int));
    memset(flaged, 0, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

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
            long dw = surp9;
            long dif = pow(2, n - p - 1) % (pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;
            long dif = pow(2, n - p - 1) % (pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }

    free(flaged);
    return 0;
}
// End of Code
