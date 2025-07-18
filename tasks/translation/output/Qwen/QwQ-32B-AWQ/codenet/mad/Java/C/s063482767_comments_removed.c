#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    int sum = total - arr[n-1];
    printf("%s\n", (arr[n-1] < sum) ? "Yes" : "No");
    free(arr);
    return 0;
    // End of Code
