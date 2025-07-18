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

double nextDouble(FastScanner *scanner) {
    int sign = 1;
    int b;
    while ((b = fgetc(scanner->input)) != EOF && !isdigit(b) && b != '-' && b != '+');
    if (b == '-') {
        sign = -1;
        b = fgetc(scanner->input);
    } else if (b == '+') {
        b = fgetc(scanner->input);
    }
    double ret = b - '0';
    while (isdigit(b = fgetc(scanner->input))) {
        ret *= 10;
        ret += b - '0';
    }
    if (b != '.') return ret * sign;
    double div = 1;
    while (isdigit(b = fgetc(scanner->input))) {
        ret *= 10;
        ret += b - '0';
        div *= 10;
    }
    return sign * ret / div;
}

char nextChar(FastScanner *scanner) {
    int b;
    while ((b = fgetc(scanner->input)) != EOF && isspace(b));
    return (char)b;
}

char* nextStr(FastScanner *scanner) {
    char *str = (char*)malloc(1024);
    int b;
    while ((b = fgetc(scanner->input)) != EOF && isspace(b));
    int i = 0;
    while (b != EOF && !isspace(b)) {
        str[i++] = (char)b;
        b = fgetc(scanner->input);
        if (i >= 1023) {
            str = (char*)realloc(str, i + 1024);
        }
    }
    str[i] = '\0';
    return str;
}

char* nextLine(FastScanner *scanner) {
    char *str = (char*)malloc(1024);
    int b;
    int i = 0;
    while ((b = fgetc(scanner->input)) != EOF && b != '\n') {
        str[i++] = (char)b;
        if (i >= 1023) {
            str = (char*)realloc(str, i + 1024);
        }
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

void solve(FastScanner *in) {
    int N = nextInt(in);
    int *A = nextIntArray(in, N);
    
    long ans = 0, sum = A[N-1];
    for(int i = N - 2; i >= 0; i--){
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%ld\n", ans);
    free(A);
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    solve(in);
    closeFastScanner(in);
    return 0;
}
// End of Code
