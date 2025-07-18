#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int max, min, in;
    scanf("%d", &in);
    max = min = in;
    for (int i = 1; i < N; i++) {
        scanf("%d", &in);
        if (in > max) max = in;
        if (in < min) min = in;
    }
    printf("%d\n", max - min);
    // End of Code
}
