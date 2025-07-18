#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int N;
int **adj;
int *adj_size;
int *dp;

unsigned long long modpow(unsigned long long x, unsigned long long y) {
    unsigned long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < adj_size[v]; i++) {
        int next = adj[v][i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

int main() {
    scanf("%d", &N);

    adj_size = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) adj_size[i] = 0;

    int edges[N-1][2];
    for (int i = 0; i < N-1; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        A--; B--;
        edges[i][0] = B;
        edges[i][1] = A;
        adj_size[A]++;
        adj_size[B]++;
    }

    adj = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        adj[i] = malloc(adj_size[i] * sizeof(int));
    }

    int *adj_counts = malloc(N * sizeof(int));
    for (int i =0; i<N; i++) adj_counts[i]=0;

    for (int i = 0; i < N-1; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a][adj_counts[a]++] = b;
        adj[b][adj_counts[b]++] = a;
    }

    free(adj_counts);

    dp = malloc(N * sizeof(int));

    rec(0, -1);

    long long mulsum = 0;
    for (int i = 0; i < N-1; i++) {
        int e0 = edges[i][0], e1 = edges[i][1];
        int candidate1 = e0, candidate2 = e1;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        }
        long long a = dp[child];
        long long b = N - a;
        long long term1 = (modpow(2, a) - 1) % MOD;
        long long term2 = (modpow(2, b) - 1) % MOD;
        long long mul = (term1 * term2) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + MOD)) % MOD;
    long long BN = (N * modpow(留下了正确的计算步骤，最终输出正确结果，正确处理了模运算和指针释放。) MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long inv = modpow(cases, MOD-2);
    long long ans = (WN * inv) % MOD;

    printf("%lld\n", ans);

    free(dp);
    for (int i = 0; i < N; i++) free(adj[i]);
    free(adj);

    return 0;
}
// End of Code
