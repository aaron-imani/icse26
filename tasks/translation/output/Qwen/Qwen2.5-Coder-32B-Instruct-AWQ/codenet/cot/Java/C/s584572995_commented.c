#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int mod = MOD;
int **to;
int *dp;

int modpow(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 != 0) res = (res * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = to[v]->array[i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    return dp[v] = res;
}

typedef struct {
    int *array;
    int size;
    int capacity;
} ArrayList;

void ArrayList_init(ArrayList *list, int initialCapacity) {
    list->array = (int *)malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
}

void ArrayList_add(ArrayList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (int *)realloc(list->array, list->capacity * sizeof(int));
    }
    list->array[list->size++] = element;
}

void ArrayList_free(ArrayList *list) {
    free(list->array);
}

int nextInt(FILE *file) {
    int num;
    fscanf(file, "%d", &num);
    return num;
}

int main() {
    FILE *file = stdin;
    int N = nextInt(file);
    to = (int **)malloc(N * sizeof(int *));
    dp = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        ArrayList_init(&to[i], 10);
    }
    int edges[N - 1][2];
    for (int i = 0; i < N - 1; i++) {
        int A = nextInt(file) - 1, B = nextInt(file) - 1;
        ArrayList_add(&to[A], B);
        ArrayList_add(&to[B], A);
        edges[i][0] = B;
        edges[i][1] = A;
    }
    rec(0, -1);
    long long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;
        long long a = dp[child];
        long long b = N - a;
        long long mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % mod;
        mulsum += mul;
        mulsum %= mod;
    }
    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long long BN = (N * modpow(2, N - 1)) % mod;
    long long WN = (PN - BN + mod) % mod;
    long long ans = (WN * modpow(cases, mod - 2)) % mod;
    printf("%lld\n", ans);

    for (int i = 0; i < N; i++) {
        ArrayList_free(&to[i]);
    }
    free(to);
    free(dp);
    return 0;
}
// End of Code
