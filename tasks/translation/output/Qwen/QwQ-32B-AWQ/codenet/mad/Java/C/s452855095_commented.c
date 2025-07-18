#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int cnt = 0;
    while (1) {
        int flag = 1; // Reset flag each iteration
        for(int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                flag = 0;
                break;
            }
            arr[i] /= 2;
        }
        if (flag) {
            cnt++;
        } else {
            break;
        }
    }
    printf("%d\n", cnt);
    free(arr);
    return 0;
}
// End of Code
