#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long nextLong(FILE *input) {
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
    long ret = b - '0';
    while (1) {
        b = fgetc(input);
        if (b < '0' || '9' < b) return ret * sign;
        ret *= 10;
        ret += b - '0';
    }
}

int* nextIntArray(FILE *input, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextLong(input);
    }
    return res;
}

void solve(FILE *input, FILE *output) {
    int N = nextLong(input);
    int* A = nextIntArray(input, N);
    
    long ans = 0, sum = A[N-1];
    for(int i = N - 2; i >= 0; i--){
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    fprintf(output, "%ld\n", ans);
    free(A);
}

int main() {
    FILE *input = stdin;
    FILE *output = stdout;
    solve(input, output);
    fclose(input);
    fclose(output);
    return 0;
}
// End of Code
