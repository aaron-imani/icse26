#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += arr[i];
    }
    printf("%s\n", sum > arr[n-1] ? "Yes" : "No");
    return 0;
}
// End of Code
