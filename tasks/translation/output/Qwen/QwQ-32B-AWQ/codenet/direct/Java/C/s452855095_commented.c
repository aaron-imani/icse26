#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int cnt = 0;
    int flag = 1;
    while (1) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                flag = 0;
                break;
            } else {
                arr[i] /= 2;
            }
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
