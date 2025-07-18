#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    FILE *input;
} FastScanner;

FastScanner *fastScannerCreate(FILE *stream) {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->input = stream;
    return scanner;
}

void fastScannerClose(FastScanner *scanner) {
    fclose(scanner->input);
    free(scanner);
}

int fastScannerNextInt(FastScanner *scanner) {
    long nl = fastScannerNextLong(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "Number format exception\n");
        exit(1);
    }
    return (int)nl;
}

long fastScannerNextLong(FastScanner *scanner) {
    int sign = 1;
    int b = fgetc(scanner->input);
    while ((b < '0' || '9' < b) && b != '-' && b != '+') {
        b = fgetc(scanner->input);
    }
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->input);
    } else if (b == '+') {
        b = fgetc(scanner->input);
    }
    long ret = b - '0';
    while (1) {
        b = fgetc(scanner->input);
        if (b < '0' || '9' < b) return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

double fastScannerNextDouble(FastScanner *scanner) {
    int sign = 1;
    int b = fgetc(scanner->input);
    while ((b < '0' || '9' < b) && b != '-' && b != '+') {
        b = fgetc(scanner->input);
    }
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->input);
    } else if (b == '+') {
        b = fgetc(scanner->input);
    }
    double ret = b - '0';
    while (1) {
        b = fgetc(scanner->input);
        if (b < '0' || '9' < b) break;
        ret *= 10;
        ret += b - '0';
    }
    if (b != '.') return sign * ret;
    double div = 1;
    b = fgetc(scanner->input);
    while ('0' <= b && b <= '9') {
        ret *= 10;
        ret += b - '0';
        div *= 10;
        b = fgetc(scanner->input);
    }
    return sign * ret / div;
}

char fastScannerNextChar(FastScanner *scanner) {
    int b = fgetc(scanner->input);
    while (isspace(b)) {
        b = fgetc(scanner->input);
    }
    return (char)b;
}

char *fastScannerNextStr(FastScanner *scanner) {
    char *str = NULL;
    size_t len = 0;
    getline(&str, &len, scanner->input);
    str[strcspn(str, "\n")] = 0;
    return str;
}

int *fastScannerNextIntArray(FastScanner *scanner, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = fastScannerNextInt(scanner);
    }
    return res;
}

void solve(FastScanner *in, FILE *out) {
    int N = fastScannerNextInt(in);
    int *A = fastScannerNextIntArray(in, N);

    long long ans = 0, sum = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(out, "%lld\n", ans);
    free(A);
}

int main() {
    FastScanner *in = fastScannerCreate(stdin);
    FILE *out = stdout;
    solve(in, out);
    fastScannerClose(in);
    return 0;
}

// End of Code
