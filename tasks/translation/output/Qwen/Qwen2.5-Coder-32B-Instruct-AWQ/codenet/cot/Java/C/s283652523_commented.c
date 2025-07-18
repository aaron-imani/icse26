#include <stdio.h>
#include <stdlib.h>

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
    int ret = b - '0';
    while (1) {
        b = fgetc(scanner->input);
        if (b < '0' || '9' < b) return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

int* nextIntArray(FastScanner *scanner, int n) {
    int *res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(scanner);
    }
    return res;
}

void solve(FastScanner *in) {
    int N = nextInt(in);
    int *A = nextIntArray(in, N);
    
    long long ans = 0, sum = A[N-1];
    for(int i = N - 2; i >= 0; i--){
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%lld\n", ans);
    free(A);
}

int main() {
    FastScanner *in = createFastScanner(stdin);
    solve(in);
    closeFastScanner(in);
    return 0;
}
// End of Code
