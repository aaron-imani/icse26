#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list, int initialCapacity) {
    list->array = (int *)malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
}

void add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

int get(ArrayList *list, int index) {
    return list->array[index];
}

void freeArrayList(ArrayList *list) {
    free(list->array);
    free(list);
}

long modpow(long x, long y) {
    if (y == 0) return 1;
    long result = 1;
    x = x % MOD;
    while (y > 0) {
        if (y % 2 == 1) result = (result * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

int rec(int v, int parent, ArrayList *to[], int *dp) {
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
    rec(0, -1, to, dp);

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

    for (int i = 0; i < N; i++) {
        freeArrayList(to[i]);
    }

    return 0;
}
// End of Code
