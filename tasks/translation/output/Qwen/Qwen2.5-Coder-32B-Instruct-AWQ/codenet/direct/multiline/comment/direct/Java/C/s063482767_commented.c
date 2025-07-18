#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // 出力
    printf(arr[n-1] < sum ? "Yes\n" : "No\n");

    free(arr);
    return 0;
}
// End of Code
