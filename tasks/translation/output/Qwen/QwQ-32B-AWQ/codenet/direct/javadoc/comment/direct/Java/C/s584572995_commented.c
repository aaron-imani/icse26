#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

long long modpow(long long x, long long y);
int rec(int v, int parent, int *dp, int **to, int *to_size);

int main() {
    int N;
    scanf("%d", &N);
    
    int **edges = malloc((N - 1) * sizeof(int *));
    for (int i = 0; i < N - 1; i++) {
        edges[i] = malloc(2 * sizeof(int));
    }
    
    int **to = malloc(N * sizeof(int *));
    int *to_size = calloc(N, sizeof(int));
    
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--;
        B--;
        edges[i][0] = B;
        edges[i][1] = A;
        to_size[A]++;
        to_size[B]++;
    }
    
    for (int i = 0; i < N; i++) {
        to[i] = malloc(to_size[i] * sizeof(int));
    }
    
    int *current_pos = calloc(N, sizeof(int));
    for (int i = 0; i < N - 1; i++) {
        int A = edges[i][1];
        int B = edges[i][0];
        to[A][current_pos[A]++] = B;
        to[B][current_pos[B]++] = A;
    }
    free(current_pos);
    
    int *dp = calloc(N, sizeof(int));
    rec(0, -1, dp, to, to_size);
    
    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = dp[candidate1] > dp[candidate2] ? candidate2 : candidate1;
        long long a = dp[child];
        long long b = N - a;
        long long term1 = (modpow(2, a) - 1) % mod;
        long long term2 = (modpow(2, b) - 1) % mod;
        long long mul = (term1 * term2) % mod;
        mulsum = (mulsum + mul) % mod;
    }
    
    long long cases = modpow(2, N);
    long long cases_minus_1 = (cases - 1 + mod) % mod;
    long long PN = (mulsum + cases_minus_1) % mod;
    
    long long BN = ( (long long)N * modpow(2, N - 1) ) % mod;
    long long WN = (PN - BN + mod) % mod;
    
    long long inv_cases = modpow(cases, mod - 2);
    long long ans = (WN * inv_cases) % mod;
    
    printf("%ld\n", ans);
    
    free(dp);
    for (int i = 0; i < N; i++) free(to[i]);
    free(to);
    free(to_size);
    for (int i = 0; i < N - 1; i++) free(edges[i]);
    free(edges);
    return 0;
}

int rec(int v, int parent, int *dp, int **to, int *to_size) {
    int res = 1;
    for (int i = 0; i < to_size[v]; i++) {
        int next = to[v][i];
        if (next == parent) continue;
        res += rec(next, v, dp, to, to_size);
    }
    dp[v] = res;
    return res;
}

long long modpow(long long x, long long y) {
    x %= mod;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == .true.) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}
// End of Code
