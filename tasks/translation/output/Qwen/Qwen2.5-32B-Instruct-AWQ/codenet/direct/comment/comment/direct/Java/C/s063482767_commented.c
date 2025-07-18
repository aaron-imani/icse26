#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} PriorityQueue;

void enqueue(PriorityQueue* pq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (pq->head == NULL || pq->head->value >= value) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* pq) {
    if (pq->head == NULL) {
        return -1; // Error: Queue is empty
    }
    Node* temp = pq->head;
    int value = temp->value;
    pq->head = pq->head->next;
    free(temp);
    return value;
}

int main() {
    int n;
    scanf("%d", &n);

    PriorityQueue pq;
    pq.head = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&pq, value);
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += dequeue(&pq);
    }

    // Output
    printf("%s\n", dequeue(&pq) < sum ? "Yes" : "No");

    return 0;
}
// End of Code
