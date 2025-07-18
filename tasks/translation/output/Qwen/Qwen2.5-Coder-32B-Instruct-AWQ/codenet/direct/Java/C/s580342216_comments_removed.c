#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_case() {
    char line[100];
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
    while (!feof(stdin)) {
        run_case();
    }
    return 0;
}

// End of Code
