#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int L, R, top, bottom;

void solve() {
    int t = 1;
    while (t--) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
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
            printf("%lld\n", (m - n < n) ? m - n : n);
            continue;
        }
        printf("%lld\n", (m - n < n) ? m - n : n);
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
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(long long *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%lld", &arr[i]);
}

void feedArr_double(double *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%lf", &arr[i]);
}

void feedArr_int(int *arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void feedArr_string(char **arr, int size) {
    for (int i = 0; i < size; i++)
        scanf("%s", arr[i]);
}

char* printArr_int(int *arr, int size) {
    char *sbr = (char *)malloc(1000 * sizeof(char));
    sbr[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[10];
        sprintf(temp, "%d ", arr[i]);
        strcat(sbr, temp);
    }
    return sbr;
}

char* printArr_long(long long *arr, int size) {
    char *sbr = (char *)malloc(1000 * sizeof(char));
    sbr[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%lld ", arr[i]);
        strcat(sbr, temp);
    }
    return sbr;
}

char* printArr_string(char **arr, int size) {
    char *sbr = (char *)malloc(1000 * sizeof(char));
    sbr[0] = '\0';
    for (int i = 0; i < size; i++) {
        strcat(sbr, arr[i]);
        strcat(sbr, " ");
    }
    return sbr;
}

char* printArr_double(double *arr, int size) {
    char *sbr = (char *)malloc(1000 * sizeof(char));
    sbr[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%lf ", arr[i]);
        strcat(sbr, temp);
    }
    return sbr;
}

int main() {
    solve();
    return 0;
}
// End of Code
