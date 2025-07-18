#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

struct Edge {
    int a, b;
};

struct AdjList {
    int *nodes;
    int size;
};

struct Edge *edges = NULL;
struct AdjList *adj = NULL;
int *dp = NULL;
int N;

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < adj[v].size; i++) {
        int next = adj[v].nodes[i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    dp[v] = res;
    return res;
}

unsigned long long modpow(unsigned long long x, unsigned long long y) {
    unsigned long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    scanf("%d", &N);

    edges = malloc((N-1)*sizeof(struct Edge));
    for (int i = 0; i < N-1; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        A--;
        B--;
        edges[i].a = B;
        edges[i].b = A;
    }

    int *count = malloc(N * sizeof(int));
    memset(count, 0, N * sizeof(int));

    for (int i = 0; i < N-1; i++) {
        struct Edge e = edges[i];
        count[e.a]++;
        count[e.b]++;
    }

    adj = malloc(N * sizeof(struct AdjList));
    for (int v = 0; v < N; v++) {
        adj[v].size = count[v];
        adj[v].nodes = malloc(adj[v].size * sizeof(int));
    }

    int *index = malloc(N * sizeof(int));
    memset(index, 0, N * sizeof(int));

    for (int i = 0; i < N-1; i++) {
        struct Edge e = edges[i];
        adj[e.a].nodes[index[e.a]++] = e.b;
        adj[e.b].nodes[index[e.b]++] = e.a;
    }

    dp = malloc(N * sizeof(int));

    rec(0, -1);

    unsigned long long mulsum = 0;
    for (int i = 0; i < N-1; i++) {
        struct Edge e = edges[i];
        int cand1 = e.a;
        int cand2 = e.b;

        int child;
        if (dp[cand1] > dp[cand2]) {
            child = cand2;
        } else {
            child = cand1;
        }

        unsigned long long a = dp[child];
        unsigned long long b = N - a;

        unsigned long long powa = modpow(2, a);
        unsigned long long powb = modpow(2, b);
        unsigned long long term = ( (powa - 1) * (powb - 1) ) % MOD;
        mulsum = (mulsum + term) % MOD;
    }

    unsigned long long cases = modpow(2, N);
    unsigned long long PN = (mulsum + (cases - 1 + MOD)) % MOD;

    unsigned long long BN = ( (unsigned long long) N * modpow(2, N-1) ) % MOD;

    unsigned long long WN = (PN - BN + MOD) % MOD;

    unsigned long long inv = modpow(cases, MOD-2);
    unsigned long long ans = (WN * inv) % MOD;

    printf("%llu\n", ans);

    return 0;
}
// End of Code
