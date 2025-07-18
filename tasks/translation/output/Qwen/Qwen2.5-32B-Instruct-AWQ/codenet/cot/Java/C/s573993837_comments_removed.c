#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int u, v, i;
} Pair;

void solve(FILE *in, FILE *out) {
    int t = 1;
    while (t--) {
        long n = 0, m = 0;
        fscanf(in, "%ld %ld", &n, &m);
        if (n == 0) {
            fprintf(out, "0\n");
            continue;
        }
        if (n == m) {
            fprintf(out, "0\n");
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            fprintf(out, "%ld\n", (m - n < n) ? m - n : n);
            continue;
        }
        fprintf(out, "%ld\n", (m - n < n) ? m - n : n);
    }
}

void swap(char *chrr, int i, int j) {
    char temp = chrr[i];
    chrr[i] = chrr[j];
    chrr[j] = temp;
}

int num(int n) {
    int a = 0;
    while (n > 0) {
        a += (n & 1);
        n >>= 1;
    }
    return a;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long fast_pow(long base, long n, long M) {
    if (n == 0) return 1;
    if (n == 1) return base;
    long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

long modInverse(long n, long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(long *arr, int len, FILE *in) {
    for (int i = 0; i < len; i++)
        fscanf(in, "%ld", &arr[i]);
}

void feedArr(double *arr, int len, FILE *in) {
    for (int i = 0; i < len; i++)
        fscanf(in, "%lf", &arr[i]);
}

void feedArr(int *arr, int len, FILE *in) {
    for (int i = 0; i < len; i++)
        fscanf(in, "%d", &arr[i]);
}

void feedArr(char **arr, int len, FILE *in) {
    for (int i = 0; i < len; i++)
        fscanf(in, "%s", arr[i]);
}

char *printArr(int *arr, int len) {
    char *sbr = malloc(len * 10 * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + i * 10, "%d ", arr[i]);
    return sbr;
}

char *printArr(long *arr, int len) {
    char *sbr = malloc(len * 10 * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + i * 11, "%ld ", arr[i]);
    return sbr;
}

char *printArr(char **arr, int len) {
    char *sbr = malloc(len * 10 * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + i * 10, "%s ", arr[i]);
    return sbr;
}

char *printArr(double *arr, int len) {
    char *sbr = malloc(len * 10 * sizeof(char));
    for (int i = 0; i < len; i++)
        sprintf(sbr + i * 10, "%f ", arr[i]);
    return sbr;
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    solve(in, out);
    fclose(out);
    return 0;
} // End of Code
