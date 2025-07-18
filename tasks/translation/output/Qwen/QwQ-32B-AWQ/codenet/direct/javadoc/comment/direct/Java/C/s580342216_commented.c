#include <stdio.h>

int main() {
    int N, K;
    while (scanf("%d %d", &N, &K) == 2) {
        int len = 0;
        int current = N;
        while (current > 0) {
            current /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
