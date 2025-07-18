#include <stdio.h>

#define MAX_SIZE 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int heap[], int *size, int value) {
    (*size)++;
    int current = *size - 1;
    heap[current] = value;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current] < heap[parent]) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

int extractMin(int heap[], int *size) {
    if (*size == 0)
        return -1;
    int root = heap[0];
    heap[0] = heap[(*size) - 1];
    (*size)--;
    int current = 0;
    while (1) {
        int smallest = current;
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        if (left < *size && heap[left] < heap[smallest])
            smallest = left;
        if (right < *size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != current) {
            swap(&heap[current], &heap[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    int heap[MAX_SIZE];
    int size = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(heap, &size, num);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += extractMin(heap, &size);
    }
    int max = extractMin(heap, &size);
    printf("%s\n", (max < sum) ? "Yes" : "No");
    return 0;
}
// End of Code
