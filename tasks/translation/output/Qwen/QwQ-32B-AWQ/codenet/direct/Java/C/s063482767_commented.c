#include <stdio.h>

void heapify(int arr[], int n, int i);
int extractMin(int arr[], int *size);

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int size = n;
    // Build the min-heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_val = extractMin(arr, &size);
        sum += min_val;
    }
    
    int remaining = extractMin(arr, &size);
    
    printf("%s\n", remaining < sum ? "Yes" : "No");
    
    return 0;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = . * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

int extractMin(int arr[], int *size) {
    if (*size == 0)
        return -1;
    int root = arr[0];
    if (*size == 1) {
        (*size)--;
        return root;
    }
    arr[0] = arr[*size - 1];
    (*size)--;
    heapify(arr, *size, 0);
    return root;
}
// End of Code
