#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long MOD;
    int MAXN;
    int *sieve;
    int *primes;
    long *factorial;
} Helper;

Helper *helper_init(long mod, int maxn) {
    Helper *hp = malloc(sizeof(Helper));
    hp->MOD = mod;
    hp->MAXN = maxn;
    hp->sieve = malloc(maxn * sizeof(int));
    hp->primes = malloc(maxn * sizeof(int));
    hp->factorial = malloc(maxn * sizeof(long));
    return hp;
}

void set_sieve(Helper *hp) {
    memset(hp->sieve, 0, hp->MAXN * sizeof(int));
    int i, j;
    for (i = 2; i < hp->MAXN; ++i)
        if (hp->sieve[i] == 0) {
            hp->primes[i] = i;
            for (j = i; j < hp->MAXN; j += i) {
                hp->sieve[j] = i;
            }
        }
}

void set_factorial(Helper *hp) {
    hp->factorial[0] = 1;
    for (int i = 1; i < hp->MAXN; ++i)
        hp->factorial[i] = hp->factorial[i - 1] * i % hp->MOD;
}

long get_factorial(Helper *hp, int n) {
    if (hp->factorial == NULL) set_factorial(hp);
    return hp->factorial[n];
}

long ncr(Helper *hp, int n, int r) {
    if (r > n) return 0;
    if (hp->factorial == NULL) set_factorial(hp);
    long numerator = hp->factorial[n];
    long denominator = hp->factorial[r] * hp->factorial[n - r] % hp->MOD;
    return numerator * pow(denominator, hp->MOD - 2, hp->MOD) % hp->MOD;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long max(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i)
        ret = (ret > ar[i]) ? ret : ar[i];
    return ret;
}

long min(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i)
        ret = (ret < ar[i]) ? ret : ar[i];
    return ret;
}

long sum(long *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += ar[i];
    return sum;
}

long pow(long base, long exp, long MOD) {
    base %= MOD;
    long ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = ret * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

int *get_int_array(Helper *hp, int size) {
    int *ar = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
        scanf("%d", &ar[i]);
    return ar;
}

void print(Helper *hp, char *str) {
    printf("%s", str);
}

void println(Helper *hp, char *str) {
    printf("%s\n", str);
}

void flush(Helper *hp) {
    fflush(stdout);
}

void solve(Helper *hp) {
    int tc = 1; // Assuming no test cases
    for (int tce = 1; tce <= tc; ++tce) {
        int N;
        long K;
        scanf("%d %ld", &N, &K);
        int *A = get_int_array(hp, N);

        int *straight = malloc(N * sizeof(int));
        int *cycle = malloc(N * sizeof(int));
        int *vis = malloc(N * sizeof(int));
        memset(vis, 0, N * sizeof(int));

        int curr = 0;
        int idx = 0;
        while (!vis[curr]) {
            vis[curr] = 1;
            straight[idx++] = curr;
            curr = A[curr] - 1;
        }

        int st = 0;
        while (st != curr) {
            straight[idx++] = st;
            st = A[st] - 1;
        }

        int cycle_idx = 0;
        cycle[cycle_idx++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle[cycle_idx++] = curr;
            curr = A[curr] - 1;
        }

        if (K < idx) {
            println(hp, straight[K] + 1);
        } else {
            K -= idx;
            println(hp, cycle[K % cycle_idx] + 1);
        }

        free(straight);
        free(cycle);
        free(vis);
        free(A);
    }
}

int main() {
    Helper *hp = helper_init(MOD, MAXN);
    set_sieve(hp);
    solve(hp);
    flush(hp);
    free(hp->sieve);
    free(hp->primes);
    free(hp->factorial);
    free(hp);
    return 0;
}
// End of Code
