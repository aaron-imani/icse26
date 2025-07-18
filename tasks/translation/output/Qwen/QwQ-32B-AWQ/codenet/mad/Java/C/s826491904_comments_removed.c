#include <stdio.h>

int main() {
    int N, num, max, min;
    scanf("%d", &N);
    scanf("%d", &num);
    max = min = num;

    for (int i = 1; i < N; i++) {
        scanf("%d", &num);
        if (num > max) max = num;
        if (num < min) min = num;
    }

    printf("%d\n", max - min);
    return 0;
} // End of Code
