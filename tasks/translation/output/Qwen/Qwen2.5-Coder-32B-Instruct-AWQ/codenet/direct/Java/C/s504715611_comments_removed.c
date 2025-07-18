#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool connect(UnionFind *uf, int A, int B) {
    A = root(uf, A);
    B = root(uf, B);
    if (A == B) return false;
    if (size(uf, A) < size(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return true;
}

void destroyUnionFind(UnionFind *uf) {
    free(uf->Parent);
    free(uf);
}

long modlcm(long a, long b, long mod) {
    return a * b * modint(gcd(a, b), mod);
}

long gcd(long a, long b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
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

int lower_bound(int a[], int n, int key) {
    int right = n;
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

int upper_bound(int a[], int n, int key) {
    int right = n;
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

bool isPrime(long n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    long d = (long)sqrt(n);
    for (int i = 3; i <= d; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

int* setArray(int a) {
    int *b = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }
    return b;
}

long* lsetArray(int a) {
    long *b = (long*)malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) {
        scanf("%ld", &b[i]);
    }
    return b;
}

char* reverse(char *str) {
    int a = strlen(str);
    char *ch = (char*)malloc(a * sizeof(char));
    strcpy(ch, str);
    for (int i = 0; i < upper_division(a, 2); i++) {
        char temp = ch[i];
        ch[i] = ch[a - i - 1];
        ch[a - i - 1] = temp;
    }
    return ch;
}

void printArray(int que[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[n - 1]);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void doublesort(int a[][2], int n) {
    qsort(a, n, sizeof(a[0]), compare);
}

void ldoublesort(long a[][2], int n) {
    qsort(a, n, sizeof(a[0]), compare);
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if (n & 1) {
            sum = sum * x % mo;
        }
        x = x * x % mo;
        n >>= 1;
    }
    return sum;
}

char* revch(char ch[]) {
    int a = strlen(ch);
    char *ret = (char*)malloc(a * sizeof(char));
    for (int i = a - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

int* revint(int ch[], int n) {
    int *ret = (int*)malloc(n * sizeof(int));
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
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

int main() {
    char str[100];
    scanf("%s", str);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    return 0;
}
// End of Code
