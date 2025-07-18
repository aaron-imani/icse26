#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList *createArrayList(int initialCapacity) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

void add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = element;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

ArrayList *nextIntArray() {
    ArrayList *list = createArrayList(10);
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        add(list, atoi(token));
        token = strtok(NULL, " ");
    }
    return list;
}

void solve() {
    int N = nextInt();
    ArrayList *list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list->data[i]) {
            max = list->data[i];
            output++;
        }
    }
    printf("%d\n", output);
    freeArrayList(list);
}

int main() {
    solve();
    return 0;
}

// End of Code
