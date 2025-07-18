#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *array;
    size_t used;
    size_t allocated;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->array = NULL;
    list->used = 0;
    list->allocated = 0;
}

void addArrayList(ArrayList *list, long value) {
    if (list->used == list->allocated) {
        size_t newAllocated = list->allocated == 0 ? 1 : list->allocated * 2;
        list->array = realloc(list->array, newAllocated * sizeof(long));
        list->allocated = newAllocated;
    }
    list->array[list->used++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->array);
    list->array = NULL;
    list->used = 0;
    list->allocated = 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long *cumsum = malloc((n + 1) * sizeof(long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    ArrayList b;
    initArrayList(&b);
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long diff = cumsum[j + 1] - cumsum[i];
            addArrayList(&b, diff);
            if (diff > max) {
                max = diff;
            }
        }
    }

    long mask = 1L << (sizeof(long) * 8 - __builtin_clzl(max) - 1);
    while (mask > 0) {
        ArrayList tmp;
        initArrayList(&tmp);
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
