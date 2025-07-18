#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *Parent;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->Parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    uf->size = n;
    return uf;
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = root(uf, uf->Parent[A]);
}

int sizeOf(UnionFind *uf, int A) {
    return -uf->Parent[root(uf, A)];
}

int connect(UnionFind *uf, int A, int B) {
    int rootA = root(uf, A);
    int rootB = root(uf, B);
    if (rootA == rootB) return 0;
    if (sizeOf(uf, A) < sizeOf(uf, B)) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }
    uf->Parent[rootA] += uf->Parent[rootB];
    uf->Parent[rootB] = rootA;
    return 1;
}

typedef struct {
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

void initFastScanner(FastScanner *fs) {
    fs->ptr = 0;
    fs->buflen = 0;
}

int isPrintableChar(int c) {
    return c >= 33 && c <= 126;
}

char* next(FastScanner *fs) {
    while (fs->ptr < fs->buflen && !isPrintableChar(fs->buffer[fs->ptr])) {
        fs->ptr++;
    }
    if (fs->ptr >= fs->buflen) {
        fs->buflen = fread(fs->buffer, 1, sizeof(fs->buffer), stdin);
        fs->ptr = 0;
        if (fs->buflen == 0) return NULL;
    }
    int start = fs->ptr;
    while (fs->ptr < fs->buflen && isPrintableChar(fs->buffer[fs->ptr])) {
        fs->ptr++;
    }
    char *result = (char*)malloc(fs->ptr - start + 1);
    strncpy(result, fs->buffer + start, fs->ptr - start);
    result[fs->ptr - start] = '\0';
    return result;
}

int nextInt(FastScanner *fs) {
    char *s = next(fs);
    if (!s) return 0;
    int num = atoi(s);
    free(s);
    return num;
}

long nextLong(FastScanner *fs) {
    char *s = next(fs);
    long num = atol(s);
    free(s);
    return num;
}

FastScanner fs;
int mod = 1000000007;
double eps = 1.0e-14;
int big = INT_MAX;
double PI = 3.14159265358979323846262338327950288;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long lmax(long a, long b) { return a > b ? a : b; }
long lmin(long a, long b) { return a < b ? a : b; }
long factorial(int i) { return i == 1 ? 1 : (long)i * factorial(i - 1); }

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 驀
        return 0;
    long d = (long)sqrt(n);
    for (long i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

int* setArray(int a) {
    int *b = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) b[i] = nextInt(&fs);
    return b;
}

long* lsetArray(int a) {
    long *b = (long*)malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) b[i] = nextLong(&fs);
    return b;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void printArray(int *arr, int len) {
    if (len == 0) return;
    for (int i = 0; i < len - 1; i++) printf("%d ", arr[i]);
    printf("%d\n", arr[len - 1]);
}

int compareInt(const void *a, const void *b) {
    int *x = *(int**)a;
    int *y = *(int**)b;
    return x[0] - y[0];
}

void doublesort(int **a, int n) {
    qsort(a, n, sizeof(int*), compareInt);
}

int compareLong(const void *a, const void *b) {
    long *x = *(long**)a;
    long *y = *(long**)b;
    return (x[0] > y[0]) - (x[0] < y[0]);
}

void ldoublesort(long **a, int n) {
    qsort(a, n, sizeof(long*), compareLong);
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if (n & 1) {
            sum = (sum * x) % mo;
        }
        x = (x * x) % mo;
        n >>= 1;
    }
    return sum;
}

void revch(char ch[]) {
    int len = strlen(ch);
    char *ret = (char*)malloc(len * sizeof(char));
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        ret[i] = ch[j];
    }
    strcpy(ch, ret);
    free(ret);
}

int* revint(int ch[]) {
    int len = sizeof(ch) / sizeof(ch[0]);
    int *ret = (int*)malloc(len * sizeof(int));
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        ret[i] = ch[j];
    }
    return ret;
}

void warshall_floyd(int v[][n], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int modint(long a, long m) {
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
    initFastScanner(&fs);
    char *str = next(&fs);
    if (str == NULL) {
        printf("No\n");
        return 1;
    }
    if (strlen(str) < 6) {
        printf("No\n");
        free(str);
        return 0;
    }
    if (str[2] == str[3] && str[4] == str[5]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(str);
    return 0;
} // End of Code
