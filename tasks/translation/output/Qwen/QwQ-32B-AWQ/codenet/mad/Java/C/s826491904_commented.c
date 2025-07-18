#include <stdio.h>

int main() {
    int N, max, min, in, i;
    scanf("%d", &N);
    scanf("%d", &max);
    min = max;
    for (i = 1; i < N; i++) {
        scanf("%d", &in);
        if (in > max) max = in;
        if (in < min) min = in;
    }
    printf("%d\n", max - min);
    return 0;
} // End of Code
