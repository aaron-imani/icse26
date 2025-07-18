#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *input;
    char line[10000];
    char *save_ptr;
} FastScanner;

void initScanner(FastScanner *scanner, FILE *input) {
    scanner->input = input;
    scanner->save_ptr = NULL;
}

char* next(FastScanner *scanner) {
    if (scanner->save_ptr == NULL || *scanner->save_ptr == '\0') {
        if (fgets(scanner->line, sizeof(scanner->line), scanner->input) == NULL)
            return NULL;
        scanner->save_ptr = scanner->line;
    }
    char *token = strtok_r(scanner->save_ptr, " \n", &scanner->save_ptr);
    if (token == NULL) {
        return next(scanner);
    }
    return token;
}

int nextInt(FastScanner *scanner) {
    char *token = next(scanner);
    return atoi(token);
}

void solve(int testNumber, FastScanner *in, FILE *out) {
    int n = nextInt(in);
    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = (char *)malloc((n + 1) * sizeof(char));
        char *line = next(in);
        strcpy(a[i], line);
    }

    long long P = 37;
    long long *powP = (long long *)malloc((n + 1) * sizeof(long long));
    powP[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
    }

    long long **hashRow = (long long **)malloc(n * sizeof(long long *));
    long long **hashCol = (long long **)malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = (long long *)calloc(n, sizeof(long long));
        hashCol[i] = (long long *)calloc(n, sizeof(long long));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod = (j - k + n) % n;
                hashRow[i][k] += a[i][j] * powP[mod];
                mod = (i - k + n) % n;
                hashCol[j][k] += a[i][j] * powP[mod];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row_iA = (i + A) % n;
                int col_iB = (i + B) % n;
                if (hashRow[row_iA][B] != hashCol[col_iB][A]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) ans++;
        }
    }

    fprintf(out, "%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(a[i]);
        free(hashRow[i]);
        free(hashCol[i]);
    }
    free(a);
    free(hashRow);
    free(hashCol);
    free(powP);
}

int main() {
    FastScanner scanner;
    initScanner(&scanner, stdin);
    solve(1, &scanner, stdout);
    return 0;
}
// End of Code
