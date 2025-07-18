#include <stdio.h>

int main() {
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int N, K;
        if (sscanf(line, "%d %d", &N, &K) != 2) {
            continue;
        }
        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
} // End of Code
