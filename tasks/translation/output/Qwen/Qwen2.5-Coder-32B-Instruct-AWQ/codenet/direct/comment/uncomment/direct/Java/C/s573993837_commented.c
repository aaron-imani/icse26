#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, i, val;
} Pair;

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

long fast_pow(long base, long n, long M) {
    if (n == 0) return 1;
    if (n == 1) return base;
    long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0) return (halfn * halfn) % M;
    else return (((halfn * halfn) % M) * base) % M;
}

long modInverse(long n, long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(long *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%ld", &arr[i]);
    }
}

void feedArr_int(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void feedArr_double(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }
}

void feedArr_string(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }
}

char* printArr_int(int *arr, int size) {
    char *result = (char *)malloc(size * 12); // Assuming each number can be up to 11 digits + space
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        sprintf(result + strlen(result), "%d ", arr[i]);
    }
    return result;
}

char* printArr_long(long *arr, int size) {
    char *result = (char *)malloc(size * 24); // Assuming each number can be up to 23 digits + space
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        sprintf(result + strlen(result), "%ld ", arr[i]);
    }
    return result;
}

char* printArr_string(char **arr, int size) {
    char *result = (char *)malloc(size * 100); // Arbitrary size for strings
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        sprintf(result + strlen(result), "%s ", arr[i]);
    }
    return result;
}

char* printArr_double(double *arr, int size) {
    char *result = (char *)malloc(size * 24); // Assuming each number can be up to 23 digits + space
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        sprintf(result + strlen(result), "%.15g ", arr[i]);
    }
    return result;
}

void solve() {
    long n, m;
    int t = 1;
    while (t--) {
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
