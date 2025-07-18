#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *parent;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n);
int root(UnionFind* uf, int A);
int sizeUnion(UnionFind* uf, int A);
int connectUnion(UnionFind* uf, int A, int B);

int lower_bound(int a[], int n, int key);
int upper_bound(int a[], int n, int key);
int isPrime(long long n);
int upper_division(int a, int b);
long long lupper_division(long long a, long long b);
int* setArray(int a);
long long* lsetArray(int a);
char* reverse(char* str);
void printArray(int que[], int len);
int compareIntArrays(const void *a, const void *b);
void doublesort(int **a, int n);
int compareLongLongArrays(const void *a, const void *b);
void ldoublesort(long long **a, int n);
long long modpow(long long x, long long n, long long mo);
char* revch(char* ch);
int* revint(int ch[], int len);
void warshall_floyd(int **v, int n);
long long modint(long long a, long long m);

UnionFind* createUnionFind(int n) {
    UnionFind* uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->parent[i] = -1;
    uf->size = n;
    return uf;
}

int root(UnionFind* uf, int A) {
    if (uf->parent[A] < 0) return A;
    return uf->parent[A] = root(uf, uf->parent[A]);
}

int sizeUnion(UnionFind* uf, int A) {
    return -uf->parent[root(uf, A)];
}

int connectUnion(UnionFind* uf, int A, int B) {
    A = root(uf, A);
    B = root(uf, B);
    if (A == B) return 0;
    if (sizeUnion(uf, A) < sizeUnion(uf, B)) {
        int temp = A;
        A = B;
        B = temp;
    }
    uf->parent[A] += uf->parent[B];
    uf->parent[B] = A;
    return 1;
}

int lower_bound(int a[], int n, int key) {
    int right = n;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int upper_bound(int a[], int n, int key) {
    int right = n;
    int left = 0;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] <= key) left = mid;
        else right = mid;
    }
    return left;
}

int isPrime(long long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long long d = sqrt(n);
    for (long long i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int upper_division(int a, int b) {
    return (a % b == 0) ? (a / b) : (a / b + 1);
}

long long lupper_division(long long a, long long b) {
    return (a % b == 0) ? (a / b) : (a / b + 1);
}

int* setArray(int a) {
    int *b = malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }
    return b;
}

long long* lsetArray(int a) {
    long long *b = malloc(a * sizeof(long long));
    for (int i = 0; i < a; i++) {
        scanf("%lld", &b[i]);
    }
    return b;
}

char* reverse(char* str) {
    int len = strlen(str);
    char *ch = malloc(len + 1);
    char *chch = str;
    int a = len;
    for (int i = 0; i < upper_division(a, 2); i++) {
        ch[i] = chch[len - i - 1];
        ch[len - 1 - i] = chch[i];
    }
    ch[len] = '\0';
    return ch;
}

void printArray(int que[], int len) {
    for (int i = 0; i < len - 1; i++) {
        printf("%d ", que[i]);
    }
    if (len > 0) printf("%d\n", que[len - 1]);
}

int compareIntArrays(const void *a, const void *b) {
    int **x = (int **)a;
    int **y = (int **)b;
    return (*x)[0] - (*y)[0];
}

void doublesort(int **a, int n) {
    qsort(a, n, sizeof(int *), compareIntArrays);
}

int compareLongLongArrays(const void *a, const void *b) {
    long long **x = (long long **)a;
    long long **y = (long long **)b;
    return (*x)[0] - (*y)[0];
}

void ldoublesort(long long **a, int n) {
    qsort(a, n, sizeof(long long *), compareLongLongArrays);
}

long long modpow(long long x, long long n, long long mo) {
    long long sum = 1;
    while (n > 0) {
        if (n & 1) {
            sum = (sum * x) % mo;
        }
        x = (x * x) % mo;
        n >>= 1;
    }
    return sum;
}

char* revch(char* ch) {
    int len = strlen(ch);
    char* ret = malloc(len + 1);
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    ret[len] = '\0';
    return ret;
}

int* revint(int ch[], int len) {
    int* ret = malloc(len * sizeof(int));
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        ret[j] = ch[i];
    }
    return ret;
}

void warshall_floyd(int **v, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = (v[i][j] < (v[i][k] + v[k][j])) ? v[i][j] : (v[i][k] + v[k][j]);
            }
        }
    }
}

long long modint(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b != 0) {
        long long t = a / b;
        a -= t * b;
        long long x = a;
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
    char str[10];
    if (scanf("%9s", str) != 1) return 1;
    int len = strlen(str);
    if (len < 6) {
        printf("No\n");
    } else {
        if (str[2] == str[3] && str[4] == str[5]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

// End of Code
