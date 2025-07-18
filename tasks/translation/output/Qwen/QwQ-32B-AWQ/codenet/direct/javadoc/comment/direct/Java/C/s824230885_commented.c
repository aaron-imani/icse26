#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int *arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            output++;
        }
    }
    printf("%d\n", output);
    free(arr);
    return 0;
}
// End of Code
