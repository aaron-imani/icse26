#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 0) {
        printf("0\n");
        return 0;
    }
    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int count = 1;
    for(int i = 1; i < N; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
} // End of Code
