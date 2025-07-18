#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char buffer[MAX];
    int buffer_pos;
    int buffer_len;
} FastScanner;

void initFastScanner(FastScanner *scanner) {
    scanner->buffer_pos = 0;
    scanner->buffer_len = 0;
}

int nextInt(FastScanner *scanner) {
    int result = 0;
    int sign = 1;
    int c;

    while ((c = getchar()) != EOF && (c < '0' || c > '9')) {
        if (c == '-') {
            sign = -1;
        }
    }

    while (c >= '0' && c <= '9') {
        result = result * 10 + (c - '0');
        c = getchar();
    }

    return result * sign;
}

char* next(FastScanner *scanner) {
    if (scanner->buffer_pos >= scanner->buffer_len) {
        scanner->buffer_len = 0;
        while ((scanner->buffer[scanner->buffer_len] = getchar()) != '\n' && scanner->buffer[scanner->buffer_len] != EOF) {
            scanner->buffer_len++;
        }
        scanner->buffer[scanner->buffer_len++] = '\0';
        scanner->buffer_pos = 0;
    }

    int pos = scanner->buffer_pos;
    while (pos < scanner->buffer_len && (scanner->buffer[pos] == ' ' || scanner->buffer[pos] == '\n')) {
        pos++;
    }

    int start = pos;
    while (pos < scanner->buffer_len && scanner->buffer[pos] != ' ' && scanner->buffer[pos] != '\n') {
        pos++;
    }

    scanner->buffer[pos] = '\0';
    scanner->buffer_pos = pos + 1;

    return scanner->buffer + start;
}

int main() {
    FastScanner scanner;
    initFastScanner(&scanner);

    int n = nextInt(&scanner);
    char a[MAX][MAX];
    long P = 37, Q = 47;
    long powP[MAX + 1], powQ[MAX + 1];
    powP[0] = powQ[0] = 1;

    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    for (int i = 0; i < n; i++) {
        char *line = next(&scanner);
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j];
        }
    }

    long hashRow[MAX][MAX], hashCol[MAX][MAX];
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

    return 0;
}
// End of Code
