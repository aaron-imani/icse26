#include <stdio.h>
#include <stdlib.h>

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

void closeFastScanner(FastScanner *scanner) {
    fclose(scanner->file);
    free(scanner);
}

int readChar(FastScanner *scanner) {
    if (scanner->buffer_pos >= scanner->buffer_len) {
        scanner->buffer_len = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->file);
        scanner->buffer_pos = 0;
        if (scanner->buffer_len == 0) return EOF;
    }
    return scanner->buffer[scanner->buffer_pos++];
}

int nextInt(FastScanner *scanner) {
    int c, sign = 1;
    while ((c = readChar(scanner)) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        sign = -1;
        c = readChar(scanner);
    } else if (c == '+') {
        c = readChar(scanner);
    }
    int num = c - '0';
    while ((c = readChar(scanner)) >= '0' && c <= '9') {
        num = num * 10 + c - '0';
    }
    return num * sign;
}

long long nextLong(FastScanner *scanner) {
    int c, sign = 1;
    while ((c = readChar(scanner)) != EOF && (c < '0' || c > '9') && c != '-' && c != '+');
    if (c == '-') {
        sign = -1;
        c = readChar(scanner);
    } else if (c == '+') {
        c = readChar(scanner);
    }
    long long num = c - '0';
    while ((c = readChar(scanner)) >= '0' && c <= '9') {
        num = num * 10 + c - '0';
    }
    return num * sign;
}

int* nextIntArray(FastScanner *scanner, int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(scanner);
    }
    return arr;
}

void solve(FastScanner *in) {
    int N = nextInt(in);
    int *A = nextIntArray(in, N);

    long long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%lld\n", ans);
    free(A);
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    solve(in);
    closeFastScanner(in);
    return 0;
}
// End of Code
