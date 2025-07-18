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
    int factorial_set;
} Helper;

Helper *helper_create(long mod, int maxn) {
    Helper *hp = (Helper *)malloc(sizeof(Helper));
    hp->MOD = mod;
    hp->MAXN = maxn;
    hp->sieve = (int *)malloc(maxn * sizeof(int));
    hp->primes = (int *)malloc(maxn * sizeof(int));
    hp->factorial = (long *)malloc(maxn * sizeof(long));
    hp->factorial_set = 0;
    return hp;
}

void helper_destroy(Helper *hp) {
    free(hp->sieve);
    free(hp->primes);
    free(hp->factorial);
    free(hp);
}

void helper_set_sieve(Helper *hp) {
    memset(hp->sieve, 0, hp->MAXN * sizeof(int));
    int i, j;
    for (i = 2; i < hp->MAXN; ++i) {
        if (hp->sieve[i] == 0) {
            hp->primes[i] = i;
            for (j = i; j < hp->MAXN; j += i) {
                hp->sieve[j] = i;
            }
        }
    }
}

void helper_set_factorial(Helper *hp) {
    hp->factorial[0] = 1;
    for (int i = 1; i < hp->MAXN; ++i) {
        hp->factorial[i] = hp->factorial[i - 1] * i % hp->MOD;
    }
    hp->factorial_set = 1;
}

long helper_get_factorial(Helper *hp, int n) {
    if (!hp->factorial_set) {
        helper_set_factorial(hp);
    }
    return hp->factorial[n];
}

long helper_ncr(Helper *hp, int n, int r) {
    if (r > n) return 0;
    if (!hp->factorial_set) {
        helper_set_factorial(hp);
    }
    long numerator = hp->factorial[n];
    long denominator = hp->factorial[r] * hp->factorial[n - r] % hp->MOD;
    return numerator * pow(denominator, hp->MOD - 2, hp->MOD) % hp->MOD;
}

long *helper_get_long_array(Helper *hp, int size) {
    long *ar = (long *)malloc(size * sizeof(long));
    for (int i = 0; i < size; ++i) {
        ar[i] = nextLong();
    }
    return ar;
}

int *helper_get_int_array(Helper *hp, int size) {
    int *ar = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        ar[i] = nextInt();
    }
    return ar;
}

char **helper_get_string_array(Helper *hp, int size) {
    char **ar = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) {
        ar[i] = next();
    }
    return ar;
}

char *helper_join_elements(long *ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) {
        sprintf(sb + strlen(sb), "%ld ", ar[i]);
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *helper_join_elements_int(int *ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) {
        sprintf(sb + strlen(sb), "%d ", ar[i]);
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *helper_join_elements_string(char **ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) {
        sprintf(sb + strlen(sb), "%s ", ar[i]);
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

long helper_gcd(long a, long b) {
    return b == 0 ? a : helper_gcd(b, a % b);
}

int helper_gcd_int(int a, int b) {
    return b == 0 ? a : helper_gcd_int(b, a % b);
}

long helper_max(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) {
        ret = ret > ar[i] ? ret : ar[i];
    }
    return ret;
}

int helper_max_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) {
        ret = ret > ar[i] ? ret : ar[i];
    }
    return ret;
}

long helper_min(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) {
        ret = ret < ar[i] ? ret : ar[i];
    }
    return ret;
}

int helper_min_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) {
        ret = ret < ar[i] ? ret : ar[i];
    }
    return ret;
}

long helper_sum(long *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return sum;
}

long helper_sum_int(int *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return sum;
}

void helper_shuffle_int(int *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = rand() % size;
        if (r != i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void helper_shuffle_long(long *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = rand() % size;
        if (r != i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void helper_reverse_int(int *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = size - 1 - i;
        if (r > i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void helper_reverse_long(long *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = size - 1 - i;
        if (r > i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

long helper_pow(long base, long exp, long MOD) {
    base %= MOD;
    long ret = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) {
            ret = ret * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

char *next() {
    char *str = (char *)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int nextInt() {
    int val;
    scanf("%d", &val);
    return val;
}

long nextLong() {
    long val;
    scanf("%ld", &val);
    return val;
}

void printsp(long a) {
    printf("%ld ", a);
}

void println(long a) {
    printf("%ld\n", a);
}

void flush() {
    // No-op in C
}

void solve(Helper *hp) {
    int tc = 1; // Assuming no test cases
    for (int tce = 1; tce <= tc; ++tce) {
        solve_tce(hp, tce);
    }
}

void solve_tce(Helper *hp, int tc) {
    int N = nextInt();
    long K = nextLong();
    int *A = helper_get_int_array(hp, N);

    int *straight = (int *)malloc(N * sizeof(int));
    int *cycle = (int *)malloc(N * sizeof(int));
    int *vis = (int *)malloc(N * sizeof(int));
    memset(vis, 0, N * sizeof(int));
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }

    int st = 0;
    int straight_size = 0;
    while (st != curr) {
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    int cycle_size = 0;
    cycle[cycle_size++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straight_size) {
        println(straight[K] + 1);
    } else {
        K -= straight_size;
        println(cycle[K % cycle_size] + 1);
    }

    free(straight);
    free(cycle);
    free(vis);
    free(A);
}

int main() {
    Helper *hp = helper_create(MOD, MAXN);
    solve(hp);
    helper_destroy(hp);
    return 0;
}
// End of Code
