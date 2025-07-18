#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_case() {
    char line[100];
    fgets(line, sizeof(line), stdin);
    int N = atoi(strtok(line, " "));
    int K = atoi(strtok(NULL, " "));

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int main() {
    while (1) {
        if (feof(stdin)) break;
        run_case();
    }
    return 0;
}

// End of Code
