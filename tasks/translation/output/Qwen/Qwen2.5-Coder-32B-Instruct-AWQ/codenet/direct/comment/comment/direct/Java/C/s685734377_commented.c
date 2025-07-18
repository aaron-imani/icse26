#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

typedef struct {
    FILE *in;
    char buffer[1024];
    char *bufptr;
    char *bufend;
} FastScanner;

FastScanner *createFastScanner(FILE *in) {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->in = in;
    scanner->bufptr = scanner->buffer;
    scanner->bufend = scanner->buffer;
    return scanner;
}

char *next(FastScanner *scanner) {
    while (scanner->bufptr == scanner->bufend) {
        size_t bytesRead = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->in);
        if (bytesRead == 0) {
            return NULL;
        }
        scanner->bufptr = scanner->buffer;
        scanner->bufend = scanner->buffer + bytesRead;
    }
    char *start = scanner->bufptr;
    while (scanner->bufptr < scanner->bufend && *scanner->bufptr != ' ' && *scanner->bufptr != '\n') {
        scanner->bufptr++;
    }
    *scanner->bufptr++ = '\0';
    return start;
}

int nextInt(FastScanner *scanner) {
    return atoi(next(scanner));
}

void solve(int n, char a[MAXN][MAXN], long P, long Q, long powP[MAXN + 1], long powQ[MAXN + 1]) {
    long hashRow[MAXN][MAXN];
    long hashCol[MAXN][MAXN];
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
    printf("%d\n", ans);
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    int n = nextInt(in);
    char a[MAXN][MAXN];
    long P = 37, Q = 47;
    long powP[MAXN + 1], powQ[MAXN + 1];
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }
    for (int i = 0; i < n; i++) {
        next(in); // Read the line into buffer
        strncpy(a[i], in->bufptr - strlen(in->bufptr) - 1, n);
        a[i][n] = '\0'; // Ensure null termination
    }
    solve(n, a, P, Q, powP, powQ);
    free(in);
    return 0;
}
// End of Code
