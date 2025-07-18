#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int **adj;
int *adj_size;
int *dp;
int N;

long modpow(long x, long y);
int rec(int v, int parent);

int main() {
    scanf("%d", &N);

    // Read edges and count the number of edges per node
    typedef struct {
        int a, b;
    } Edge;
    Edge *edges = malloc((N - 1) * sizeof(Edge));
    int *count = calloc(N, sizeof(int));

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[i].a = a;
        edges[i].b = b;
        count[a]++;
        count[b]++;
    }

    // Allocate adjacency lists
    adj = malloc(N * sizeof(int *));
    adj_size = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        adj[i] = malloc(count[i] * sizeof(int));
        adj_size[i] = count[i];
    }

    // Reset pointers to track current positions in adjacency lists
    int *adj_ptr = calloc(N, sizeof(int));

    // Fill adjacency lists
    for (int i = 0; i < N - 1; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        adj[a][adj_ptr[a]++] = b;
        adj[b][adj_ptr[b]++] = a;
    }
    free(adj_ptr);

    // Initialize DP array
    dp = malloc(N * sizeof(int));

    // Compute DP values
    rec(0, -1);

    // Process each edge to compute contributions
    long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        int candidate1 = a;
        int candidate2 = b;
        int child = (dp[candidate1] < dp[candidate2]) ? candidate1 : candidate2;

        long a_val = dp[child];
        long b_val = N - a_val;

        long term1 = (modpow(2, a_val) - 1) % MOD;
        long term2 = (modpow(2, b_val) - 1) % MOD;
        long mul = (term1 * term2) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    // Compute cases = 2^N mod MOD
    long cases = modpow(2, N) % MOD;
    long PN = (mulsum + (cases - 1 + MOD)) % MOD;

    // BN = N * modpow(2, N-1) mod MOD
    long BN = ((long)N % MOD) * modpow(2, N - 1) % MOD;

    // WN = (PN - BN + MOD) % MOD
    long WN = (PN - BN + MOD) % MOD;

    // ans = WN * inv(cases) mod MOD
    long inv_cases = modpow(cases, MOD - 2) % MOD;
    long ans = (WN * inv_cases) % MOD;

    printf("%ld\n", ans);

    // Free allocated memory
    free(count);
    free(edges);
    for (int i = 0; i < N; i++) free(adj[i]);
    free(adj);
    free(adj_size);
    free(dp);

    return 0;
}

long modpow(long x, long y) {
    long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return res % MOD;
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
// End of Code
