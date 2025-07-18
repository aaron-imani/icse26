#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
    return list;
}

void resizeArrayList(ArrayList* list, int newCapacity) {
    list->data = (int*)realloc(list->data, newCapacity * sizeof(int));
    list->capacity = newCapacity;
}

void addArrayList(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        resizeArrayList(list, list->capacity == 0 ? 1 : list->capacity * 2);
    }
    list->data[list->size++] = value;
}

int dp[100005];

int rec(int v, int parent, ArrayList** to) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = to[v]->data[i];
        if (next == parent) continue;
        res += rec(next, v, to);
    }
    return dp[v] = res;
}

long long modpow(long long x, long long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % MOD;
    long long tmp = modpow(x, y / 2);
    return tmp * tmp % MOD;
}

int main() {
    int N;
    scanf("%d", &N);

    ArrayList** to = (ArrayList**)malloc(N * sizeof(ArrayList*));
    for (int i = 0; i < N; i++) {
        to[i] = createArrayList();
    }

    int edges[N - 1][2];
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        A--; B--;
        addArrayList(to[A], B);
        addArrayList(to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }

    rec(0, -1, to);

    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;

        long long a = dp[child];
        long long b = N - a;

        long long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % MOD;
        mulsum += mul;
        mulsum %= MOD;
    }

    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long long BN = N * modpow(2, N - 1) % MOD;
    long long WN = (PN - BN + MOD) % MOD;
    long long ans = WN * modpow(cases, MOD - 2) % MOD;

    printf("%lld\n", ans);

    for (int i = 0; i < N; i++) {
        free(to[i]->data);
        free(to[i]);
    }
    free(to);

    return 0;
}

// End of Code
