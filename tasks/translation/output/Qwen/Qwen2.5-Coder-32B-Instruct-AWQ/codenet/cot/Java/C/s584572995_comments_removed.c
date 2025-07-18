#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int mod = MOD;
int **to;
int *dp;

int nextInt(FILE *fp) {
    int n;
    fscanf(fp, "%d", &n);
    return n;
}

long modpow(long x, long y) {
    if(y == 0) return 1;
    if(y % 2 != 0) return (x * modpow(x, y - 1)) % mod;
    long tmp = modpow(x, y / 2);
    return (tmp * tmp) % mod;
}

int rec(int v, int parent) {
    int res = 1;
    for(int i = 0; i < to[v]->size; i++) {
        int next = to[v]->array[i];
        if(next == parent) continue;
        res += rec(next, v);
    }
    return dp[v] = res;
}

int main() {
    FILE *fp = stdin;
    int N = nextInt(fp);
    to = (int **)malloc(N * sizeof(int *));
    dp = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        to[i] = (int *)malloc(N * sizeof(int));
        to[i]->size = 0;
    }
    int **edges = (int **)malloc((N - 1) * sizeof(int *));
    for(int i = 0; i < N - 1; i++) {
        edges[i] = (int *)malloc(2 * sizeof(int));
        int A = nextInt(fp) - 1, B = nextInt(fp) - 1;
        to[A]->array[to[A]->size++] = B;
        to[B]->array[to[B]->size++] = A;
        edges[i][0] = B;
        edges[i][1] = A;
    }
    rec(0, -1);
    long mulsum = 0;
    for(int i = 0; i < N - 1; i++) {
        int candidate1 = edges[i][0];
        int candidate2 = edges[i][1];
        int child = candidate1;
        if(dp[candidate1] > dp[candidate2]) child = candidate2;
        long a = dp[child];
        long b = N - a;
        long mul = ((modpow(2, a) - 1) * (modpow(2, b) - 1)) % mod;
        mulsum += mul;
        mulsum %= mod;
    }
    long cases = modpow(2, N);
    long PN = (mulsum + (cases - 1 + mod) % mod) % mod;
    long BN = N * modpow(2, N - 1) % mod;
    long WN = (PN - BN + mod) % mod;
    long ans = WN * modpow(cases, mod - 2);
    ans %= mod;
    printf("%ld\n", ans);
    // Free allocated memory
    for(int i = 0; i < N; i++) {
        free(to[i]);
    }
    free(to);
    free(dp);
    for(int i = 0; i < N - 1; i++) {
        free(edges[i]);
    }
    free(edges);
    return 0;
}

// Custom array structure to mimic Java's ArrayList
typedef struct {
    int *array;
    int size;
} IntArray;

IntArray *createIntArray(int capacity) {
    IntArray *arr = (IntArray *)malloc(sizeof(IntArray));
    arr->array = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    return arr;
}

void addToArray(IntArray *arr, int value) {
    arr->array[arr->size++] = value;
}
// End of Code
