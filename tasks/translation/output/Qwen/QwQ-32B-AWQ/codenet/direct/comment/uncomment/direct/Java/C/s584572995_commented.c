#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

typedef struct {
    int a;
    int b;
} Edge;

typedef struct {
    int node;
    int parent;
    int visited;
} StackElement;

long modpow(long x, long y) {
    long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y = y / 2;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);

    Edge edges[N-1];
    int count[N];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < N-1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--;
        B--;
        edges[i].a = A;
        edges[i].b = B;
        count[A]++;
        count[B]++;
    }

    int **to = (int **)malloc(N * sizeof(int *));
    int *sizes = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        sizes[i] = count[i];
        to[i] = (int *)malloc(sizes[i] * sizeof(int));
    }

    int *current = (int *)calloc(N, sizeof(int));
    for (int i = 0; i < N-1; i++) {
        int a = edges[i].a;
        int b = edges[i].b;
        to[a][current[a]++] = b;
        to[b][current[b]++] = a;
    }
    free(current);

    int dp[N];
    memset(dp, 0, N * sizeof(int));

    StackElement stack[N];
    int top = -1;
    stack[++top] = (StackElement) {0, -1, 0};

    while (top >= 0) {
        StackElement e = stack[top];
        if (!e.visited) {
            stack[top].visited = 1;
            int node = e.node;
            int parent = e.parent;
            for (int i = 0; i < sizes[node]; i++) {
                int neighbor = to[node][i];
                if (neighbor != parent) {
                    stack[++top] = (StackElement) {neighbor, node, 0};
                }
            }
        } else {
            int node = e.node;
            int sum = 0;
            for (int i = 0; i < sizes[node]; i++) {
                int neighbor = to[node][i];
                if (neighbor != e.parent) {
                    sum += dp[neighbor];
                }
            }
            dp[node] = 1 + sum;
            top--;
        }
    }

    long mulsum = 0;
    for (int i = 0; i < N-1; i++) {
        Edge e = edges[i];
        int a_val = dp[e.a];
        int b_val = dp[e.b];
        int child = a_val < b_val ? e.a : e.b;
        long a = dp[child];
        long b = N - a;
        long term = ((modpow(2, a) - 1) % mod) * ((modpow(2, b) - 1) % mod) % mod;
        mulsum = (mulsum + term) % mod;
    }

    long cases = modpow(2, N);
    long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long BN = ((long)N * modpow(2, N-1)) % mod;
    long WN = (PN - BN + mod) % mod;
    long invcases = modpow(cases, mod-2);
    long ans = (WN * invcases) % mod;

    for (int i = 0; i < N; i++) free(to[i]);
    free(to);
    free(sizes);

    printf("%ld\n", ans);
    return 0;
}
// End of Code
