#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int u, v, i;
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

void feedArr(long *arr, int len, FILE *input) {
    for (int i = 0; i < len; i++)
        fscanf(input, "%ld", &arr[i]);
}

void feedArr(double *arr, int len, FILE *input) {
    for (int i = 0; i < len; i++)
        fscanf(input, "%lf", &arr[i]);
}

void feedArr(int *arr, int len, FILE *input) {
    for (int i = 0; i < len; i++)
        fscanf(input, "%d", &arr[i]);
}

void feedArr(char **arr, int len, FILE *input) {
    for (int i = 0; i < len; i++) {
        arr[i] = malloc(100 * sizeof(char));
        fscanf(input, "%s", arr[i]);
    }
}

char *printArr(int *arr, int len) {
    char *sbr = malloc(100 * len * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + strlen(sbr), "%d ", arr[i]);
    return sbr;
}

char *printArr(long *arr, int len) {
    char *sbr = malloc(100 * len * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + strlen(sbr), "%ld ", arr[i]);
    return sbr;
}

char *printArr(char **arr, int len) {
    char *sbr = malloc(100 * len * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + strlen(sbr), "%s ", arr[i]);
    return sbr;
}

char *printArr(double *arr, int len) {
    char *sbr = malloc(100 * len * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + strlen(sbr), "%lf ", arr[i]);
    return sbr;
}

void solve(FILE *input, FILE *output) {
    int t = 1;
    while (t--) {
        long n, m;
        fscanf(input, "%ld %ld", &n, &m);
        if (n == 0) {
            fprintf(output, "0\n");
            continue;
        }
        if (n == m) {
            fprintf(output, "0\n");
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            fprintf(output, "%ld\n", (m - n < n) ? m - n : n);
            continue;
        }
        fprintf(output, "%ld\n", (m - n < n) ? m - n : n);
    }
}

int main() {
    FILE *input = stdin;
    FILE *output = stdout;
    solve(input, output);
    return 0;
}
// End of Code
