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
    long long nl = nextLong(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "Number out of int range\n");
        exit(1);
    }
    return (int)nl;
}

long long nextLong(FastScanner *scanner) {
    int sign = 1;
    int b = readChar(scanner);
    while ((b < '0' || b > '9') && b != '-' && b != '+') {
        b = readChar(scanner);
    }
    if (b == '-') {
        sign = -1;
        b = readChar(scanner);
    } else if (b == '+') {
        b = readChar(scanner);
    }
    long long ret = b - '0';
    while (1) {
        b = readChar(scanner);
        if (b < '0' || b > '9') return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

double nextDouble(FastScanner *scanner) {
    int sign = 1;
    int b = readChar(scanner);
    while ((b < '0' || b > '9') && b != '-' && b != '+') {
        b = readChar(scanner);
    }
    if (b == '-') {
        sign = -1;
        b = readChar(scanner);
    } else if (b == '+') {
        b = readChar(scanner);
    }
    double ret = b - '0';
    while (1) {
        b = readChar(scanner);
        if (b < '0' || b > '9') break;
        ret *= 10;
        ret += b - '0';
    }
    if (b != '.') return sign * ret;
    double div = 1;
    b = readChar(scanner);
    while ('0' <= b && b <= '9') {
        ret *= 10;
        ret += b - '0';
        div *= 10;
        b = readChar(scanner);
    }
    return sign * ret / div;
}

char nextChar(FastScanner *scanner) {
    int b = readChar(scanner);
    while (isspace(b)) {
        b = readChar(scanner);
    }
    return (char)b;
}

char* nextStr(FastScanner *scanner) {
    char *str = (char*)malloc(1024);
    int pos = 0;
    int b = readChar(scanner);
    while (isspace(b)) {
        b = readChar(scanner);
    }
    while (b != EOF && !isspace(b)) {
        str[pos++] = (char)b;
        b = readChar(scanner);
    }
    str[pos] = '\0';
    return str;
}

char* nextLine(FastScanner *scanner) {
    char *str = (char*)malloc(1024);
    int pos = 0;
    int b = readChar(scanner);
    while (b != EOF && b != '\n') {
        str[pos++] = (char)b;
        b = readChar(scanner);
    }
    str[pos] = '\0';
    return str;
}

int* nextIntArray(FastScanner *scanner, int n) {
    int *res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(scanner);
    }
    return res;
}

long long* nextLongArray(FastScanner *scanner, int n) {
    long long *res = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        res[i] = nextLong(scanner);
    }
    return res;
}

double* nextDoubleArray(FastScanner *scanner, int n) {
    double *res = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        res[i] = nextDouble(scanner);
    }
    return res;
}

void solve() {
    FastScanner *in = createFastScanner(stdin);
    FILE *out = stdout;

    int N = nextInt(in);
    int *A = nextIntArray(in, N);

    long long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }

    fprintf(out, "%lld\n", ans);

    free(A);
    closeFastScanner(in);
    fclose(out);
}

int main() {
    solve();
    return 0;
}
// End of Code
