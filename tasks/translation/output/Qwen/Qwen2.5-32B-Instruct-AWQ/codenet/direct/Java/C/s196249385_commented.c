#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *array;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list, int initialCapacity) {
    list->array = (long *)malloc(initialCapacity * sizeof(long));
    list->size = 0;
    list->capacity = initialCapacity;
}

void addArrayList(ArrayList *list, long element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (long *)realloc(list->array, list->capacity * sizeof(long));
    }
    list->array[list->size++] = element;
}

void freeArrayList(ArrayList *list) {
    free(list->array);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long *cumsum = (long *)malloc((n + 1) * sizeof(long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    ArrayList b;
    initArrayList(&b, n * (n + 1) / 2);
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long val = cumsum[j + 1] - cumsum[i];
            addArrayList(&b, val);
            if (val > max) {
                max = val;
            }
        }
    }

    long mask = 1L << (long)(log2(max));
    while (mask > 0) {
        ArrayList tmp;
        initArrayList(&tmp, b.size);
        for (int i = 0; i < b.size; i++) {
            if ((b.array[i] & mask) != 0) {
                addArrayList(&tmp, b.array[i]);
            }
        }
        if (tmp.size >= k) {
            freeArrayList(b.array);
            b = tmp;
        } else {
            freeArrayList(tmp.array);
        }
        mask >>= 1;
    }

    if (b.size < k) {
        printf("0\n");
    } else {
        long ans = -1L;
        for (int i = 0; i < b.size; i++) {
            ans &= b.array[i];
        }
        printf("%ld\n", ans);
    }

    free(a);
    free(cumsum);
    freeArrayList(b.array);
    return 0;
}
// End of Code
