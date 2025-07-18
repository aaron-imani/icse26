#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

typedef struct {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList *createArrayList() {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (int *)malloc(sizeof(int) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void add(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = value;
}

int *readIntArray(int n) {
    int *array = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % mod;
    long tmp = modpow(x, y / 2);
    return tmp * tmp % mod;
}

int rec(ArrayList **to, int *dp, int v, int parent) {
    int res = 1;
    for (int i = 0; i < to[v]->size; i++) {
        int next = to[v]->data[i];
        if (next == parent) continue;
        res += rec(to, dp, next, v);
    }
    return dp[v] = res;
}

int main() {
    int N;
    scanf("%d", &N);
    ArrayList **to = (ArrayList **)malloc(sizeof(ArrayList *) * N);
    for (int i = 0; i < N; i++) {
        to[i] = createArrayList();
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
    rec(to, dp, 0, -1);
    long mulsum = 0;
    for (int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if (dp[candidate1] > dp[candidate2]) child = candidate2;

        long a = dp[child];
        long b = N - a;

        long mul = (modpow(2, a) - 1) * (modpow(2, b) - 1) % mod;
        mulsum += mul;
        mulsum %= mod;
    }
    long cases = modpow(2, N);

    long PN = (mulsum + (cases - 1 + mod) % mod) % mod;

    long BN = N * modpow(2, N - 1) % mod;

    long WN = (PN - BN + mod) % mod;
    long ans = WN * modpow(cases, mod - 2) % mod;

    printf("%ld\n", ans);

    return 0;
}
// End of Code
