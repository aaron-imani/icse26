#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (LLONG_MAX / 2)
#define MOD 1000000007
#define SIZE 1000000

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long mod_inverse(long a, long m) {
    long m0 = m, t, q;
    long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long mod_pow(long a, long r, long m) {
    long res = 1;
    a = a % m;
    while (r > 0) {
        if (r & 1) res = (res * a) % m;
        r = r >> 1;
        a = (a * a) % m;
    }
    return res;
}

void init_comb() {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long mod_comb(int n, int r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

int is_prime(long a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int next_permutation(int *a, int n) {
    int i, j;
    for (i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            break;
        }
    }
    if (i < 0) return 0;
    for (j = n - 1; j > i; j--) {
        if (a[j] > a[i]) {
            break;
        }
    }
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    for (i = i + 1, j = n - 1; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int map[1001] = {0};
    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (map[s] != 0 && map[s] != c) {
            printf("-1\n");
            return 0;
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[10];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != 0 && map[j + 1] != s[j] - '0') || (map[j + 1] == 0 && s[j] - '0' != 0)) {
                if (map[j + 1] == 0 && j == 0 && s[j] - '0' == 1) {
                    continue;
                }
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}

// End of Code
