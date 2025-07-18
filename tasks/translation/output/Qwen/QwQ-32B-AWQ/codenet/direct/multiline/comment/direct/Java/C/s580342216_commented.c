#include <stdio.h>

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        int N, K;
        sscanf(line, "%d %d", &N, &K);
        int len = 0;
        int temp = N;
        while (temp > 0) {
            temp /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
