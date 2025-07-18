#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, i;
} Pair;

static int isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

static long gcd(long a, long b) {
    if (b == 0)
        return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

static long fast_pow(long base, long n, long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

static long modInverse(long n, long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(long *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%ld", &arr[i]);
}

void feedArr(double *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%lf", &arr[i]);
}

void feedArr(int *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void feedArr(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(char) * 100);
        scanf("%s", arr[i]);
    }
}

char* printArr(int *arr, int size) {
    static char sbr[1000];
    for (int i = 0; i < size; i++)
        sprintf(sbr + strlen(sbr), "%d ", arr[i]);
    return sbr;
}

char* printArr(long *arr, int size) {
    static char sbr[1000];
    for (int i = 0; i < size; i++)
        sprintf(sbr + strlen(sbr), "%ld ", arr[i]);
    return sbr;
}

char* printArr(char **arr, int size) {
    static char sbr[1000];
    for (int i = 0; i < size; i++)
        sprintf(sbr + strlen(sbr), "%s ", arr[i]);
    return sbr;
}

char* printArr(double *arr, int size) {
    static char sbr[1000];
    for (int i = 0; i < size; i++)
        sprintf(sbr + strlen(sbr), "%f ", arr[i]);
    return sbr;
}

void solve() {
    int t = 1;
    while (t--) {
        long n, m;
        scanf("%ld %ld", &n, &m);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        if (n == m) {
            printf("0\n");
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            printf("%ld\n", (m - n < n) ? m - n : n);
            continue;
        }
        printf("%ld\n", (m - n < n) ? m - n : n);
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
