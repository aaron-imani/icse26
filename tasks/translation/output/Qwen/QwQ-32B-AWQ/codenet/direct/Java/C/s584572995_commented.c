#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

struct adj_node {
    int *list;
    int size;
    int capacity;
};

struct adj_node *adj;
int *dp;

long long pow_mod(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y % 2 == 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y /= 2;
    }
    return res;
}

int rec(int v, int parent) {
    int res = 1;
    struct adj_node *node = &adj[v];
    for (int i = 0; i < node->size; i++) {
        int next = node->list[i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    int edges_count = N - 1;
    int *edges_a = (int*)malloc(edges_count * sizeof(int));
    int *edges_b = (int*)malloc(edges_count * sizeof(int));
    int *degrees = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < edges_count; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges_a[i] = a;
        edges_b[i] = b;
        degrees[a]++;
        degrees[b]++;
    }

    adj = (struct adj_node*)malloc(N * sizeof(struct adj_node));

    for (int i = 0; i < N; i++) {
        adj[i].capacity = degrees[i] + 1;
        adj[i].list = (int*)malloc(adj[i].capacity * sizeof(int));
        adj[i].size = 0;
    }

    for (int i = 0; i < edges_count; i++) {
        int a = edges_a[i];
        int b = edges_b[i];
        adj[a].list[adj[a].size++] = b;
        adj[b].list[adj[b].size++] = a;
    }

    dp = (int*)malloc(N * sizeof(int));

    rec(0, -1);

    long long mulsum = 0;
    for (int i = 0; i < edges_count; i++) {
        int a = edges_a[i];
        int b = edges_b[i];
        int candidate1 = a;
        int candidate2 = b;
        int child;
        if (dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        } else {
            child = candidate1;
        }
        long long a_val = dp[child];
        long long b_val = N - a_val;
        long long term1 = (pow_mod(2, a_val) - 1) % MOD;
        long long term2 = (pow_mod(2, b_val) - 1) % MOD;
        long long mul = (term1 * term2) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    free(edges_a);
    free(edges_b);
    free(degrees);

    long long cases = pow_mod(2, N) % MOD;
    long long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long long BN = ( (long long) N * pow_mod(2, N - 1) ) % MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long inv_cases = pow_mod(cases, MOD - 2) % MOD;
    long long ans = (WN * inv_cases) % MOD;

    printf("%lld\n", ans);

    for (int i = 0; i < N; i++) {
        free(adj[i].list);
    }
    free(adj);
    free(dp);

    return 0;
}
// End of Code
