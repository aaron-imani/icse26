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

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

FastScanner* createFastScanner() {
    FastScanner *fs = (FastScanner*)malloc(sizeof(FastScanner));
    fs->in = stdin;
    fs->ptr = 0;
    fs->buflen = 0;
    return fs;
}

int hasNextByte(FastScanner *fs) {
    if (fs->ptr < fs->buflen) return 1;
    fs->ptr = 0;
    fs->buflen = fread(fs->buffer, 1, 1024, fs->in);
    if (fs->buflen <= 0) return 0;
    return 1;
}

int readByte(FastScanner *fs) {
    if (hasNextByte(fs)) return fs->buffer[fs->ptr++];
    return -1;
}

int isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

int hasNext(FastScanner *fs) {
    while (hasNextByte(fs) && !isPrintableChar(fs->buffer[fs->ptr])) fs->ptr++;
    return hasNextByte(fs);
}

char* next(FastScanner *fs) {
    if (!hasNext(fs)) exit(1);
    char *sb = (char*)malloc(1024 * sizeof(char));
    int b = readByte(fs);
    int i = 0;
    while (isPrintableChar(b)) {
        sb[i++] = b;
        b = readByte(fs);
    }
    sb[i] = '\0';
    return sb;
}

long nextLong(FastScanner *fs) {
    if (!hasNext(fs)) exit(1);
    long n = 0;
    int minus = 0;
    int b = readByte(fs);
    if (b == '-') {
        minus = 1;
        b = readByte(fs);
    }
    if (b < '0' || '9' < b) exit(1);
    while (1) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
            return minus ? -n : n;
        } else {
            exit(1);
        }
        b = readByte(fs);
    }
}

int nextInt(FastScanner *fs) {
    long nl = nextLong(fs);
    if (nl < INT_MIN || nl > INT_MAX) exit(1);
    return (int) nl;
}

double nextDouble(FastScanner *fs) {
    return atof(next(fs));
}

char nextchar(FastScanner *fs) {
    return (char)fgetc(fs->in);
}

int main() {
    FastScanner *fs = createFastScanner();
    char *str = next(fs);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    free(str);
    free(fs);
    return 0;
}
// End of Code
