#include <stdio.h>
#include <stdlib.h>

#define INF 9223372036854775807 / 2
#define MOD 1000000007
#define SIZE 1000000

typedef struct {
    long a, b;
} Pair;

int compare_pairs(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    if (pa.b < pb.b) return -1;
    else if (pa.b > pb.b) return 1;
    else return 0;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long pow_mod(long a, long r) {
    long sum = 1;
    while (r > 0) {
        if (r & 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return sum;
}

long mod_fact(long n) {
    if (n == 0) return 1;
    return n * mod_fact(n - 1) % MOD;
}

long fact(long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void init_comb(long *fac, long *inv, long *finv) {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long mod_comb(int n, int r, long *fac, long *finv) {
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

void next_permutation(char *s) {
    int len = strlen(s);
    int pivot_pos = -1;
    char pivot = 0;
    for (int i = len - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            pivot_pos = i;
            pivot = s[i];
            break;
        }
    }

    if (pivot_pos == -1 && pivot == 0) {
        s[0] = '\0';
        return;
    }

    int L = pivot_pos + 1;
    int R = len - 1;
    int min_pos = -1;
    char min_val = 127;
    for (int i = R; i >= L; i--) {
        if (pivot < s[i]) {
            if (s[i] < min_val) {
                min_val = s[i];
                min_pos = i;
            }
        }
    }

    char temp = s[pivot_pos];
    s[pivot_pos] = s[min_pos];
    s[min_pos] = temp;

    qsort(s + L, R - L + 1, sizeof(char), (int (*)(const void *, const void *))strcmp);
}

int find(long dest, long *a, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
}

void elimination(int **a, int *b, int n) {
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = -a[i][k] / (double)a[k][k];
            for (int j = k + 1; j < n; j++) {
                a[i][j] += f * a[k][j];
            }
            b[i] += f * b[k];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                b[i] -= a[i][j] * b[j];
            }
            b[i] = b[i] / a[i][i];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *map = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) map[i] = -1;

    for (int i = 0; i < m; i++) {
        int s, c;
        scanf("%d %d", &s, &c);
        if (map[s] != -1 && map[s] != c) {
            printf("-1\n");
            free(map);
            return 0;
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[11];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != -1 && map[j + 1] != s[j] - '0') || (map[j + 1] == -1 && s[j] - '0' != 0)) {
                if (map[j + 1] == -1 && j == 0 && s[j] - '0' == 1) continue;
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            free(map);
            return 0;
        }
    }

    printf("-1\n");
    free(map);
    return 0;
}

// End of Code
