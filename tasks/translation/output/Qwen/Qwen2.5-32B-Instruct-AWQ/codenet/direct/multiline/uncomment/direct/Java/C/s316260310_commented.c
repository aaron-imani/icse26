#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    int MOD;
    int MAXN;
    int *sieve;
    int *primes;
    long long *factorial;
} Helper;

Helper *helper_create(int mod, int maxn) {
    Helper *hp = malloc(sizeof(Helper));
    hp->MOD = mod;
    hp->MAXN = maxn;
    hp->sieve = malloc(maxn * sizeof(int));
    hp->primes = malloc(maxn * sizeof(int));
    hp->factorial = malloc(maxn * sizeof(long long));
    memset(hp->sieve, 0, maxn * sizeof(int));
    memset(hp->primes, 0, maxn * sizeof(int));
    memset(hp->factorial, 0, maxn * sizeof(long long));
    return hp;
}

void helper_destroy(Helper *hp) {
    free(hp->sieve);
    free(hp->primes);
    free(hp->factorial);
    free(hp);
}

void set_sieve(Helper *hp) {
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

long long get_factorial(Helper *hp, int n) {
    if (hp->factorial == NULL) set_factorial(hp);
    return hp->factorial[n];
}

long long ncr(Helper *hp, int n, int r) {
    if (r > n) return 0;
    if (hp->factorial == NULL) set_factorial(hp);
    long long numerator = hp->factorial[n];
    long long denominator = hp->factorial[r] * hp->factorial[n - r] % hp->MOD;
    return numerator * pow(denominator, hp->MOD - 2, hp->MOD) % hp->MOD;
}

long long *get_long_array(Helper *hp, int size) {
    long long *ar = malloc(size * sizeof(long long));
    for (int i = 0; i < size; ++i) ar[i] = next_long(hp);
    return ar;
}

int *get_int_array(Helper *hp, int size) {
    int *ar = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) ar[i] = next_int(hp);
    return ar;
}

char **get_string_array(Helper *hp, int size) {
    char **ar = malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) ar[i] = next(hp);
    return ar;
}

char *join_elements(long long *ar, int size) {
    char *sb = malloc(size * 20 * sizeof(char)); // Assuming each number can be up to 20 characters long
    for (int i = 0; i < size; ++i) {
        sprintf(sb + strlen(sb), "%lld ", ar[i]);
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *join_elements_int(int *ar, int size) {
    char *sb = malloc(size * 20 * sizeof(char)); // Assuming each number can be up to 20 characters long
    for (int i = 0; i < size; ++i) {
        sprintf(sb + strlen(sb), "%d ", ar[i]);
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *join_elements_str(char **ar, int size) {
    char *sb = malloc(size * 20 * sizeof(char)); // Assuming each string can be up to 20 characters long
    for (int i = 0; i < size; ++i) {
        strcat(sb, ar[i]);
        strcat(sb, " ");
    }
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_int(int a, int b) {
    return b == 0 ? a : gcd_int(b, a % b);
}

long long max(long long *ar, int size) {
    long long ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret > ar[i] ? ret : ar[i];
    return ret;
}

int max_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret > ar[i] ? ret : ar[i];
    return ret;
}

long long min(long long *ar, int size) {
    long long ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret < ar[i] ? ret : ar[i];
    return ret;
}

int min_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret < ar[i] ? ret : ar[i];
    return ret;
}

long long sum(long long *ar, int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i) sum += ar[i];
    return sum;
}

long long sum_int(int *ar, int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i) sum += ar[i];
    return sum;
}

void shuffle(int *ar, int size) {
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

void shuffle_long(long long *ar, int size) {
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

void reverse(int *ar, int size) {
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

void reverse_long(long long *ar, int size) {
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

long long pow(long long base, long long exp, long long MOD) {
    base %= MOD;
    long long ret = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) ret = ret * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

char *next(Helper *hp) {
    char *sb = malloc(20 * sizeof(char));
    scanf("%s", sb);
    return sb;
}

int next_int(Helper *hp) {
    int val;
    scanf("%d", &val);
    return val;
}

long long next_long(Helper *hp) {
    long long val;
    scanf("%lld", &val);
    return val;
}

void print(Helper *hp, const char *a) {
    printf("%s", a);
}

void printsp(Helper *hp, const char *a) {
    print(hp, a);
    print(hp, " ");
}

void println(Helper *hp) {
    printf("\n");
}

void println_with_value(Helper *hp, const char *a) {
    print(hp, a);
    println(hp);
}

void flush(Helper *hp) {
    fflush(stdout);
}

void solve(Helper *hp) {
    int tc = 1; // Assuming no test cases
    for (int tce = 1; tce <= tc; ++tce) {
        int N = next_int(hp);
        long long K = next_long(hp);
        int *A = get_int_array(hp, N);

        int *straight = malloc(N * sizeof(int));
        int *cycle = malloc(N * sizeof(int));
        int vis[N];
        memset(vis, 0, N * sizeof(int));
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = 1;
            curr = A[curr] - 1;
        }

        int st = 0;
        int idx = 0;
        while (st != curr) {
            straight[idx++] = st;
            st = A[st] - 1;
        }

        idx = 0;
        cycle[idx++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle[idx++] = curr;
            curr = A[curr] - 1;
        }

        if (K < idx) {
            println_with_value(hp, straight[K] + 1);
        } else {
            K -= idx;
            println_with_value(hp, cycle[K % idx] + 1);
        }

        free(straight);
        free(cycle);
        free(A);
    }
}

int main() {
    Helper *hp = helper_create(MOD, MAXN);
    solve(hp);
    helper_destroy(hp);
    return 0;
}
// End of Code
