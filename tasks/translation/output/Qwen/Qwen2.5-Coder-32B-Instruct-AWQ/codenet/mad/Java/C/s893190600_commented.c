// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1005

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
    long *val;
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
    int size;
    PP *elements;
} List;

typedef struct {
    int size;
    int *elements;
} IntList;

typedef struct {
    int key;
    IntList *value;
} MapEntry;

typedef struct {
    int size;
    MapEntry *entries;
} Map;

Map *createMap() {
    Map *map = (Map *)malloc(sizeof(Map));
    map->size = 0;
    map->entries = NULL;
    return map;
}

void add(Map *map, int key, IntList *value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }
    map->entries = (MapEntry *)realloc(map->entries, (map->size + 1) * sizeof(MapEntry));
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->size++;
}

IntList *get(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return NULL;
}

bool contains(Map *map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return true;
        }
    }
    return false;
}

void freeMap(Map *map) {
    for (int i = 0; i < map->size; i++) {
        free(map->entries[i].value->elements);
        free(map->entries[i].value);
    }
    free(map->entries);
    free(map);
}

IntList *createIntList() {
    IntList *list = (IntList *)malloc(sizeof(IntList));
    list->size = 0;
    list->elements = NULL;
    return list;
}

void addInt(IntList *list, int value) {
    list->elements = (int *)realloc(list->elements, (list->size + 1) * sizeof(int));
    list->elements[list->size] = value;
    list->size++;
}

void freeIntList(IntList *list) {
    free(list->elements);
    free(list);
}

List *createList() {
    List *list = (List *)malloc(sizeof(List));
    list->size = 0;
    list->elements = NULL;
    return list;
}

void addPP(List *list, PP value) {
    list->elements = (PP *)realloc(list->elements, (list->size + 1) * sizeof(PP));
    list->elements[list->size] = value;
    list->size++;
}

void freeList(List *list) {
    free(list->elements);
    free(list);
}

void prn(const char *s) {
    printf("%s\n", s);
}

void prr(const char *s) {
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

char *ns() {
    char *s = (char *)malloc(MAX * sizeof(char));
    scanf("%s", s);
    return s;
}

int *ndi(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = ni();
    }
    return arr;
}

long *ndl(int n) {
    long *arr = (long *)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        arr[i] = nl();
    }
    return arr;
}

double *ndd(int n) {
    double *arr = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        arr[i] = nd();
    }
    return arr;
}

char **nds(int n) {
    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = ns();
    }
    return arr;
}

int **nddi(int n, int m) {
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            arr[i][j] = ni();
        }
    }
    return arr;
}

long **nddl(int n, int m) {
    long **arr = (long **)malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        arr[i] = (long *)malloc(m * sizeof(long));
        for (int j = 0; j < m; j++) {
            arr[i][j] = nl();
        }
    }
    return arr;
}

void solve() {
    int H = ni();
    int W = ni();
    char C[MAX][MAX];
    for (int i = 0; i < H; i++) {
        scanf("%s", C[i + 1] + 1);
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
