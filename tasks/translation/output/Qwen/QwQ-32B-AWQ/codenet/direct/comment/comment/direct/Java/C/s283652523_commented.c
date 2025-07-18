#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int*)malloc(N * sizeof(int));
    for (int i =0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long ans =0;
    long long sum = A[N-1];
    for (int i = N-2; i >=0; i--) {
        long long product = (sum * (long long)A[i]) % MOD;
        if (product <0) product += MOD;
        ans = (ans + product) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    printf("%lld\n", ans);
    free(A);
    return 0;
}
// End of Code
