#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *array;
    size_t used;
    size_t size;
} ArrayList;

void initArrayList(ArrayList *list, size_t initialSize) {
    list->array = (long *)malloc(initialSize * sizeof(long));
    list->used = 0;
    list->size = initialSize;
}

void addArrayList(ArrayList *list, long value) {
    if (list->used == list->size) {
        list->size *= 2;
        list->array = (long *)realloc(list->array, list->size * sizeof(long));
    }
    list->array[list->used++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->array);
    list->array = NULL;
    list->used = 0;
    list->size = 0;
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

    long mask = 1L << (sizeof(long) * 8 - __builtin_clzl(max) - 1);
    while (mask > 0) {
        ArrayList tmp;
        initArrayList(&tmp, b.used);
        for (size_t i = 0; i < b.used; i++) {
            if ((b.array[i] & mask) != 0) {
                addArrayList(&tmp, b.array[i]);
            }
        }
        if (tmp.used >= k) {
            freeArrayList(&b);
            b = tmp;
        } else {
            freeArrayList(&tmp);
        }
        mask >>= 1;
    }

    if (b.used < k) {
        printf("0\n");
    } else {
        long ans = -1L;
        for (size_t i = 0; i < b.used; i++) {
            ans &= b.array[i];
        }
        printf("%ld\n", ans);
    }

    free(a);
    free(cumsum);
    freeArrayList(&b);
    return 0;
}

// End of Code
