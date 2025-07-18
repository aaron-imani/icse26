#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    char *token;
} FastScanner;

FastScanner *new_FastScanner(FILE *in) {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    scanner->token = NULL;
    return scanner;
}

char *next(FastScanner *scanner) {
    if (scanner->token == NULL || *scanner->token == '\0') {
        if (fgets(scanner->line, MAX_LINE_LENGTH, stdin) == NULL) {
            return NULL;
        }
        scanner->token = strtok(scanner->line, " ");
    } else {
        scanner->token = strtok(NULL, " ");
    }
    return scanner->token;
}

int nextInt(FastScanner *scanner) {
    char *token = next(scanner);
    return atoi(token);
}

void solve(int testNumber, FastScanner *in, FILE *out) {
    int n = nextInt(in);
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = (char *)malloc(n * sizeof(char));
    }
    long P = 37, Q = 47;
    long *powP = (long *)malloc((n + 1) * sizeof(long));
    long *powQ = (long *)malloc((n + 1) * sizeof(long));
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }
    for (int i = 0; i < n; i++) {
        next(in);
        sscanf(in->token, "%s", a[i]);
    }

    long **hashRow = (long **)malloc(n * sizeof(long *));
    long **hashCol = (long **)malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = (long *)malloc(n * sizeof(long));
        hashCol[i] = (long *)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
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
                ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
            }
            ans += ok ? 1 : 0;
        }
    }
    fprintf(out, "%d\n", ans);
}

int main() {
    FastScanner *in = new_FastScanner(stdin);
    FILE *out = stdout;
    solve(1, in, out);
    return 0;
}
// End of Code
