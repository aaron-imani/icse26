#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 1024

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
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
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

void feedArr(long *arr, int length) {
    for (int i = 0; i < length; i++)
        scanf("%ld", &arr[i]);
}

void feedArrDouble(double *arr, int length) {
    for (int i = 0; i < length; i++)
        scanf("%lf", &arr[i]);
}

void feedArrInt(int *arr, int length) {
    for (int i = 0; i < length; i++)
        scanf("%d", &arr[i]);
}

void feedArrString(char **arr, int length) {
    for (int i = 0; i < length; i++)
        scanf("%s", arr[i]);
}

char* printArr(int *arr, int length) {
    static char result[MAX_LINE];
    result[0] = '\0';
    for (int i = 0; i < length; i++) {
        char temp[12];
        snprintf(temp, sizeof(temp), "%d ", arr[i]);
        strncat(result, temp, MAX_LINE - strlen(result) - 1);
    }
    return result;
}

char* printArrLong(long *arr, int length) {
    static char result[MAX_LINE];
    result[0] = '\0';
    for (int i = 0; i < length; i++) {
        char temp[24];
        snprintf(temp, sizeof(temp), "%ld ", arr[i]);
        strncat(result, temp, MAX_LINE - strlen(result) - 1);
    }
    return result;
}

char* printArrString(char **arr, int length) {
    static char result[MAX_LINE];
    result[0] = '\0';
    for (int i = 0; i < length; i++) {
        strncat(result, arr[i], MAX_LINE - strlen(result) - 1);
        strncat(result, " ", MAX_LINE - strlen(result) - 1);
    }
    return result;
}

char* printArrDouble(double *arr, int length) {
    static char result[MAX_LINE];
    result[0] = '\0';
    for (int i = 0; i < length; i++) {
        char temp[32];
        snprintf(temp, sizeof(temp), "%.1f ", arr[i]);
        strncat(result, temp, MAX_LINE - strlen(result) - 1);
    }
    return result;
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
