#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **lines;
    int line_count;
    int current_line;
} FastScanner;

FastScanner *create_fast_scanner() {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->lines = NULL;
    scanner->line_count = 0;
    scanner->current_line = 0;
    return scanner;
}

void free_fast_scanner(FastScanner *scanner) {
    for (int i = 0; i < scanner->line_count; i++) {
        free(scanner->lines[i]);
    }
    free(scanner->lines);
    free(scanner);
}

void read_input(FastScanner *scanner) {
    char line[MAX_LINE_LENGTH];
    scanner->line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        scanner->lines = (char **)realloc(scanner->lines, (scanner->line_count + 1) * sizeof(char *));
        scanner->lines[scanner->line_count] = strdup(line);
        scanner->line_count++;
    }
}

char *next(FastScanner *scanner) {
    if (scanner->current_line >= scanner->line_count) {
        return NULL;
    }
    char *line = scanner->lines[scanner->current_line++];
    char *token = strtok(line, " \n");
    return token;
}

int next_int(FastScanner *scanner) {
    char *token = next(scanner);
    return atoi(token);
}

void solve(int testNumber, FastScanner *in, FILE *out) {
    int n = next_int(in);
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = next(in);
    }

    long P = 37, Q = 47;
    long *powP = (long *)malloc((n + 1) * sizeof(long));
    long *powQ = (long *)malloc((n + 1) * sizeof(long));
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    long **hashRow = (long **)malloc(n * sizeof(long *));
    long **hashCol = (long **)malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = (long *)calloc(n, sizeof(long));
        hashCol[i] = (long *)calloc(n, sizeof(long));
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
    FastScanner *in = create_fast_scanner();
    read_input(in);
    solve(1, in, stdout);
    free_fast_scanner(in);
    return 0;
}
// End of Code
