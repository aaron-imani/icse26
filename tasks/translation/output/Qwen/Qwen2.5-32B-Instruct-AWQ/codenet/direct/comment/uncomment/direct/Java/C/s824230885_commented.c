#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} ArrayList;

void init(ArrayList *list, size_t initial_capacity) {
    list->array = (int *)malloc(initial_capacity * sizeof(int));
    list->size = 0;
    list->capacity = initial_capacity;
}

void append(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = value;
}

void free_list(ArrayList *list) {
    free(list->array);
}

int next_int() {
    int num;
    scanf("%d", &num);
    return num;
}

ArrayList next_int_array() {
    ArrayList list;
    init(&list, 16); // Initial capacity of 16
    char c;
    while ((c = getchar()) != '\n') {
        ungetc(c, stdin);
        append(&list, next_int());
    }
    return list;
}

void solve() {
    int N = next_int();
    ArrayList list = next_int_array();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list.array[i]) {
            max = list.array[i];
            output++;
        }
    }
    printf("%d\n", output);
    free_list(&list);
}

int main() {
    solve();
    return 0;
}

// End of Code
