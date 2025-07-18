#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    FILE *file;
} FastScanner;

FastScanner* createFastScanner(FILE *file) {
    FastScanner *scanner = (FastScanner*)malloc(sizeof(FastScanner));
    scanner->file = file;
    return scanner;
}

void closeFastScanner(FastScanner *scanner) {
    fclose(scanner->file);
    free(scanner);
}

int nextInt(FastScanner *scanner) {
    long nl = nextLong(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "Number out of int range\n");
        exit(1);
    }
    return (int)nl;
}

long nextLong(FastScanner *scanner) {
    int sign = 1;
    int b = fgetc(scanner->file);
    while ((b < '0' || b > '9') && b != '-' && b != '+') {
        b = fgetc(scanner->file);
    }
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->file);
    } else if (b == '+') {
        b = fgetc(scanner->file);
    }
    long ret = b - '0';
    while (1) {
        b = fgetc(scanner->file);
        if (b < '0' || b > '9') return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

double nextDouble(FastScanner *scanner) {
    int sign = 1;
    int b = fgetc(scanner->file);
    while ((b < '0' || b > '9') && b != '-' && b != '+') {
        b = fgetc(scanner->file);
    }
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->file);
    } else if (b == '+') {
        b = fgetc(scanner->file);
    }
    double ret = b - '0';
    while (1) {
        b = fgetc(scanner->file);
        if (b < '0' || b > '9') break;
        ret *= 10;
        ret += b - '0';
    }
    if (b != '.') return sign * ret;
    double div = 1;
    b = fgetc(scanner->file);
    while ('0' <= b && b <= '9') {
        ret *= 10;
        ret += b - '0';
        div *= 10;
        b = fgetc(scanner->file);
    }
    return sign * ret / div;
}

char nextChar(FastScanner *scanner) {
    int b = fgetc(scanner->file);
    while (isspace(b)) {
        b = fgetc(scanner->file);
    }
    return (char)b;
}

char* nextStr(FastScanner *scanner) {
    char *str = (char*)malloc(1024 * sizeof(char));
    int b = fgetc(scanner->file);
    while (isspace(b)) {
        b = fgetc(scanner->file);
    }
    int i = 0;
    while (b != EOF && !isspace(b)) {
        str[i++] = (char)b;
        b = fgetc(scanner->file);
    }
    str[i] = '\0';
    return str;
}

char* nextLine(FastScanner *scanner) {
    char *str = (char*)malloc(1024 * sizeof(char));
    int b = fgetc(scanner->file);
    int i = 0;
    while (b != EOF && b != '\n') {
        str[i++] = (char)b;
        b = fgetc(scanner->file);
    }
    str[i] = '\0';
    return str;
}

int* nextIntArray(FastScanner *scanner, int n) {
    int *res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(scanner);
    }
    return res;
}

long* nextLongArray(FastScanner *scanner, int n) {
    long *res = (long*)malloc(n * sizeof(long));
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

    long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(out, "%ld\n", ans);

    closeFastScanner(in);
    fclose(out);
}

int main() {
    solve();
    return 0;
}
// End of Code
