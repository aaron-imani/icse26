#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} PriorityQueue;

void init(PriorityQueue *pq, int capacity) {
    pq->array = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left] < pq->array[smallest])
        smallest = left;

    if (right < pq->size && pq->array[right] < pq->array[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&pq->array[i], &pq->array[smallest]);
        heapify(pq, smallest);
    }
}

void insert(PriorityQueue *pq, int key) {
    if (pq->size == pq->capacity) {
        printf("Overflow: Could not insert key\n");
        return;
    }

    int i = pq->size;
    pq->array[i] = key;
    pq->size = pq->size + 1;

    while (i != 0 && pq->array[(i - 1) / 2] > pq->array[i]) {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(PriorityQueue *pq) {
    if (pq->size <= 0)
        return INT_MAX;
    if (pq->size == 1) {
        pq->size--;
        return pq->array[0];
    }

    int root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    PriorityQueue pq;
    init(&pq, n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(&pq, num);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += extractMin(&pq);
    }

    int last = extractMin(&pq);
    printf("%s\n", last < sum ? "Yes" : "No");

    free(pq.array);
    return 0;
}
// End of Code
