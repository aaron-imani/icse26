#include <stdio.h>

int main() {
    int N, max, min, num;
    scanf("%d", &N);
    scanf("%d", &max);
    min = max;
    for (int i = 1; i < N; i++) {
        scanf("%d", &num);
        if (num > max) max = num;
        if (num < min) min = num;
    }
    printf("%d\n", max - min);
    return 0;
}
// End of Code
