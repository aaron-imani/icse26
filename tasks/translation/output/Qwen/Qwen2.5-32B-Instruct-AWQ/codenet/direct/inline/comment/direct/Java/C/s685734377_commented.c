#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char **data;
} FastScanner;

FastScanner *fast_scanner_create(FILE *in) {
    FastScanner *scanner = malloc(sizeof(FastScanner));
    scanner->data = NULL;
    return scanner;
}

void fast_scanner_destroy(FastScanner *scanner) {
    if (scanner != NULL) {
        free(scanner->data);
        free(scanner);
    }
}

char *fast_scanner_next(FastScanner *scanner) {
    if (scanner->data == NULL) {
        char buffer[1024];
        fgets(buffer, sizeof(buffer), stdin);
        scanner->data = strtok(buffer, " ");
    } else {
        scanner->data = strtok(NULL, " ");
    }
    return scanner->data;
}

int fast_scanner_next_int(FastScanner *scanner) {
    return atoi(fast_scanner_next(scanner));
}

void task_b_solve(int testNumber, FastScanner *in, FILE *out) {
    int n = fast_scanner_next_int(in);
    char **a = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(n * sizeof(char));
    }
    long P = 37, Q = 47;
    long *powP = malloc((n + 1) * sizeof(long)), *powQ = malloc((n + 1) * sizeof(long));
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }
    for (int i = 0; i < n; i++) {
        fscanf(in->data, "%s", a[i]);
    }

    long **hashRow = malloc(n * sizeof(long *));
    long **hashCol = malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = malloc(n * sizeof(long));
        hashCol[i] = malloc(n * sizeof(long));
        memset(hashRow[i], 0, n * sizeof(long));
        memset(hashCol[i], 0, n * sizeof(long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    fprintf(out, "%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(hashRow[i]);
        free(hashCol[i]);
    }
    free(a);
    free(powP);
    free(powQ);
    free(hashRow);
    free(hashCol);
}

int main() {
    FastScanner *in = fast_scanner_create(stdin);
    FILE *out = stdout;
    task_b_solve(1, in, out);
    fast_scanner_destroy(in);
    return 0;
}
// End of Code
