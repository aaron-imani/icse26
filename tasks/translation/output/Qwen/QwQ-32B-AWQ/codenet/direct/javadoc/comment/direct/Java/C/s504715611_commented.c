#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

long mod = 1000000007;
double eps = 1.0e-14;
int big = INT_MAX;
double PI = 3.14159265358979323846262338327950288;

typedef struct {
    int *Parent;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->size = n;
    uf->Parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
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

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

void initFastScanner(FastScanner *fs) {
    fs->in = stdin;
    fs->ptr = 0;
    fs->buflen = 0;
}

int hasNextByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) return 1;
    fs->ptr = 0;
    if (fgets(fs->buffer, sizeof(fs->buffer), fs->in) == NULL) return 0;
    fs->buflen = strlen(fs->buffer);
    return fs->buflen > 0;
}

int readByte(FastScanner *fs) {
    if (!hasNextByte(fs)) return -1;
    return (int)fs->buffer[fs->ptr++];
}

int hasNext(FastScanner *fs) {
    while (hasNextByte(fs) && !isPrintableChar(fs->buffer[fs->ptr])) fs->ptr++;
    return hasNextByte(fs);
}

int isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

char* next(FastScanner *fs) {
    if (!hasNext(fs)) return NULL;
    int length = 0;
    int index = 0;
    int b = readByte(fs);
    while (isPrintableChar(b)) {
        length++;
        b = readByte(fs);
    }
    char *result = (char*)malloc((length + 1) * sizeof(char));
    fs->ptr -= length;
    for (int i = 0; i < length; i++) {
        b = readByte(fs);
        result[i] = (char)b;
    }
    result[length] = '\0';
    return result;
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

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    long d = sqrt(n);
    for (long i = 3; i <= d; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int upper_division(int a, int b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return (a % b == 0) ? a / b : a / b + 1;
}

int* setArray(int a) {
    int *b = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
        b[i] = nextInt(&scan);
    return b;
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

long modlcm(long a, long b) {
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

void printArray(int que[], int len) {
    for (int i = 0; i < len - 1; i++)
        printf("%d ", que[i]);
    printf("%d\n", que[len - 1]);
}

int nextInt(FastScanner *fs) {
    if (!hasNext(fs)) return -1;
    long n = 0;
    int minus = 0;
    int b = readByte(fs);
    if (b == '-') {
        minus = 1;
        b = readByte(fs);
    }
    if (b < '0' || b > '9') return -1;
    while (1) {
        if (b >= '0' && b <= '9') {
            n = n * 10 + (b - '0');
        } else if (b == -1 || !isPrintableChar(b)) {
            return (int)(minus ? -n : n);
        } else {
            return -1;
        }
        b = readByte(fs);
    }
}

char* reverse(char *str) {
    int a = strlen(str);
    char *ch = (char*)malloc((a + 1) * sizeof(char));
    char *chch = strdup(str);
    for (int i = 0; i < upper_division(a, 2); i++) {
        ch[i] = chch[a - i - 1];
        ch[a - 1 - i] = chch[i];
    }
    ch[a] = '\0';
    free(chch);
    return ch;
}

int main() {
    FastScanner scan;
    initFastScanner(&scan);
    char *str = next(&scan);
    if (str[2] == str[3] && str[4] == str[5]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(str);
    return 0;
}
// End of Code
