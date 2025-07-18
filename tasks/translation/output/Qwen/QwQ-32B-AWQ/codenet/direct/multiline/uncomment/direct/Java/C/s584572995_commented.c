#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int mod;
int *dp;
int **to;
int *to_size;
int N;

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < to_size[v]; i++) {
        int next = to[v][i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1LL;
    if (y % 2 != 0) return (x * modpow(x, y - 1)) % MOD;
    long long tmp = modpow(x, y / 2);
    return (tmp * tmp) % MOD;
}

int main() {
    mod = MOD;
    scanf("%d", &N);
    
    to_size = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) to_size[i] = 0;
    
    int edges[N-1][2];
    for (int i = 0; i < N-1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--; B--;
        edges[i][0] = B;
        edges[i][1] = A;
        to_size[A]++;
        to_size[B]++;
    }
    
    to = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        to[i] = (int *)malloc(to_size[i] * sizeof(int));
    }
    
    int *current_size = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) current_size[i] = 0;
    
    for (int i = 0; i < N-1; i++) {
        int a = edges[i][1];
        int b = edges[i][0];
        to[a][current_size[a]++] = b;
        to[b][current_size[b]++] = a;
    }
    
    free(current_size);
    
    dp = (int *)malloc(N * sizeof(int));
    rec(0, -1);
    
    long long mulsum = 0;
    for (int i = 0; i < N-1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;
        long long a = dp[child];
        long long b = N - a;
        long long term = ((modpow(2, a) - 1) % MOD) * ((modpow(2, b) - 1) % MOD) % MOD;
        if (term < 0) term += MOD;
        mulsum = (mulsum + term) % MOD;
    }
    
    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long long BN = (N * modpow(2, N-1)) % MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long invCases = modpow(cases, MOD - 2);
    long long ans = (WN * invCases) % MOD;
    
    printf("%lld\n", ans);
    
    for (int i = 0; i < N; i++) free(to[i]);
    free(to);
    free(dp);
    free(to_size);
    
    return 0;
}
// End of Code
