#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char **data;
} FastScanner;

FastScanner *fast_scanner_create(FILE *in) {
    FastScanner *scanner = malloc(sizeof(FastScanner));
    scanner->data = malloc(MAX_N * sizeof(char *));
    for (int i = 0; i < MAX_N; ++i) {
        scanner->data[i] = malloc(MAX_N + 1);
    }
    return scanner;
}

void fast_scanner_destroy(FastScanner *scanner) {
    for (int i = 0; i < MAX_N; ++i) {
        free(scanner->data[i]);
    }
    free(scanner->data);
    free(scanner);
}

char *fast_scanner_next(FastScanner *scanner) {
    static char buffer[MAX_N];
    fgets(buffer, MAX_N, stdin);
    return strtok(buffer, " ");
}

int fast_scanner_next_int(FastScanner *scanner) {
    char *str = fast_scanner_next(scanner);
    return atoi(str);
}

void task_b_solve(int testNumber, FastScanner *in, FILE *out) {
    int n = fast_scanner_next_int(in);
    char **a = malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {
        a[i] = fast_scanner_next(in);
    }

    long P = 37, Q = 47;
    long powP[MAX_N + 1], powQ[MAX_N + 1];
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    long hashRow[MAX_N][MAX_N], hashCol[MAX_N][MAX_N];
    memset(hashRow, 0, sizeof(hashRow));
    memset(hashCol, 0, sizeof(hashCol));

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

    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
}

int main() {
    FastScanner *in = fast_scanner_create(stdin);
    task_b_solve(1, in, stdout);
    fast_scanner_destroy(in);
    return 0;
}
// End of Code
