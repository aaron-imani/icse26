#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod 1000000007
#define eps 1.0e-14
#define big 2147483647
#define PI 3.14159265358979323846262338327950288

typedef struct {
    int *Parent;
    int size;
} UnionFind;

UnionFind *create_UnionFind(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->Parent = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    uf->size = n;
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
        int tmp = A;
        A = B;
        B = tmp;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return 1;
}

typedef struct {
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

int hasNextByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) return 1;
    else {
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, 1, 1024, stdin);
        if (fs->buflen <= 0) return 0;
    }
    return 1;
}

int readByte(FastScanner *fs) {
    if (hasNextByte(fs)) return (unsigned char)fs->buffer[fs->ptr++];
    else return -1;
}

int isPrintableChar(int c) {
    return c >= 33 && c <= 126;
}

int hasNext(FastScanner *fs) {
    while (hasNextByte(fs) && !isPrintableChar(fs->buffer[fs->ptr])) {
        fs->ptr++;
    }
    return hasNextByte(fs);
}

char *next(FastScanner *fs) {
    if (!hasNext(fs)) return NULL;
    int capacity = 1;
    int sb_len = 0;
    char *sb = malloc(capacity);
    int b = readByte(fs);
    while (isPrintableChar(b)) {
        if (sb_len >= capacity) {
            capacity *= 2;
            sb = realloc(sb, capacity);
        }
        sb[sb_len++] = (char)b;
        b = readByte(fs);
    }
    sb[sb_len] = '\0';
    return sb;
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
    return i == 1 ? 1 : (long)i * factorial(i - 1);
}

int lower_bound(int *a, int len, int key) {
    int left = 0, right = len;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (a[mid] < key) left = mid;
        else right = mid;
    }
    return left;
}

int upper_bound(int *a, int len, int key) {
    int left = 0, right = len;
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
    return a % b == 0 ? a / b : a / b + 1;
}

long lupper_division(long a, long b) {
    return a % b == 0 ? a / b : a / b + 1;
}

int *setArray(FastScanner *fs, int a) {
    int *b = malloc(a * sizeof(int));
    for (int i = 0; i < a; i++) b[i] = nextInt(fs);
    return b;
}

long *lsetArray(FastScanner *fs, int a) {
    long *b = malloc(a * sizeof(long));
    for (int i = 0; i < a; i++) b[i] = nextLong(fs);
    return b;
}

char *reverse(char *str) {
    int len = strlen(str);
    char *ch = malloc(len + 1);
    char *chch = strdup(str);
    for (int i = 0; i < (len + 1) / 2; i++) {
        ch[i] = chch[len - 1 - i];
        ch[len - 1 - i] = chch[i];
    }
    ch[len] = '\0';
    free(chch);
    return ch;
}

void printArray(int *que, int len) {
    for (int i = 0; i < len - 1; i++) printf("%d ", que[i]);
    printf("%d\n", que[len - 1]);
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while (n > 0) {
        if (n & 1) sum = sum * x % mo;
        x = x * x % mo;
        n >>=  تعديل:1;
    }
    return sum;
}

char *revch(char ch[]) {
    int len = strlen(ch);
    char *ret = malloc(len + 1);
    memcpy(ret, ch, len + 1);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = ret[i];
        ret[i] = ret[j];
        ret[j] = tmp;
    }
    return ret;
}

int *revint(int ch[], int len) {
    int *ret = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) ret[i] = ch[len - 1 - i];
    return ret;
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
    FastScanner fs = {0};
    char *str = next(&fs);
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
    free(str);
    return 0;
}
// End of Code
