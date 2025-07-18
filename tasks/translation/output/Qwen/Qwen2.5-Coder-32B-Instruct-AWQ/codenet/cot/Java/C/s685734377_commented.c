#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    FILE *in;
    char buffer[MAX];
    char *ptr;
} FastScanner;

void initFastScanner(FastScanner *scanner, FILE *in) {
    scanner->in = in;
    scanner->ptr = scanner->buffer;
    *scanner->buffer = '\0';
}

int nextInt(FastScanner *scanner) {
    int num;
    fscanf(scanner->in, "%d", &num);
    return num;
}

char *next(FastScanner *scanner) {
    if (*scanner->ptr == '\0') {
        if (fgets(scanner->buffer, MAX, scanner->in) == NULL) {
            return NULL;
        }
        scanner->ptr = scanner->buffer;
    }
    char *token = strsep(&scanner->ptr, " \n");
    return token;
}

void solve(int testNumber, FastScanner *in, FILE *out) {
    int n = nextInt(in);
    char a[n][n];
    long P = 37, Q = 47;
    long powP[n + 1], powQ[n + 1];
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }
    for (int i = 0; i < n; i++) {
        char *line = next(in);
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j];
        }
    }

    long hashRow[n][n], hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = hashCol[i][j] = 0;
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
}

int main() {
    FastScanner in;
    initFastScanner(&in, stdin);
    FILE *out = stdout;
    solve(1, &in, out);
    return 0;
}
// End of Code
