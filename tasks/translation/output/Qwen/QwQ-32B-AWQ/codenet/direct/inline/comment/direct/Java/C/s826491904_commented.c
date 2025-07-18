#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int max, min;
    int first = 0;
    scanf("%d", &first);
    max = min = first;
    for (int i = 1; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num > max) max = num;
        if (num < min) min = num;
    }
    printf("%d\n", max - min);
    return 0;
} // End of Code
