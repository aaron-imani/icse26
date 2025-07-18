#include <stdio.h>

#define MOD 1000000007

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long ans = 0;
    long long sum = A[N-1];
    for (int i = N-2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
// End of Code
