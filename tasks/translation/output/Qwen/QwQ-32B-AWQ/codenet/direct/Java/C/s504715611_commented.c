#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

typedef struct {
    int *Parent;
    int size;
} UnionFind;

void initFastScanner(FastScanner *fs) {
    fs->ptr = 0;
    fs->buflen = fread(fs->buffer, 1, 1024, stdin);
}

int readByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) {
        return fs->buffer[fs->ptr++];
    } else {
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, 1, 1024, stdin);
        if (fs->buflen <= 0) return -1;
        return fs->buffer[fs->ptr++];
    }
}

int isPrintableChar(int c) {
    return c >= 33 && c <= 126;
}

char *next(FastScanner *fs) {
    char *buf = malloc(128);
    int len = 0, cap = 128;
    int c;
    while (1) {
        c = readByte(fs);
        if (c == -1) {
            free(buf);
            return NULL;
        }
        if (isPrintableChar(c)) break;
    }
    do {
        if (len >= cap) {
            cap *= 2;
            buf = realloc(buf, cap);
        }
        buf[len++] = c;
        c = readByte(fs);
    } while (isPrintableChar(c));
    buf[len] = '\0';
    return buf;
}

long nextLong(FastScanner *fs) {
    char *str = next(fs);
    long n = strtol(str, NULL, 10);
    free(str);
    return n;
}

int nextInt(FastScanner *fs) {
    return (int)nextLong(fs);
}

UnionFind* createUnionFind(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->size = n;
    uf->Parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    return uf;
}

void freeUnionFind(UnionFind *uf) {
    free(uf->Parent);
    free(uf);
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = root(uf, uf->Parent[A]);
}

int sizeUF(UnionFind *uf, int A) {
    return -uf->Parent[root(uf, A)];
}

int connect(UnionFind *uf, int A, int B) {
    int rootA = root(uf, A);
    int rootB = root(uf, B);
    if (rootA == rootB) return 0;
    if (sizeUF(uf, A) < sizeUF(uf, B)) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }
    uf->Parent[rootA] += uf->Parent[rootB];
    uf->Parent[rootB] = rootA;
    return 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
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

long factorial(int i) {
    if (i == 1) return 1;
    return (long)i * factorial(i - 1);
}

void warshall_floyd(int v[][MAX_SIZE], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 犯错; j < n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int upper_division(int a, int b) {
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long d = sqrt(n);
    for (long i = 3; i <= d; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long lupper_division(long a, long b) {
    if (a % b == 0) return a / b;
    else return a / b + 1;
}

int lmax(long a, long b) {
    return a > b ? a : b;
}

int lmin(long a, long b) {
    return a < b ? a : b;
}

int* setArray(int a, FastScanner *fs) {
    int *b = malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) {
        b[i] = nextInt(fs);
    }
    return b;
}

void printArray(int que[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", que[i]);
    }
    printf("%d\n", que[size-1]);
}

int compare(const void *a, const void *b) {
    int *x = *(int**)a;
    int *y = *(int**)b;
    return x[0] - y[0];
}

int main() {
    FastScanner fs;
    initFastScanner(&fs);
    char *str = next(&fs);
    if (str[2] == str[3] && str[4] == str[5]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(str);
    return 0;
} // End of Code
