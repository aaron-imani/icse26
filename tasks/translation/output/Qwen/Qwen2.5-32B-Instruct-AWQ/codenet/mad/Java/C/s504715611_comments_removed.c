#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *Parent;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->Parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->Parent[i] = -1;
    }
    return uf;
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = root(uf, uf->Parent[A]);
}

int size(UnionFind *uf, int A) {
    return -uf->Parent[root(uf, A)];
}

int connect(UnionFind *uf, int A, int B) {
    A = root(uf, A);
    B = root(uf, B);
    if (A == B) return 0;
    if (size(uf, A) < size(uf, B)) {
        int C = A;
        A = B;
        B = C;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return 1;
}

int lower_bound(int a[], int key, int length) {
    int right = length;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int upper_bound(int a[], int key, int length) {
    int right = length;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    double d = sqrt(n);
    for (int i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int upper_division(int a, int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

long lupper_division(long a, long b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

long lmax(long a, long b) {
    return a > b ? a : b;
}

long lmin(long a, long b) {
    return a < b ? a : b;
}

long factorial(int i) {
    return i == 1 ? 1 : i * factorial(i - 1);
}

long gcd(long a, long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long modlcm(long a, long b, long mod) {
    return a * b * modint(gcd(a, b), mod);
}

long modint(long a, long m) {
    long b = m, u = 1, v = 0;
    while (b != 0) {
        long t = a / b;
        a -= t * b;
        long x = a;
        a = b;
        b = x;

        u -= t * v;
        x = u;
        u = v;
        v = x;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if ((n & 1) == 1) {
            sum = sum * x % mo;
        }
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

void warshall_floyd(int v[][100], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    return 0;
}
// End of Code
