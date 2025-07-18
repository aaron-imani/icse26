#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long modpow(long long x, long long y) {
    x %= MOD;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    // Read edges and build adjacency lists
    int (*edges)[2] = malloc((N - 1) * sizeof(*edges));
    int *degree = calloc(N, sizeof(int));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[i][0] = a;
        edges[i][1] = b;
        degree[a]++;
        degree[b]++;
    }

    // Allocate adjacency lists
    int **adj = malloc(N * sizeof(int*));
    for (int v = 0; v < N; v++) {
        adj[v] = malloc(degree[v] * sizeof(int));
    }

    int *adj_ptr = calloc(N, sizeof(int));
    for (int i = 0; i < N - 1; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a][adj_ptr[a]++] = b;
        adj[b][adj_ptr[b]++] = a;
    }
    free(adj_ptr);

    // DP array
    int *dp = calloc(N, sizeof(int));

    // Iterative post-order traversal
    typedef struct {
        int v;
        int parent;
        int visited;
    } StackElement;
    const int max_stack_size = 2 * N;
    StackElement *stack = malloc(max_stack_size * sizeof(StackElement));
    int top = 0;

    stack[top].v = 0;
    stack[top].parent = -1;
    stack[top].visited = 0;
    top++;

    while (top > 0) {
        top--;
        StackElement e = stack[top];
        if (e.visited == 0) {
            stack[top].visited = 1;
            for (int i = 0; i < degree[e.v]; i++) {
                int u = adj[e.v][i];
                if (u != e.parent) {
                    if (top + 1 >= max_stack_size) {
                        exit(1);
                    }
                    stack[top].v = u;
                    stack[top].parent = e.v;
                    stack[top].visited = 0;
                    top++;
                }
            }
        } else {
            dp[e.v] = 1;
            for (int i = 0; i < degree[e.v]; i++) {
                int u = adj[e.v][i];
                if (u != e.parent) {
                    dp[e.v] += dp[u];
                }
            }
        }
    }
    free(stack);

    // Compute mulsum
    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int a = edges[i][0], b = edges[i][1];
        int candidate1 = a, candidate2 = b;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        }
        long long d = dp[child];
        long long other = N - d;
        long long term1 = (modpow(2LL, d) - 1LL) % MOD;
        long long term2 = (modpow(2LL, other) - 1LL) % MOD;
        long long mul = (term1 * term2) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    // Compute cases
    long long cases = modpow(2LL, N) % MOD;

    long long PN = (mulsum + (cases - 1LL) % MOD) % MOD;
    if (PN < 0) PN += MOD;

    long long BN = ( (long long) N * modpow(2LL, N - 1) ) % MOD;

    long long WN = (PN - BN + MOD) % MOD;

    long long inv_cases = modpow(cases, MOD - 2) % MOD;
    long long ans = (WN * inv_cases) % MOD;

    printf("%lld\n", ans % MOD);

    // Free memory
    for (int v = 0; v < N; v++) free(adj[v]);
    free(adj);
    free(edges);
    free(dp);
    free(degree);

    return 0;
}

// End of Code
