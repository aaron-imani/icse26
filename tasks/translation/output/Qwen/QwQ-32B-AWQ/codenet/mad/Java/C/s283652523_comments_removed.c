#include <stdio.h>
#define MOD 1000000007
int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] %= MOD;
        if (A[i] < 0) A[i] += MOD;
    }
    long long ans = 0;
    long long sum = A[N-1] % MOD;
    for (int i = N-2; i >= 0; i--) {
        long long product = (sum * (long long)A[i]) % MOD;
        ans = (ans + product) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    printf("%lld\n", ans % MOD);
    return 0;
} // End of Code
