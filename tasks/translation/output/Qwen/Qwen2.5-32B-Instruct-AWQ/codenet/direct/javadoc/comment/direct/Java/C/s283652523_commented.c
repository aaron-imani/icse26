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

void solve(FastScanner *in, FILE *out) {
    int N = fastScannerNextInt(in);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        A[i] = fastScannerNextInt(in);
    }

    long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(out, "%ld\n", ans);

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
