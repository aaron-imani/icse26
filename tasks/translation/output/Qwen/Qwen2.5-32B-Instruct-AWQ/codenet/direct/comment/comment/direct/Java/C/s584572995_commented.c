#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *data;
    size_t used;
    size_t size;
} ArrayList;

ArrayList *createArrayList() {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->data = NULL;
    list->used = 0;
    list->size = 0;
    return list;
}

void arrayListAdd(ArrayList *list, int value) {
    if (list->used == list->size) {
        list->size = list->size == 0 ? 1 : list->size * 2;
        list->data = realloc(list->data, list->size * sizeof(int));
    }
    list->data[list->used++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->data);
    free(list);
}

int modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % MOD;
    long tmp = modpow(x, y / 2);
    return tmp * tmp % MOD;
}

int rec(ArrayList **to, int dp[], int v, int parent) {
    int res = 1;
    for (size_t i = 0; i < to[v]->used; ++i) {
        int next = to[v]->data[i];
        if (next == parent) continue;
        res += rec(to, dp, next, v);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);

    ArrayList **to = malloc(N * sizeof(ArrayList *));
    for (int i = 0; i < N; ++i) {
        to[i] = createArrayList();
    }

    int edges[N - 1][2];
    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        scanf("%d%d", &A, &B);
        --A;
        --B;
        arrayListAdd(to[A], B);
        arrayListAdd(to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }

    int dp[N];
    rec(to, dp, 0, -1);

    long mulsum = 0;
    for (int i = 0; i < N - 1; ++i) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;

        long a = dp[child];
        long b = N - a;

        long mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % MOD;
        mulsum += mul;
        mulsum %= MOD;
    }

    long cases = modpow(2, N);
    long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long BN = N * modpow(2, N - 1) % MOD;
    long WN = (PN - BN + MOD) % MOD;
    long ans = WN * modpow(cases, MOD - 2) % MOD;

    printf("%ld\n", ans);

    for (int i = 0; i < N; ++i) {
        freeArrayList(to[i]);
    }
    free(to);

    return 0;
}

// End of Code
