#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long mod;
    int maxn;
    int *sieve;
    int *primes;
    long *factorial;
    FILE *in;
    FILE *out;
} Helper;

void init_helper(Helper *hp, long mod, int maxn) {
    hp->mod = mod;
    hp->maxn = maxn;
    hp->sieve = (int *)malloc(maxn * sizeof(int));
    hp->primes = (int *)malloc(maxn * sizeof(int));
    hp->factorial = (long *)malloc(maxn * sizeof(long));
    hp->in = stdin;
    hp->out = stdout;
}

void set_sieve(Helper *hp) {
    int i, j;
    for (i = 0; i < hp->maxn; ++i) hp->sieve[i] = 0;
    int prime_count = 0;
    for (i = 2; i < hp->maxn; ++i) {
        if (hp->sieve[i] == 0) {
            hp->primes[prime_count++] = i;
            for (j = i; j < hp->maxn; j += i) {
                hp->sieve[j] = i;
            }
        }
    }
}

void set_factorial(Helper *hp) {
    hp->factorial[0] = 1;
    for (int i = 1; i < hp->maxn; ++i) {
        hp->factorial[i] = (hp->factorial[i - 1] * i) % hp->mod;
    }
}

long get_factorial(Helper *hp, int n) {
    if (hp->factorial == NULL) set_factorial(hp);
    return hp->factorial[n];
}

long ncr(Helper *hp, int n, int r) {
    if (r > n) return 0;
    if (hp->factorial == NULL) set_factorial(hp);
    long numerator = hp->factorial[n];
    long denominator = (hp->factorial[r] * hp->factorial[n - r]) % hp->mod;
    long mod_inv = pow(denominator, hp->mod - 2, hp->mod);
    return (numerator * mod_inv) % hp->mod;
}

long *get_long_array(Helper *hp, int size) {
    long *ar = (long *)malloc(size * sizeof(long));
    for (int i = 0; i < size; ++i) {
        fscanf(hp->in, "%ld", &ar[i]);
    }
    return ar;
}

int *get_int_array(Helper *hp, int size) {
    int *ar = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        fscanf(hp->in, "%d", &ar[i]);
    }
    return ar;
}

void print_array(Helper *hp, long *ar, int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(hp->out, "%ld ", ar[i]);
    }
    fprintf(hp->out, "\n");
}

void print_array_int(Helper *hp, int *ar, int size) {
    for (int i = 0; i < size; ++i) {
        fprintf(hp->out, "%d ", ar[i]);
    }
    fprintf(hp->out, "\n");
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_int(int a, int b) {
    return b == 0 ? a : gcd_int(b, a % b);
}

long max_long(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > ret) ret = ar[i];
    }
    return ret;
}

int max_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > ret) ret = ar[i];
    }
    return ret;
}

long min_long(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] < ret) ret = ar[i];
    }
    return ret;
}

int min_int(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] < ret) ret = ar[i];
    }
    return ret;
}

long sum_long(long *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return sum;
}

long sum_int(int *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return sum;
}

void shuffle_int(int *ar, int size) {
    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        if (r != i) {
            int temp = ar[i];
            ar[i] = ar[r];
            ar[r] = temp;
        }
    }
}

void shuffle_long(long *ar, int size) {
    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        if (r != i) {
            long temp = ar[i];
            ar[i] = ar[r];
            ar[r] = temp;
        }
    }
}

void reverse_int(int *ar, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = ar[i];
        ar[i] = ar[size - 1 - i];
        ar[size - 1 - i] = temp;
    }
}

void reverse_long(long *ar, int size) {
    for (int i = 0; i < size / 2; ++i) {
        long temp = ar[i];
        ar[i] = ar[size - 1 - i];
        ar[size - 1 - i] = temp;
    }
}

long pow_mod(long base, long exp, long MOD) {
    base %= MOD;
    long ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ret;
}

void solve(Helper *hp) {
    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) {
        int N = 0;
        long K = 0;
        fscanf(hp->in, "%d %ld", &N, &K);
        int *A = get_int_array(hp, N);

        int straight[MAXN], cycle[MAXN];
        bool vis[MAXN];
        for (int i = 0; i < N; ++i) vis[i] = false;

        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
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
            fprintf(hp->out, "%d\n", straight[K] + 1);
        } else {
            K -= straight_size;
            fprintf(hp->out, "%d\n", cycle[K % cycle_size] + 1);
        }

        free(A);
    }
}

int main() {
    Helper hp;
    init_helper(&hp, MOD, MAXN);
    set_sieve(&hp);
    solve(&hp);
    return 0;
}
// End of Code
