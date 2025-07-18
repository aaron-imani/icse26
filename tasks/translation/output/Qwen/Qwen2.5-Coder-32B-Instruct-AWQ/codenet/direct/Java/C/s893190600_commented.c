#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1024

typedef struct {
    int key;
    int val;
} PP;

typedef struct {
    int key;
    int val1;
    int val2;
} PPP;

typedef struct {
    long key;
    long val;
} PPL;

typedef struct {
    long key;
    long val[2];
} PPDL;

typedef struct {
    int key;
    int val;
} PPKEY;

typedef struct {
    long key;
    long val;
} PPLKEY;

typedef struct {
    int key;
    int val;
} Pair;

typedef struct {
    int *data;
    int size;
} List;

typedef struct {
    List **adj;
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (List**)malloc(V * sizeof(List*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (List*)malloc(sizeof(List));
        graph->adj[i]->data = (int*)malloc(MAX * sizeof(int));
        graph->adj[i]->size = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src]->data[graph->adj[src]->size++] = dest;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        printf("\n Adjacency list of vertex %d\n head ", v);
        for (int i = 0; i < graph->adj[v]->size; i++) {
            printf("-> %d", graph->adj[v]->data[i]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adj[i]->data);
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);
}

void prn(char* s) {
    printf("%s\n", s);
}

void prn_int(int i) {
    printf("%d\n", i);
}

void prn_long(long i) {
    printf("%ld\n", i);
}

void prr(char* s) {
    printf("%s", s);
}

int ni() {
    int n;
    scanf("%d", &n);
    return n;
}

long nl() {
    long n;
    scanf("%ld", &n);
    return n;
}

double nd() {
    double n;
    scanf("%lf", &n);
    return n;
}

char* ns() {
    char* str = (char*)malloc(MAX * sizeof(char));
    scanf("%s", str);
    return str;
}

int* ndi(int n) {
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = ni();
    }
    return ans;
}

long* ndl(int n) {
    long* ans = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        ans[i] = nl();
    }
    return ans;
}

double* ndd(int n) {
    double* ans = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ans[i] = nd();
    }
    return ans;
}

char** nds(int n) {
    char** ans = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        ans[i] = ns();
    }
    return ans;
}

int** nddi(int n, int m) {
    int** ans = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            ans[i][j] = ni();
        }
    }
    return ans;
}

long** nddl(int n, int m) {
    long** ans = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        ans[i] = (long*)malloc(m * sizeof(long));
        for (int j = 0; j < m; j++) {
            ans[i][j] = nl();
        }
    }
    return ans;
}

void solve() {
    int H = ni();
    int W = ni();
    char C[H + 2][W + 2];
    for (int i = 0; i < H; i++) {
        char* line = ns();
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = line[j];
        }
        free(line);
    }
    if (H == 1 && W == 1) {
        prn("No");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                prn("No");
                return;
            }
        }
    }
    prn("Yes");
}

int main() {
    solve();
    return 0;
}
// End of Code
