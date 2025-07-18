#include <stdio.h>

int main() {
    int N, K;
    while (scanf("%d %d", &N, &K) == 2) {
        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
