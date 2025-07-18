#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

void run_case() {
    char line[MAX_LINE];
    if (fgets(line, sizeof(line), stdin) != NULL) {
        int N, K;
        sscanf(line, "%d %d", &N, &K);

        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }

        printf("%d\n", len);
    }
}

int main() {
    while (run_case()) {
        // run_case() will return 0 if fgets fails, effectively ending the loop
    }
    return 0;
}

// End of Code
