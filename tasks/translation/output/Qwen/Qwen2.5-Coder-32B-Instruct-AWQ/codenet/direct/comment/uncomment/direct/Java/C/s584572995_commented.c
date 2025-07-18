#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int size;
    int capacity;
    int *elements;
} ArrayList;

void initArrayList(ArrayList *list, int initialCapacity) {
    list->size = 0;
    list->capacity = initialCapacity;
    list->elements = (int *)malloc(initialCapacity * sizeof(int));
}

void add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->elements = (int *)realloc(list->elements, list->capacity * sizeof(int));
    }
    list->elements[list->size++] = element;
}

int get(ArrayList *list, int index) {
    return list->elements[index];
}

void freeArrayList(ArrayList *list) {
    free(list->elements);
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return (x * modpow(x, y - 1)) % MOD;
    long long tmp = modpow(x, y / 2);
    return (tmp * tmp) % MOD;
}

int rec(int v, int parent, ArrayList **to, int *dp) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = get(to[v], i);
        if (next == parent) continue;
        res += rec(next, v, to, dp);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);

    ArrayList **to = (ArrayList **)malloc(N * sizeof(ArrayList *));
    for (int i = 0; i < N; i++) {
        initArrayList(&to[i], 10);
    }

    int edges[N - 1][2];
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--; B--;
        add(&to[A], B);
        add(&to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }

    int *dp = (int *)malloc(N * sizeof(int));
    rec(0, -1, to, dp);

    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;

        long long a = dp[child];
        long long b = N - a;

        long long mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long long BN = (N * modpow(2, N - 1)) % MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long ans = (WN * modpow(cases, MOD - 2)) % MOD;

    printf("%lld\n", ans);

    for (int i = 0; i < N; i++) {
        freeArrayList(&to[i]);
    }
    free(to);
    free(dp);

    return 0;
}
// End of Code
