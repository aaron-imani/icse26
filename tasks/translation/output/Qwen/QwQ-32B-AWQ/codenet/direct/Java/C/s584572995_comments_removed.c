#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

long long modpow(long long x, long long y) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y % 2 == 1)
            res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    int edges_count = N - 1;
    int *edgesA = malloc(edges_count * sizeof(int));
    int *edgesB = malloc(edges_count * sizeof(int));

    for (int i = 0; i < edges_count; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        edgesA[i] = A - 1;
        edgesB[i] = B - 1;
    }

    int *degrees = malloc(N * sizeof(int));
    memset(degrees, 0, N * sizeof(int));

    for (int i = 0; i < edges_count; i++) {
        degrees[edgesA[i]]++;
        degrees[edgesB[i]]++;
    }

    int **adj = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        adj[i] = malloc(degrees[i] * sizeof(int));
    }

    int *current_count = malloc(N * sizeof(int));
    memset(current_count, 0, N * sizeof(int));

    for (int i = 0; i < edges_count; i++) {
        int a = edgesA[i];
        int b = edgesB[i];
        adj[a][current_count[a]++] = b;
        adj[b][current_count[b]++] = a;
    }

    int *dp = malloc(N * sizeof(int));
    memset(dp, 0, N * sizeof(int));

    typedef struct {
        int node;
        int parent;
        int processed;
    } StackElement;

    int stack_size = N * 2;
    StackElement *stack = malloc(stack_size * sizeof(StackElement));
    int top = -1;

    StackElement e;
    e.node = 0;
    e.parent = -1;
    e.processed = 0;
    top++;
    stack[top] = e;

    while (top >= 0) {
        StackElement e = stack[top];
        top--;
        if (!e.processed) {
            top++;
            stack[top].node = e.node;
            stack[top].parent = e.parent;
            stack[top].processed = 1;

            int a = e.node;
            int parent_node = e.parent;
            for (int i = 0; i < degrees[a]; i++) {
                int neighbor = adj[a][i];
                if (neighbor != parent_node) {
                    StackElement new_e;
                    new_e.node = neighbor;
                    new_e.parent = a;
                    new_e.processed = 0;
                    top++;
                    if (top >= stack_size) {
                    }
                    stack[top] = new_e;
                }
            }
        } else {
            int a = e.node;
            dp[a] = 1;
            for (int i = 0; i < degrees[a]; i++) {
                int neighbor = adj[a][i];
                if (neighbor != e.parent) {
                    dp[a] += dp[neighbor];
                }
            }
        }
    }

    free(stack);
    free(current_count);
    free(degrees);
    free(edgesA);
    free(edgesB);
    for (int i = 0; i < N; i++) free(adj[i]);
    free(adj);

    long long mulsum = 0;
    for (int i = 0; i < edges_count; i++) {
        int candidate1 = edgesA[i];
        int candidate2 = edgesB[i];
        int child = dp[candidate1] < dp[candidate2] ? candidate1 : candidate2;

        long long a = dp[child];
        long long b = N - a;
        long long term1 = (modpow(2, a) - 1) % mod;
        long long term2 = (modpow(2, b) - 1) % mod;
        long long mul = (term1 * term2) % mod;
        mulsum = (mulsum + mul) % mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long long BN = (N * modpow(2, N - 1)) % mod;
    long long WN = (PN - BN + mod) % mod;
    long long inv_cases = modpow(cases, mod - 2);
    long long ans = (WN * inv_cases) % mod;

    printf("%lld\n", ans);

    free(dp);
    return 0;
} // End of Code
