#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} PriorityQueue;

void pq_init(PriorityQueue *pq, int capacity) {
    pq->array = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void pq_free(PriorityQueue *pq) {
    free(pq->array);
}

void pq_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pq_heapify(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left] < pq->array[smallest])
        smallest = left;

    if (right < pq->size && pq->array[right] < pq->array[smallest])
        smallest = right;

    if (smallest != i) {
        pq_swap(&pq->array[i], &pq->array[smallest]);
        pq_heapify(pq, smallest);
    }
}

void pq_insert(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        printf("Priority queue overflow\n");
        return;
    }
    int i = pq->size;
    pq->array[i] = value;
    pq->size++;

    while (i != 0 && pq->array[(i - 1) / 2] > pq->array[i]) {
        pq_swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pq_extract_min(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority queue underflow\n");
        return INT_MAX;
    }
    if (pq->size == 1) {
        pq->size--;
        return pq->array[0];
    }
    int root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    pq_heapify(pq, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    PriorityQueue pq;
    pq_init(&pq, n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        pq_insert(&pq, value);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += pq_extract_min(&pq);
    }

    int last = pq_extract_min(&pq);
    printf("%s\n", last < sum ? "Yes" : "No");

    pq_free(&pq);
    return 0;
}
// End of Code
