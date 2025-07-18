#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int *Parent;
    int size;
} UnionFind;

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

void initUnionFind(UnionFind *uf, int n);
int root(UnionFind *uf, int A);
int size(UnionFind *uf, int A);
int connect(UnionFind *uf, int A, int B);

int hasNextByte(FastScanner *fs);
int readByte(FastScanner *fs);
int hasNext(FastScanner *fs);
char *next(FastScanner *fs);
int isPrime(long n);
long modpow(long x, long n, long mo);
long modint(long a, long m);
long gcd(long a, long b);
int max(int a, int b);
int min(int a, int b);
long lmax(long a, long b);
long lmin(long a, long b);
int upper_division(int a, int b);
long lupper_division(long a, long b);
int lower_bound(int a[], int key);
int upper_bound(int a[], int key);
void warshall_floyd(int v[][100], int n);
char *reverse(char *str);
void printArray(int que[]);
int **doublesort(int **a, int n);
long **ldoublesort(long **a, int n);
int *setArray(int a);
long *lsetArray(int a);

void initUnionFind(UnionFind *uf, int n) {
    uf->Parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    uf->size = n;
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = root(uf, uf->Parent[A]);
}

int size(UnionFind *uf, int A) {
    return -uf->Parent[root(uf, A)];
}

int connect(UnionFind *uf, int A, int B) {
    int rootA = root(uf, A);
    int rootB = root(uf, B);
    if (rootA == rootB) return 0;
    if (size(uf, A) < size(uf, B)) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }
    uf->Parent[rootA] += uf->Parent[rootB];
    uf->Parent[rootB] = rootA;
    return 1;
}

int hasNextByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) return 1;
    else {
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, 1, 1024, fs->in);
        return (fs->buflen > 0);
    }
}

int readByte(FastScanner *fs) {
    if (hasNextByte(fs)) return (unsigned char)fs->buffer[fs->ptr++];
    else return -1;
}

int hasNext(FastScanner *fs) {
    while (hasNextByte(fs) && !isprint(fs->buffer[fs->ptr])) fs->ptr++;
    return hasNextByte(fs);
}

char *next(FastScanner *fs) {
    if (!hasNext(fs)) return NULL;
    char *result = malloc(1024);
    int len = 0;
    int b = readByte(fs);
    while (isprint(b)) {
        result[len++] = b;
        b = readByte(fs);
    }
    result[len] = '\0';
    return result;
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

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if (n & 1) sum = (sum * x) % mo;
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
        long x = a; a = b; b = x;
        u -= t * v;
        x = u; u = v; v = x;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long lmax(long a, long b) { return a > b ? a : b; }
long lmin(long a, long b) { return a < b ? a : b; }
int upper_division(int a, int b) {
    return a % b == 0 ? a / b : a / b + 1;
}
long lupper_division(long a, long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

int lower_bound(int a[], int key) {
    return 0;
}

int upper_bound(int a[], int key) {
    return 0;
}

void warshall_floyd(int v[][100], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

char *reverse(char *str) {
    int len = strlen(str);
    char *ret = malloc(len);
    for (int i = 0, j = len-1; i < len; i++, j--) {
        ret[i] = str[j];
    }
    ret[len] = '\0';
    return ret;
}

void printArray(int que[]) {
    return;
}

int **doublesort(int **a, int n) {
    return a;
}

long **ldoublesort(long **a, int n) {
    return a;
}

int *setArray(int a) {
    int *b = malloc(a * sizeof(int));
    for (int i=0; i < a; i++) {
        char *input = next(&fs);
        b[i] = atoi(input);
        free(input);
    }
    return b;
}

long *lsetArray(int a) {
    long *b = malloc(a * sizeof(long));
    for (int i=0; i < a; i++) {
        char *input = next(&fs);
        b[i] = atoll(input);
        free(input);
    }
    return b;
}

int main() {
    FastScanner fs;
    fs.in = stdin;
    fs.ptr = 0;
    fs.buflen = 0;

    char *str = next(&fs);
    if (str == NULL || strlen(str) < 6) {
        printf("No\n");
    } else {
        if (str[2] == str[3] && str[4] == str[5]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    free(str);
    return 0;
}
// End of Code
