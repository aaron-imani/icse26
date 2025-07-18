#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayListInt;

ArrayListInt *createArrayListInt(int capacity) {
    ArrayListInt *list = (ArrayListInt *)malloc(sizeof(ArrayListInt));
    list->data = (int *)malloc(capacity * sizeof(int));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addArrayListInt(ArrayListInt *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int getArrayListInt(ArrayListInt *list, int index) {
    return list->data[index];
}

void freeArrayListInt(ArrayListInt *list) {
    free(list->data);
    free(list);
}

int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

ArrayListInt *nextIntArray() {
    int N = nextInt();
    ArrayListInt *list = createArrayListInt(N);
    for (int i = 0; i < N; i++) {
        addArrayListInt(list, nextInt());
    }
    return list;
}

void solve() {
    int N = nextInt();
    ArrayListInt *list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= getArrayListInt(list, i)) {
            max = getArrayListInt(list, i);
            output++;
        }
    }
    printf("%d\n", output);
    freeArrayListInt(list);
}

int main() {
    solve();
    return 0;
}
// End of Code
