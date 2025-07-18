#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long ans = 0;
    long long sum = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        long long temp = (sum * A[i]) % MOD;
        ans = (ans + temp) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    free(A);
    printf("%lld\n", ans);
    return 0;
} // End of Code
