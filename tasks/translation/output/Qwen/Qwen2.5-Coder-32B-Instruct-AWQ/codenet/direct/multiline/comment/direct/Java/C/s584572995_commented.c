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

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return (x * modpow(x, y - 1)) % MOD;
    long tmp = modpow(x, y / 2);
    return (tmp * tmp) % MOD;
}

int rec(ArrayList *to[], int v, int parent, int dp[]) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = to[v]->elements[i];
        if (next == parent) continue;
        res += rec(to, next, v, dp);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);

    ArrayList *to[N];
    for (int i = 0; i < N; i++) {
        to[i] = (ArrayList *)malloc(sizeof(ArrayList));
        initArrayList(to[i], 10);
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
    rec(to, 0, -1, dp);

    long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = (dp[candidate1] > dp[candidate2]) ? candidate2 : candidate1;

        long a = dp[child];
        long b = N - a;

        long mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % MOD;
        mulsum = (mulsum + mul) % MOD;
    }

    long cases = modpow(2, N);
    long PN = (mulsum + (cases - 1 + MOD) % MOD) % MOD;
    long BN = (N * modpow(2, N - 1)) % MOD;
    long WN = (PN - BN + MOD) % MOD;
    long ans = (WN * modpow(cases, MOD - 2)) % MOD;

    printf("%ld\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(to[i]->elements);
        free(to[i]);
    }

    return 0;
}
// End of Code
