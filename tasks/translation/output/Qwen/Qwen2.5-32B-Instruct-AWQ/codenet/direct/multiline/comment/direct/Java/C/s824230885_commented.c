#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t used;
    size_t allocated;
} ArrayList;

void init(ArrayList *list) {
    list->data = NULL;
    list->used = 0;
    list->allocated = 0;
}

void append(ArrayList *list, int value) {
    if (list->used == list->allocated) {
        size_t new_allocated = list->allocated == 0 ? 1 : list->allocated * 2;
        list->data = realloc(list->data, new_allocated * sizeof(int));
        list->allocated = new_allocated;
    }
    list->data[list->used++] = value;
}

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

ArrayList nextIntArray() {
    ArrayList list;
    init(&list);
    while (1) {
        char c = getchar();
        if (c == ' ' || c == '\n') break;
        ungetc(c, stdin);
        int n = nextInt();
        append(&list, n);
    }
    return list;
}

void solve() {
    int N = nextInt();
    ArrayList list = nextIntArray();
    int max = 0;
    int output = 0;
    for (size_t i = 0; i < list.used; i++) {
        if (max <= list.data[i]) {
            max = list.data[i];
            output++;
        }
    }
    printf("%d\n", output);
}

int main() {
    solve();
    return 0;
}

// End of Code
