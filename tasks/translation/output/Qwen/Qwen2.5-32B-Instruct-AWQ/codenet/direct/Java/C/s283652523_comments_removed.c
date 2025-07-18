#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    FILE *input;
} FastScanner;

FastScanner *new_FastScanner(FILE *stream) {
    FastScanner *scanner = (FastScanner *)malloc(sizeof(FastScanner));
    scanner->input = stream;
    return scanner;
}

void close_FastScanner(FastScanner *scanner) {
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
    while (true) {
        b = fgetc(scanner->input);
        if (b < '0' || '9' < b) return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

double nextDouble(FastScanner *scanner) {
    double sign = 1;
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
    while (true) {
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

char nextChar(FastScanner *scanner) {
    int b = fgetc(scanner->input);
    while (isspace(b)) {
        b = fgetc(scanner->input);
    }
    return (char)b;
}

char *nextStr(FastScanner *scanner) {
    char *buffer = (char *)malloc(1024 * sizeof(char));
    int b = fgetc(scanner->input);
    while (isspace(b)) {
        b = fgetc(scanner->input);
    }
    int idx = 0;
    while (b != -1 && !isspace(b)) {
        buffer[idx++] = (char)b;
        b = fgetc(scanner->input);
    }
    buffer[idx] = '\0';
    return buffer;
}

char *nextLine(FastScanner *scanner) {
    char *buffer = (char *)malloc(1024 * sizeof(char));
    int b = fgetc(scanner->input);
    int idx = 0;
    while (b != -1 && b != '\n') {
        buffer[idx++] = (char)b;
        b = fgetc(scanner->input);
    }
    buffer[idx] = '\0';
    return buffer;
}

int *nextIntArray(FastScanner *scanner, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(scanner);
    }
    return res;
}

void solve(FastScanner *scanner, FILE *output) {
    int N = nextInt(scanner);
    int *A = nextIntArray(scanner, N);
    
    long long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(output, "%lld\n", ans);
}

int main() {
    FastScanner *scanner = new_FastScanner(stdin);
    FILE *output = stdout;
    
    solve(scanner, output);
    
    close_FastScanner(scanner);
    return 0;
}

// End of Code
