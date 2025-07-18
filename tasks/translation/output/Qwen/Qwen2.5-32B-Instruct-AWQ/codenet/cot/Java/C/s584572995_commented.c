#include <stdio.h>
#include <stdlib.h>

#define mod 1000000007
int N;
int to[100000];
int dp[100000];
int edges[100000][2];

int rec(int v, int parent) {
    int res = 1;
    for (int i = 0; i < to[v]; i++) {
        int next = to[v * 100000 + i];
        if (next == parent) continue;
        res += rec(next, v);
    }
    return dp[v] = res;
}

long modpow(long x, long y) {
    if (y == 0) return 1;
    if (y % 2 != 0) return x * modpow(x, y - 1) % mod;
    long tmp = modpow(x, y / 2);
    return tmp * tmp % mod;
}

int main() {
    int A, B;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) to[i] = 0;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &A, &B);
        A--; B--;
        to[A * 100000 + to[A]] = B;
        to[B * 100000 + to[B]] = A;
        edges[i][0] = B;
        edges[i][1] = A;
        to[A]++; to[B]++;
    }
    for (int i = 0; i < N; i++) dp[i] = 0;
    rec(0, -1);
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
