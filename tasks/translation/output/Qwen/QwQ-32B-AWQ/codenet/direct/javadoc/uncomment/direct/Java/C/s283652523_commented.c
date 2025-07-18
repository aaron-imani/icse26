#include <stdio.h>
#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long ans = 0;
    long long sum = ( (A[N-1] % MOD) + MOD ) % MOD;
    for(int i = N-2; i >= 0; i--) {
        long long product = ( (sum * (long long)A[i]) % MOD + MOD ) % MOD;
        ans = ( (ans + product) % MOD + MOD ) % MOD;
        sum = ( (sum + (long long)A[i]) % MOD + MOD ) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
// End of Code
