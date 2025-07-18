#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MOD 1000000007

typedef struct {
    FILE *input;
} FastScanner;

FastScanner* createFastScanner(FILE *stream) {
    FastScanner *scanner = (FastScanner*)malloc(sizeof(FastScanner));
    scanner->input = stream;
    return scanner;
}

void closeFastScanner(FastScanner *scanner) {
    fclose(scanner->input);
    free(scanner);
}

int nextInt(FastScanner *scanner) {
    long nl = nextLong(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "NumberFormatException\n");
        exit(EXIT_FAILURE);
    }
    return (int)nl;
}

long nextLong(FastScanner *scanner) {
    int sign = 1;
    int b;
    while ((b = fgetc(scanner->input)) != EOF && !isdigit(b) && b != '-' && b != '+');
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->input);
    } else if (b == '+') {
        b = fgetc(scanner->input);
    }
    long ret = b - '0';
    while (isdigit(b = fgetc(scanner->input))) {
        ret *= 10;
        ret += b - '0';
    }
    return ret * sign;
}

void nextIntArray(FastScanner *scanner, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt(scanner);
    }
}

void solve(FastScanner *scanner) {
    int N = nextInt(scanner);
    int *A = (int*)malloc(N * sizeof(int));
    nextIntArray(scanner, A, N);

    long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%ld\n", ans);
    free(A);
}

int main() {
    FastScanner *scanner = createFastScanner(stdin);
    solve(scanner);
    closeFastScanner(scanner);
    return 0;
}
// End of Code
