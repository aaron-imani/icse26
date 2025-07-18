#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node** array;
} MinHeap;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(capacity * sizeof(Node*));
    return minHeap;
}

void swapNodes(Node* a, Node* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void heapifyDown(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->value < minHeap->array[smallest]->value)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->value < minHeap->array[smallest]->value)
        smallest = right;

    if (smallest != index) {
        swapNodes(minHeap->array[index], minHeap->array[smallest]);
        heapifyDown(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap* minHeap, int value) {
    if (minHeap->size == minHeap->capacity) {
        printf("Overflow: Could not insert key\n");
        return;
    }

    int i = minHeap->size;
    minHeap->array[i] = createNode(value);
    minHeap->size++;

    while (i != 0 && minHeap->array[(i - 1) / 2]->value > minHeap->array[i]->value) {
        swapNodes(minHeap->array[i], minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(MinHeap* minHeap) {
    if (minHeap->size <= 0)
        return INT_MAX;
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0]->value;
    }

    int root = minHeap->array[0]->value;
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapifyDown(minHeap, 0);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    MinHeap* minHeap = createMinHeap(n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertMinHeap(minHeap, value);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += extractMin(minHeap);
    }

    // 出力
    printf("%s\n", extractMin(minHeap) < sum ? "Yes" : "No");

    return 0;
}
// End of Code
