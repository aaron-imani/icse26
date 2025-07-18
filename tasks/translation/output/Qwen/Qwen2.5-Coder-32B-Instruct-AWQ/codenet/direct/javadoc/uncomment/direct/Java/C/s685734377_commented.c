#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    FILE *file;
    char buffer[1024];
    int buffer_pos;
    int buffer_len;
} FastScanner;

FastScanner* createFastScanner(FILE *file) {
    FastScanner *scanner = (FastScanner*)malloc(sizeof(FastScanner));
    scanner->file = file;
    scanner->buffer_pos = 0;
    scanner->buffer_len = 0;
    return scanner;
}

void destroyFastScanner(FastScanner *scanner) {
    free(scanner);
}

int nextInt(FastScanner *scanner) {
    char c;
    do {
        c = fgetc(scanner->file);
    } while (c == ' ' || c == '\n');
    ungetc(c, scanner->file);
    int result = 0;
    fscanf(scanner->file, "%d", &result);
    return result;
}

char* next(FastScanner *scanner) {
    if (scanner->buffer_pos >= scanner->buffer_len) {
        scanner->buffer_len = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->file);
        scanner->buffer_pos = 0;
    }
    char *start = scanner->buffer + scanner->buffer_pos;
    while (scanner->buffer_pos < scanner->buffer_len && scanner->buffer[scanner->buffer_pos] != ' ' && scanner->buffer[scanner->buffer_pos] != '\n') {
        scanner->buffer_pos++;
    }
    scanner->buffer[scanner->buffer_pos++] = '\0';
    return start;
}

long power(long base, long exp) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    int n = nextInt(in);
    char **a = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        a[i] = next(in);
    }

    long P = 37, Q = 47;
    long *powP = (long*)malloc((n + 1) * sizeof(long));
    long *powQ = (long*)malloc((n + 1) * sizeof(long));
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
        powQ[i] = (powQ[i - 1] * Q) % MOD;
    }

    long **hashRow = (long**)malloc(n * sizeof(long*));
    long **hashCol = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        hashRow[i] = (long*)calloc(n, sizeof(long));
        hashCol[i] = (long*)calloc(n, sizeof(long));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] = (hashRow[i][k] + ((a[i][j] - 'a') * powP[(j - k + n) % n]) % MOD) % MOD;
                hashCol[j][k] = (hashCol[j][k] + ((a[i][j] - 'a') * powP[(i - k + n) % n]) % MOD) % MOD;
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

    for (int i = 0; i < n; i++) {
        free(hashRow[i]);
        free(hashCol[i]);
    }
    free(hashRow);
    free(hashCol);
    free(powP);
    free(powQ);
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    destroyFastScanner(in);
    return 0;
}
// End of Code
