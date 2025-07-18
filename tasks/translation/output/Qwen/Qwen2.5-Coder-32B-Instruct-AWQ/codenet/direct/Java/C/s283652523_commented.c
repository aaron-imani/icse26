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
    int b;
    while (1) {
        b = fgetc(scanner->file);
        if ((b >= '0' && b <= '9') || b == '-' || b == '+') break;
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

char nextChar(FastScanner *scanner) {
    int b;
    while (1) {
        b = fgetc(scanner->file);
        if (!isspace(b)) break;
    }
    return (char)b;
}

char* nextStr(FastScanner *scanner) {
    char *str = (char*)malloc(1024);
    int b;
    int pos = 0;
    while (1) {
        b = fgetc(scanner->file);
        if (!isspace(b)) break;
    }
    while (b != EOF && !isspace(b)) {
        str[pos++] = (char)b;
        b = fgetc(scanner->file);
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

    closeFastScanner(in);
    fclose(out);
}

int main() {
    solve();
    return 0;
}
// End of Code
