#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long long MOD;
    int MAXN;
} Helper;

Helper* createHelper(long long mod, int maxn) {
    Helper* hp = (Helper*)malloc(sizeof(Helper));
    if (!hp) return NULL;
    hp->MOD = mod;
    hp->MAXN = maxn;
    return hp;
}

void setSieve(int* sieve, int* primes, int maxn) {
    int i, j, primeCount = 0;
    for (i = 2; i < maxn; ++i) {
        if (sieve[i] == 0) {
            primes[primeCount++] = i;
            for (j = i; j < maxn; j += i) {
                sieve[j] = i;
            }
        }
    }
}

void setFactorial(long long* factorial, int maxn, long long mod) {
    factorial[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

long long getFactorial(long long* factorial, int n) {
    return factorial[n];
}

long long powMod(long long base, long long exp, long long mod) {
    base %= mod;
    long long ret = 1;
    while (exp > 0) {
        if (exp & 1) ret = (ret * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ret;
}

long long ncr(long long* factorial, int n, int r, long long mod) {
    if (r > n) return 0;
    long long numerator = factorial[n];
    long long denominator = (factorial[r] * factorial[n - r]) % mod;
    return (numerator * powMod(denominator, mod - 2, mod)) % mod;
}

int* getIntArray(int size, FILE* in) {
    int* ar = (int*)malloc(size * sizeof(int));
    if (!ar) return NULL;
    for (int i = 0; i < size; ++i) {
        fscanf(in, "%d", &ar[i]);
    }
    return ar;
}

void solve(int N, long long K, int* A) {
    bool* vis = (bool*)calloc(N, sizeof(bool));
    if (!vis) return;
    int* straight = (int*)malloc(N * sizeof(int));
    if (!straight) {
        free(vis);
        return;
    }
    int* cycle = (int*)malloc(N * sizeof(int));
    if (!cycle) {
        free(vis);
        free(straight);
        return;
    }
    int straightSize = 0, cycleSize = 0;

    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = true;
        curr = A[curr] - 1;
    }

    int st = 0;
    while (st != curr) {
        straight[straightSize++] = st;
        st = A[st] - 1;
    }

    cycle[cycleSize++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle[cycleSize++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straightSize) {
        printf("%d\n", straight[K] + 1);
    } else {
        K -= straightSize;
        printf("%d\n", cycle[K % cycleSize] + 1);
    }

    free(vis);
    free(straight);
    free(cycle);
}

int main() {
    Helper* hp = createHelper(MOD, MAXN);
    if (!hp) return 1;
    int* sieve = (int*)calloc(hp->MAXN, sizeof(int));
    if (!sieve) {
        free(hp);
        return 1;
    }
    int* primes = (int*)malloc(hp->MAXN * sizeof(int));
    if (!primes) {
        free(sieve);
        free(hp);
        return 1;
    }
    long long* factorial = (long long*)malloc(hp->MAXN * sizeof(long long));
    if (!factorial) {
        free(primes);
        free(sieve);
        free(hp);
        return 1;
    }

    setSieve(sieve, primes, hp->MAXN);
    setFactorial(factorial, hp->MAXN, hp->MOD);

    int tc = 1;
    int tce;
    int N;
    long long K;
    int* A;

    while (tc--) {
        fscanf(stdin, "%d %lld", &N, &K);
        A = getIntArray(N, stdin);
        if (!A) {
            free(factorial);
            free(primes);
            free(sieve);
            free(hp);
            return 1;
        }
        solve(N, K, A);
        free(A);
    }

    free(factorial);
    free(primes);
    free(sieve);
    free(hp);

    return 0;
}
// End of Code
