#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, i, val;
} Pair;

int isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long fast_pow(long base, long n, long M) {
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

long modInverse(long n, long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(long *arr, int len) {
    for (int i = 0; i < len; i++)
        scanf("%ld", &arr[i]);
}

void feedArrDouble(double *arr, int len) {
    for (int i = 0; i < len; i++)
        scanf("%lf", &arr[i]);
}

void feedArrInt(int *arr, int len) {
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
}

void feedArrString(char **arr, int len) {
    for (int i = 0; i < len; i++)
        scanf("%s", arr[i]);
}

void printArrInt(int *arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printArrLong(long *arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%ld ", arr[i]);
    printf("\n");
}

void printArrString(char **arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

void printArrDouble(double *arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%lf ", arr[i]);
    printf("\n");
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
            printf("%ld\n", n < m - n ? n : m - n);
            continue;
        }
        printf("%ld\n", n < m - n ? n : m - n);
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
