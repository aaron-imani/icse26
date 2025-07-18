#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int *Parent;
} UnionFind;

UnionFind* UnionFind_create(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->Parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->Parent[i] = -1;
    }
    return uf;
}

int UnionFind_root(UnionFind* uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = UnionFind_root(uf, uf->Parent[A]);
}

int UnionFind_size(UnionFind* uf, int A) {
    return -uf->Parent[UnionFind_root(uf, A)];
}

bool UnionFind_connect(UnionFind* uf, int A, int B) {
    A = UnionFind_root(uf, A);
    B = UnionFind_root(uf, B);
    if (A == B) return false;
    if (UnionFind_size(uf, A) < UnionFind_size(uf, B)) {
        int C = A;
        A = B;
        B = C;
    }
    uf->Parent[A] += uf->Parent[B];
    uf->Parent[B] = A;
    return true;
}

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

FastScanner* FastScanner_create() {
    FastScanner* fs = (FastScanner*)malloc(sizeof(FastScanner));
    fs->in = stdin;
    fs->ptr = 0;
    fs->buflen = 0;
    return fs;
}

bool FastScanner_hasNextByte(FastScanner* fs) {
    if (fs->ptr < fs->buflen) return true;
    fs->ptr = 0;
    fs->buflen = fread(fs->buffer, 1, 1024, fs->in);
    return fs->buflen > 0;
}

int FastScanner_readByte(FastScanner* fs) {
    if (FastScanner_hasNextByte(fs)) return fs->buffer[fs->ptr++];
    return -1;
}

bool FastScanner_isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

bool FastScanner_hasNext(FastScanner* fs) {
    while (FastScanner_hasNextByte(fs) && !FastScanner_isPrintableChar(fs->buffer[fs->ptr])) fs->ptr++;
    return FastScanner_hasNextByte(fs);
}

char* FastScanner_next(FastScanner* fs) {
    if (!FastScanner_hasNext(fs)) exit(1);
    char* sb = (char*)malloc(1024 * sizeof(char));
    int b = FastScanner_readByte(fs);
    int i = 0;
    while (FastScanner_isPrintableChar(b)) {
        sb[i++] = b;
        b = FastScanner_readByte(fs);
    }
    sb[i] = '\0';
    return sb;
}

long FastScanner_nextLong(FastScanner* fs) {
    if (!FastScanner_hasNext(fs)) exit(1);
    long n = 0;
    bool minus = false;
    int b = FastScanner_readByte(fs);
    if (b == '-') {
        minus = true;
        b = FastScanner_readByte(fs);
    }
    if (b < '0' || '9' < b) exit(1);
    while (true) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !FastScanner_isPrintableChar(b)) {
            return minus ? -n : n;
        } else {
            exit(1);
        }
        b = FastScanner_readByte(fs);
    }
}

int FastScanner_nextInt(FastScanner* fs) {
    long nl = FastScanner_nextLong(fs);
    if (nl < INT_MIN || nl > INT_MAX) exit(1);
    return (int)nl;
}

double FastScanner_nextDouble(FastScanner* fs) {
    return atof(FastScanner_next(fs));
}

char FastScanner_nextchar(FastScanner* fs) {
    return (char)fgetc(fs->in);
}

int main() {
    FastScanner* fs = FastScanner_create();
    char* str = FastScanner_next(fs);
    printf("%s\n", str[2] == str[3] && str[4] == str[5] ? "Yes" : "No");
    free(str);
    free(fs);
    return 0;
}
// End of Code
