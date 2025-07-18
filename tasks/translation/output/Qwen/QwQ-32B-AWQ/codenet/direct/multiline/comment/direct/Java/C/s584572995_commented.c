#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

struct Edge {
    int a, b;
};

long long modpow(long long x, long long y) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    int **adj = (int**)malloc(N * sizeof(int*));
    int *adj_size = (int*)calloc(N, sizeof(int));
    int *adj_cap = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        adj[i] = NULL;
        adj_size[i] = 0;
        adj_cap[i] = 0;
    }

    struct Edge *edges = (struct Edge*)malloc((N - 1) * sizeof(struct Edge));
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--;
        B--;
        edges[i].a = B;
        edges[i].b = A;

        if (adj_size[A] >= adj_cap[A]) {
            adj_cap[A] = adj_cap[A] == 0 ? 1 : adj_cap[A] * 2;
            adj[A] = (int*)realloc(adj[A], adj_cap[A] * sizeof(int));
        }
        adj[A][adj_size[A]++] = B;

        if (adj_size[B] >= adj_cap[B]) {
            adj_cap[B] = adj_cap[B] == 0 ? 1 : adj_cap[B] * 2;
            adj[B] = (int*)realloc(adj[B], adj_cap[B] * sizeof(int));
        }
        adj[B][adj_size[B]++] = A;
    }

    int dp[N];
    memset(dp, 0, N * sizeof(int));

    typedef struct {
        int v;
        int parent;
        int visited;
    } StackElement;

    int stack_capacity = 16;
    StackElement *stack = (StackElement*)malloc(stack_capacity * sizeof(StackElement));
    int stack_size = 0;

    stack[stack_size].v = 0;
    stack[stack_size].parent = -1;
    stack[stack_size].visited = 0;
    stack_size++;

    while (stack_size > 0) {
        StackElement current = stack[stack_size - 1];
        stack_size--;
        if (!current.visited) {
            if (stack_size >= stack_capacity) {
                stack_capacity *= 2;
                stack = (StackElement*)realloc(stack, stack_capacity * sizeof(StackElement));
            }
            stack[stack_size].v = current.v;
            stack[stack_size].parent = current.parent;
            stack[stack_size].visited = 1;
            stack_size++;

            for (int i = 0; i < adj_size[current.v]; i++) {
                int next = adj[current.v][i];
                if (next != current.parent) {
                    if (stack_size >= stack_capacity) {
                        stack_capacity *= 2;
                        stack = (StackElement*)realloc(stack, stack_capacity * sizeof(StackElement));
                    }
                    stack[stack_size].v = next;
                    stack[stack_size].parent = current.v;
                    stack[stack_size].visited = 0;
                    stack_size++;
                }
            }
        } else {
            dp[current.v] = 1;
            for (int i = 0; i < adj_size[current.v]; i++) {
                int next = adj[current.v][i];
                if (next != current.parent) {
                    dp[current.v] += dp[next];
                }
            }
        }
    }

    free(stack);

    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        struct Edge e = edges[i];
        int candidate1 = e.a;
        int candidate2 = e.b;
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        }

        long long a = dp[child];
        long long b = N - a;

        long long term = ((modpow(2, a) - 1) % mod) * ((modpow(2, b) - 1) % mod) % mod;
        term = term < 0 ? term + mod : term;
        mulsum = (mulsum + term) % mod;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod)) % mod;
    PN %= mod;

    long long BN = ( (long long)N * modpow(2, N - 1) ) % mod;

    long long WN = (PN - BN + mod) % mod;

    long long inv_cases = modpow(cases, mod - 2);
    long long ans = (WN * inv_cases) % mod;

    printf("%lld\n", ans);

    for (int i = 0; i < N; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adj_size);
    free(adj_cap);
    free(edges);

    return 0;
}

// End of Code
