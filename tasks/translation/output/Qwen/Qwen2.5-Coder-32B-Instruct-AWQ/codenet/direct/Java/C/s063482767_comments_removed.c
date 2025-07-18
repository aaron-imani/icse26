#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} PriorityQueue;

void init(PriorityQueue *pq, int capacity) {
    pq->arr = (int *)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    while (index > 0 && pq->arr[(index - 1) / 2] > pq->arr[index]) {
        swap(&pq->arr[index], &pq->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->arr[left] < pq->arr[smallest]) {
        smallest = left;
    }

    if (right < pq->size && pq->arr[right] < pq->arr[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->arr[index], &pq->arr[smallest]);
        heapifyDown(pq, smallest);
    }
}

void add(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->arr = (int *)realloc(pq->arr, pq->capacity * sizeof(int));
    }
    pq->arr[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

int poll(PriorityQueue *pq) {
    if (pq->size == 0) {
        return -1; // Error: queue is empty
    }
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[--pq->size];
    heapifyDown(pq, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    PriorityQueue queue;
    init(&queue, n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        add(&queue, value);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += poll(&queue);
    }

    printf("%s\n", poll(&queue) < sum ? "Yes" : "No");

    free(queue.arr);
    return 0;
}
// End of Code
