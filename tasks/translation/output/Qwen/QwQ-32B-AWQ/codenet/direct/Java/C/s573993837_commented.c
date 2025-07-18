#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int L, R, top, bottom;

void solve() {
    int t = 1;
    while (t-- > 0) {
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
            n %= m;
        }
        printf("%lld\n", (m - n < n) ? m - n : n);
    }
}

void swap(char *arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int num(int n) {
    int a = 0;
    while (n > 0) {
        a += (n & 1);
        n >>= 1;
    }
    return a;
}

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
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base % M;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return ((halfn * halfn) % M * (base % M)) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void feedArrLong(long arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%ld", &arr[i]);
    }
}

void feedArrDouble(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }
}

void feedArrInt(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void feedArrString(char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }
}

char *printArrInt(int arr[], int size) {
    static char buffer[100];
    buffer[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%d ", arr[i]);
        strcat(buffer, temp);
    }
    return buffer;
}

char *printArrLong(long arr[], int size) {
    static char buffer[100];
    buffer[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%ld ", arr[i]);
        strcat(buffer, temp);
    }
    return buffer;
}

char *printArrString(char *arr[], int size) {
    static char buffer[100];
    buffer[0] = '\0';
    for (int i = 0; i < size; i++) {
        strcat(buffer, arr[i]);
        strcat(buffer, " ");
    }
    return buffer;
}

char *printArrDouble(double arr[], int size) {
    static char buffer[100];
    buffer[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%lf ", arr[i]);
        strcat(buffer, temp);
    }
    return buffer;
}

int main() {
    solve();
    return 0;
}
// End of Code
