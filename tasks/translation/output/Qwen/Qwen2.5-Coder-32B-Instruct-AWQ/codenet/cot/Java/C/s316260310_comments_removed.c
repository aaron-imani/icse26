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
    return (numerator * pow(denominator, hp->mod - 2, hp->mod)) % hp->mod;
}

long *get_long_array(Helper *hp, int size) {
    long *ar = (long *)malloc(size * sizeof(long));
    for (int i = 0; i < size; ++i) ar[i] = next_long(hp);
    return ar;
}

int *get_int_array(Helper *hp, int size) {
    int *ar = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) ar[i] = next_int(hp);
    return ar;
}

void shuffle_int_array(int *ar, int size) {
    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        if (r != i) {
            int temp = ar[i];
            ar[i] = ar[r];
            ar[r] = temp;
        }
    }
}

void shuffle_long_array(long *ar, int size) {
    for (int i = 0; i < size; ++i) {
        int r = rand() % size;
        if (r != i) {
            long temp = ar[i];
            ar[i] = ar[r];
            ar[r] = temp;
        }
    }
}

void reverse_int_array(int *ar, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = ar[i];
        ar[i] = ar[size - 1 - i];
        ar[size - 1 - i] = temp;
    }
}

void reverse_long_array(long *ar, int size) {
    for (int i = 0; i < size / 2; ++i) {
        long temp = ar[i];
        ar[i] = ar[size - 1 - i];
        ar[size - 1 - i] = temp;
    }
}

long pow(long base, long exp, long MOD) {
    base %= MOD;
    long ret = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ret;
}

int scan(Helper *hp) {
    int c;
    while ((c = fgetc(hp->in)) <= 32);
    return c;
}

int next_int(Helper *hp) {
    int c, val = 0;
    c = scan(hp);
    bool neg = c == '-';
    if (c == '-' || c == '+') c = scan(hp);
    for (; c >= '0' && c <= '9'; c = scan(hp)) {
        val = (val << 3) + (val << 1) + (c & 15);
    }
    return neg ? -val : val;
}

long next_long(Helper *hp) {
    int c;
    long val = 0;
    c = scan(hp);
    bool neg = c == '-';
    if (c == '-' || c == '+') c = scan(hp);
    for (; c >= '0' && c <= '9'; c = scan(hp)) {
        val = (val << 3) + (val << 1) + (c & 15);
    }
    return neg ? -val : val;
}

void print(Helper *hp, const char *a) {
    fprintf(hp->out, "%s", a);
}

void printsp(Helper *hp, const char *a) {
    print(hp, a);
    print(hp, " ");
}

void println(Helper *hp) {
    fprintf(hp->out, "\n");
}

void println_int(Helper *hp, int a) {
    fprintf(hp->out, "%d\n", a);
}

void println_long(Helper *hp, long a) {
    fprintf(hp->out, "%ld\n", a);
}

void flush(Helper *hp) {
    fflush(hp->out);
}

void solve(Helper *hp, int tc) {
    int i, j, k;

    int N = next_int(hp);
    long K = next_long(hp);
    int *A = get_int_array(hp, N);

    int straight[MAXN], cycle[MAXN];
    bool vis[MAXN];
    for (i = 0; i < N; ++i) vis[i] = false;
    int curr = 0;
    int straight_size = 0, cycle_size = 0;
    while (!vis[curr]) {
        vis[curr] = true;
        straight[straight_size++] = curr;
        curr = A[curr] - 1;
    }

    int st = straight[0];
    while (st != curr) {
        st = A[st] - 1;
    }

    cycle[cycle_size++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straight_size) {
        println_int(hp, straight[K] + 1);
    } else {
        K -= straight_size;
        println_int(hp, cycle[K % cycle_size] + 1);
    }

    free(A);
}

void solve_all(Helper *hp) {
    int tc = 1; // Assuming TESTCASES is false
    for (int tce = 1; tce <= tc; ++tce) {
        solve(hp, tce);
    }
    flush(hp);
}

int main() {
    Helper hp;
    init_helper(&hp, MOD, MAXN);
    solve_all(&hp);
    free(hp.sieve);
    free(hp.primes);
    free(hp.factorial);
    return 0;
}
// End of Code
