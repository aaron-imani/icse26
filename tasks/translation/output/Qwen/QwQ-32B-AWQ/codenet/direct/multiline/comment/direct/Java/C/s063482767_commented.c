#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%s\n", (max < sum - max) ? "Yes" : "No");
    return 0;
}
// End of Code
