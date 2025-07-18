#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 8

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
    int **data;
    int size;
} Graph;

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = size;
    graph->data = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph->data[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int from, int to) {
    graph->data[from] = (int*)realloc(graph->data[from], (graph->data[from] ? graph->data[from][0] + 1 : 1) * sizeof(int));
    if (graph->data[from][0] == 0) {
        graph->data[from][0] = 1;
        graph->data[from][1] = to;
    } else {
        graph->data[from][++graph->data[from][0]] = to;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->data[i] != NULL) {
            printf("%d: ", i);
            for (int j = 1; j <= graph->data[i][0]; j++) {
                printf("%d ", graph->data[i][j]);
            }
            printf("\n");
        }
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->data[i]);
    }
    free(graph->data);
    free(graph);
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char C[H+2][W+2];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf(" %c", &C[i+1][j+1]);
        }
    }
    if (H == 1 && W == 1) {
        printf("No\n");
        return 0;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' && C[i][j-1] != '#' && C[i][j+1] != '#') {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}

// End of Code
