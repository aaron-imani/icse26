#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int u, v, i, val;
} Pair;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
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

void feedArrInt(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void feedArrDouble(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }
}

void feedArrString(char **arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%s", arr[i]);
    }
}

char* printArr(int *arr, int size) {
    static char result[1000] = "";
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[10];
        sprintf(temp, "%d ", arr[i]);
        strcat(result, temp);
    }
    return result;
}

char* printArrLong(long *arr, int size) {
    static char result[1000] = "";
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%ld ", arr[i]);
        strcat(result, temp);
    }
    return result;
}

char* printArrString(char **arr, int size) {
    static char result[1000] = "";
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        strcat(result, arr[i]);
        strcat(result, " ");
    }
    return result;
}

char* printArrDouble(double *arr, int size) {
    static char result[1000] = "";
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        char temp[20];
        sprintf(temp, "%.1f ", arr[i]);
        strcat(result, temp);
    }
    return result;
}

int main() {
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
    return 0;
}
// End of Code
