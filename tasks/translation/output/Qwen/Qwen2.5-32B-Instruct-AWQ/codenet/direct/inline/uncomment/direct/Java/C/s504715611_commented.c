#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *parent;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = -1;
    }
    return uf;
}

int findRoot(UnionFind *uf, int A) {
    if (uf->parent[A] < 0) return A;
    return uf->parent[A] = findRoot(uf, uf->parent[A]);
}

int getSize(UnionFind *uf, int A) {
    return -uf->parent[findRoot(uf, A)];
}

void connect(UnionFind *uf, int A, int B) {
    A = findRoot(uf, A);
    B = findRoot(uf, B);
    if (A == B) return;
    if (getSize(uf, A) < getSize(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->parent[A] += uf->parent[B];
    uf->parent[B] = A;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    return 0;
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

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long d = sqrt(n);
    for (int i = 3; i <= d; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int upper_division(int a, int b) {
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
    int len = strlen(str);
    char *ch = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < upper_division(len, 2); i++) {
        ch[i] = str[len - i - 1];
        ch[len - 1 - i] = str[i];
    }
    return ch;
}

void printArray(int *que, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[n - 1]);
}

int** doublesort(int **a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j][0] > a[j + 1][0]) {
                int *temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

long** ldoublesort(long **a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j][0] > a[j + 1][0]) {
                long *temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
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

char* revch(char *ch, int len) {
    char *ret = (char*)malloc(len * sizeof(char));
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

int* revint(int *ch, int len) {
    int *ret = (int*)malloc(len * sizeof(int));
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

void warshall_floyd(int **v, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = v[i][j] < v[i][k] + v[k][j] ? v[i][j] : v[i][k] + v[k][j];
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
// End of Code
