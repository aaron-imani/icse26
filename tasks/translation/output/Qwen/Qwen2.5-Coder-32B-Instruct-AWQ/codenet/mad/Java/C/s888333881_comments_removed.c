#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define INF 100000000
#define INFL 10000000000000000
#define e97 1000000007

typedef struct Node0n {
    int* next_vs;
    int size;
    int capacity;
} Node0n;

typedef struct Graph0n {
    Node0n* dt;
    int size;
} Graph0n;

typedef struct Edge {
    int from;
    int v2;
    long long weight;
} Edge;

typedef struct Edge2 {
    int v2;
    long long cost1;
    long long cost2;
} Edge2;

void Node0n_init(Node0n* node) {
    node->next_vs = (int*)malloc(10 * sizeof(int));
    node->size = 0;
    node->capacity = 10;
}

void Node0n_add(Node0n* node, int val) {
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->next_vs = (int*)realloc(node->next_vs, node->capacity * sizeof(int));
    }
    node->next_vs[node->size++] = val;
}

int Node0n_get(Node0n* node, int index) {
    return node->next_vs[index];
}

int* Node0n_getAll(Node0n* node) {
    return node->next_vs;
}

int Node0n_size(Node0n* node) {
    return node->size;
}

void Node0n_clear(Node0n* node) {
    node->size = 0;
}

void Node0n_free(Node0n* node) {
    free(node->next_vs);
}

void Graph0n_init(Graph0n* graph, int sz) {
    graph->dt = (Node0n*)malloc(sz * sizeof(Node0n));
    graph->size = sz;
    for (int i = 0; i < sz; i++) {
        Node0n_init(&graph->dt[i]);
    }
}

void Graph0n_add(Graph0n* graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
}

void Graph0n_add2(Graph0n* graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
    Node0n_add(&graph->dt[val], vn);
}

int Graph0n_get(Graph0n* graph, int vn, int index) {
    return Node0n_get(&graph->dt[vn], index);
}

int* Graph0n_getAll(Graph0n* graph, int vn) {
    return Node0n_getAll(&graph->dt[vn]);
}

int Graph0n_sizeOf(Graph0n* graph, int vn) {
    return Node0n_size(&graph->dt[vn]);
}

void Graph0n_clear(Graph0n* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node0n_clear(&graph->dt[i]);
    }
}

void Graph0n_free(Graph0n* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node0n_free(&graph->dt[i]);
    }
    free(graph->dt);
}

int compare_Edge(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->weight > edgeB->weight) return -1;
    else if (edgeA->weight < edgeB->weight) return 1;
    else return edgeB->v2 - edgeA->v2;
}

int V2Comp(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->v2 > edgeB->v2) return -1;
    else if (edgeA->v2 < edgeB->v2) return 1;
    else if (edgeA->weight > edgeB->weight) return
