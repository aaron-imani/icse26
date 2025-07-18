#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

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
    long val[100];
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
    int* data[MAX];
    int size[MAX];
} Graph;

void graph_add(Graph* g, int from, int to) {
    if (g->data[from] == NULL) {
        g->data[from] = (int*)malloc(MAX * sizeof(int));
        g->size[from] = 0;
    }
    g->data[from][g->size[from]++] = to;
}

bool graph_contains(Graph* g, int key) {
    return g->data[key] != NULL;
}

int* graph_get(Graph* g, int key) {
    return g->data[key];
}

void graph_del(Graph* g, int from, int to) {
    if (g->data[from] == NULL) return;
    for (int i = 0; i < g->size[from]; i++) {
        if (g->data[from][i] == to) {
            g->data[from][i] = g->data[from][g->size[from] - 1];
            g->size[from]--;
            break;
        }
    }
}

void graph_dump(Graph* g, FILE* out) {
    for (int i = 0; i < MAX; i++) {
        if (g->data[i] != NULL) {
            fprintf(out, "%d : ", i);
            for (int j = 0; j < g->size[i]; j++) {
                fprintf(out, "%d ", g->data[i][j]);
            }
            fprintf(out, "\n");
        }
    }
}

typedef struct {
    Graph g;
    int euler_tour[MAX * 2];
    int begin[MAX];
    int end[MAX];
    int k;
    int root;
} EulerTour;

void euler_tour_dfs(EulerTour* et, int v, int p, FILE* out) {
    fprintf(out, "v = %d  p = %d\n", v, p);
    et->begin[v] = et->k;
    et->euler_tour[et->k++] = v;
    if (!graph_contains(&et->g, v)) return;
    for (int i = 0; i < et->g.size[v]; i++) {
        int next = et->g.data[v][i];
        if (next != p) {
            euler_tour_dfs(et, next, v, out);
            et->euler_tour[et->k++] = v;
        }
    }
    et->end[v] = et->k;
}

void euler_tour_init(EulerTour* et, int p_cnt, int root, Graph g, FILE* out) {
    et->g = g;
    et->root = root;
    et->k = 0;
    euler_tour_dfs(et, root, -1, out);
}

int* euler_tour_get_part_tour(EulerTour* et, int v) {
    return &et->euler_tour[et->begin[v]];
}

int* euler_tour_get_part_list(EulerTour* et, int v) {
    int* tour = euler_tour_get_part_tour(et, v);
    int size = et->end[v] - et->begin[v];
    int* list = (int*)malloc(size * sizeof(int));
    int* set = (int*)calloc(MAX, sizeof(int));
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!set[tour[i]]) {
            set[tour[i]] = 1;
            list[count++] = tour[i];
        }
    }
    free(set);
    return list;
}

typedef struct {
    FILE* in;
    FILE* out;
} MyInput;

int my_input_read(MyInput* in) {
    return fgetc(in->in);
}

int my_input_next_int(MyInput* in) {
    int c = my_input_read(in);
    while (c != EOF && (c < '0' || c > '9')) c = my_input_read(in);
    int ret = 0;
    bool negative = false;
    if (c == '-') {
        negative = true;
        c = my_input_read(in);
    }
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
        c = my_input_read(in);
    }
    return negative ? -ret : ret;
}

char* my_input_next_string(MyInput* in) {
    static char str[1000];
    int c = my_input_read(in);
    while (c != EOF && (c == ' ' || c == '\n' || c == '\r' || c == '\t')) c = my_input_read(in);
    int i = 0;
    while (c != EOF && c != ' ' && c != '\n' && c != '\r' && c != '\t') {
        str[i++] = c;
        c = my_input_read(in);
    }
    str[i] = '\0';
    return str;
}

void solver_solve(MyInput* in, FILE* out) {
    int H = my_input_next_int(in);
    int W = my_input_next_int(in);
    char C[H + 2][W + 2];
    for (int i = 0; i < H; i++) {
        char* line = my_input_next_string(in);
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = line[j];
        }
    }
    if (H == 1 && W == 1) {
        fprintf(out, "No\n");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                fprintf(out, "No\n");
                return;
            }
        }
    }
    fprintf(out, "Yes\n");
}

int main() {
    MyInput in = {stdin, stdout};
    solver_solve(&in, stdout);
    return 0;
}
// End of Code
