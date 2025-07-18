#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int nextInt(FILE *input) {
    long long nl = nextLong(input);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "NumberFormatException\n");
        exit(1);
    }
    return (int) nl;
}

long long nextLong(FILE *input) {
    int sign = 1;
    int b = fgetc(input);
    while ((b < '0' || '9' < b) && b != '-' && b != '+') {
        b = fgetc(input);
    }
    if (b == '-') {
        sign = -1;
        b = fgetc(input);
    } else if (b == '+') {
        b = fgetc(input);
    }
    long long ret = b - '0';
    while (1) {
        b = fgetc(input);
        if (b < '0' || '9' < b) return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

int nextChar(FILE *input) {
    int b = fgetc(input);
    while (b == ' ' || b == '\t' || b == '\n' || b == '\r') {
        b = fgetc(input);
    }
    return b;
}

char *nextStr(FILE *input) {
    char *sb = malloc(100);
    int b = fgetc(input);
    int index = 0;
    while (b == ' ' || b == '\t' || b == '\n' || b == '\r') {
        b = fgetc(input);
    }
    while (b != EOF && (b != ' ' && b != '\t' && b != '\n' && b != '\r')) {
        sb[index++] = b;
        b = fgetc(input);
    }
    sb[index] = '\0';
    return sb;
}

char *nextLine(FILE *input) {
    char *sb = malloc(100);
    int b = fgetc(input);
    int index = 0;
    while (b != EOF && b != '\n') {
        sb[index++] = b;
        b = fgetc(input);
    }
    sb[index] = '\0';
    return sb;
}

int *nextIntArray(FILE *input, int n) {
    int *res = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(input);
    }
    return res;
}

void solve(FILE *input, FILE *output) {
    int N = nextInt(input);
    int *A = nextIntArray(input, N);
    
    long long ans = 0, sum = A[N-1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(output, "%lld\n", ans);
    free(A);
}

int main() {
    FILE *input = stdin;
    FILE *output = stdout;
    solve(input, output);
    return 0;
}
// End of Code
