#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->array = (int *)malloc(10 * sizeof(int));
    list->size = 0;
    list->capacity = 10;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = value;
}

void freeArrayList(ArrayList *list) {
    free(list->array);
}

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return (x * modpow(x, y - 1)) % MOD;
    long tmp = modpow(x, y / 2);
    return (tmp * tmp) % MOD;
}

int rec(int v, int parent, ArrayList *to[], int *dp) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = to[v]->array[i];
        if (next == parent) continue;
        res += rec(next, v, to, dp);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);
    ArrayList *to[N];
    for (int i = 0; i < N; i++) {
        to[i] = (ArrayList *)malloc(sizeof(ArrayList));
        initArrayList(to[i]);
    }
    int edges[N - 1][2];
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        A--; B--;
        add(to[A], B);
        add(to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }
    int dp[N];
    rec(0, -1, to, dp);
    long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
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
    long BN = (N * modpow(2, N - 1)) % MOD;
    long WN = (PN - BN + MOD) % MOD;
    long ans = (WN * modpow(cases, MOD - 2)) % MOD;
    printf("%ld\n", ans);
    for (int i = 0; i < N; i++) {
        freeArrayList(to[i]);
        free(to[i]);
    }
    return 0;
}
// End of Code
