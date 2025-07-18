#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    FILE *input;
} FastScanner;

FastScanner *newFastScanner(FILE *stream) {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->input = stream;
    return scanner;
}

void closeFastScanner(FastScanner *scanner) {
    if (scanner->input != stdin) {
        fclose(scanner->input);
    }
    free(scanner);
}

int nextInt(FastScanner *scanner) {
    long nl = nextLong(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "NumberFormatException\n");
        exit(1);
    }
    return (int)nl;
}

long nextLong(FastScanner *scanner) {
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

int nextChar(FastScanner *scanner) {
    int b = fgetc(scanner->input);
    while (b == ' ' || b == '\t' || b == '\n') {
        b = fgetc(scanner->input);
    }
    return b;
}

char *nextStr(FastScanner *scanner) {
    char *sb = (char *)malloc(100 * sizeof(char));
    int b = fgetc(scanner->input);
    int index = 0;
    while (b == ' ' || b == '\t' || b == '\n') {
        b = fgetc(scanner->input);
    }
    while (b != EOF && b != ' ' && b != '\t' && b != '\n') {
        sb[index++] = b;
        b = fgetc(scanner->input);
    }
    sb[index] = '\0';
    return sb;
}

char *nextLine(FastScanner *scanner) {
    char *sb = (char *)malloc(100 * sizeof(char));
    int b = fgetc(scanner->input);
    int index = 0;
    while (b != EOF && b != '\n') {
        sb[index++] = b;
        b = fgetc(scanner->input);
    }
    sb[index] = '\0';
    return sb;
}

int *nextIntArray(FastScanner *scanner, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(scanner);
    }
    return res;
}

void solve(FastScanner *scanner, FILE *out) {
    int N = nextInt(scanner);
    int *A = nextIntArray(scanner, N);
    
    long long ans = 0, sum = A[N-1];
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
    FastScanner *scanner = newFastScanner(stdin);
    FILE *out = stdout;
    solve(scanner, out);
    closeFastScanner(scanner);
    return 0;
}
// End of Code
