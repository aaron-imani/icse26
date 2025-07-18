#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int max, min;
    scanf("%d", &max);
    min = max;
    for (int i = 1; i < N; i++) {
        int in;
        scanf("%d", &in);
        if (in > max) {
            max = in;
        }
        if (in < min) {
            min = in;
        }
    }
    printf("%d\n", max - min);
} // End of Code
