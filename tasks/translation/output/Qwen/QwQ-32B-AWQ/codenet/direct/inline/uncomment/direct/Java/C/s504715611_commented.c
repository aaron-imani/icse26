#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *Parent;
    int capacity;
} UnionFind;

UnionFind* create_union_find(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->Parent = (int*)malloc(n * sizeof(int));
    uf->capacity = n;
    for (int i = 0; i < n; i++) uf->Parent[i] = -1;
    return uf;
}

int root(UnionFind *uf, int A) {
    if (uf->Parent[A] < 0) return A;
    return uf->Parent[A] = root(uf, uf->Parent[A]);
}

int size(UnionFind *uf, int A) {
    int rootA = root(uf, A);
    return -uf->Parent[rootA];
}

int connect(UnionFind *uf, int A, int B) {
    int rootA = root(uf, A), rootB = root(uf, B);
    if (rootA == rootB) return 0;
    if (size(uf, A) < size(uf, B)) {
        int temp = rootA; rootA = rootB; rootB = temp;
    }
    uf->Parent[rootA] += uf->Parent[rootB];
    uf->Parent[rootB] = rootA;
    return 1;
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
long lmax(long a, long b) { return a > b ? a : b; }
long lmin(long a, long b) { return a < b ? a : b; }

int isPrime(long n) {
    if (n == 2) return 1;
    if (n < 2 || n%2 == 0) return 0;
    double d = sqrt(n);
    for (long i = 3; i <= d; i += 2) if (n%i == 0) return 0;
    return 1;
}

int upper_division(int a, int b) { return a%b == 0 ? a/b : a/b + 1; }
long lupper_division(long a, long b) { return a%b == 0 ? a/b : a/b + 1; }

void setArray(int array[], int a, void* fs) {
    for (int i = 0; i < a; i++) array[i] = ((FastScanner*)fs)->nextInt();
}

void lsetArray(long array[], int a, void* fs) {
    for (int i = 0; i < a; i++) array[i] = ((FastScanner*)fs)->nextLong();
}

char* reverse(char *str) {
    int len = strlen(str);
    char *ret = (char*)malloc(len+1);
    for (int i=0; i<len; i++) ret[i] = str[len-1-i];
    ret[len]='\0';
    return ret;
}

void printArray(int que[], int length) {
    for (int i=0; i<length-1; i++) printf("%d ", que[i]);
    printf("%d\n", que[length-1]);
}

void warshall_floyd(int v[][100], int n) {
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
}

long modpow(long x, long n, long mo) {
    long sum = 1;
    while(n>0) {
        if(n%2==1) sum = sum*x%mo;
        x = x*x%mo;
        n /= 2;
    }
    return sum;
}

char* revch(char ch[]) {
    int len = strlen(ch);
    char *ret = (char*)malloc(len+1);
    for(int i=0,j=len-1; i<len; i++,j--) ret[i] = ch[j];
    ret[len]='\0';
    return ret;
}

int* revint(int ch[], int len) {
    int *ret = (int*)malloc(len * sizeof(int));
    for(int i=0,j=len-1; i<len; i++,j--) ret[i] = ch[j];
    return ret;
}

long modint(long a, long m) {
    long b = m, u = 1, v = 0;
    while(b) {
        long t = a/b;
        a -= t*b; long x = a; a = b; b = x;
        u -= t*v; x = u; u = v; v = x;
    }
    u %= m; if(u<0) u += m;
    return u;
}

typedef struct {
    char buffer[1024]; int ptr, buflen;
    char* next() {
        if (!hasNext()) return NULL;
        int start = ptr;
        while(hasNextByte()) {
            if (!isPrintableChar(buffer[ptr])) break;
            ptr++;
        }
        int len = ptr - start;
        char* res = (char*)malloc(len+1);
        memcpy(res, buffer+start, len); res[len]='\0';
        return res;
    }
    int hasNext() {
        while(hasNextByte()) {
            if (isPrintableChar(buffer[ptr])) return 1;
            ptr++;
        }
        return 0;
    }
    int hasNextByte() {
        if (ptr < buflen) return 1;
        ptr=0; buflen = fread(buffer,1,1024,stdin);
        return buflen>0;
    }
    int isPrintableChar(int c) { return c >=33 && c<=126; }
    long nextLong() {
        if (!hasNext()) return 0;
        int sign=1, c = readByte();
        if (c == '-') { sign =-1; c = readByte(); }
        if (c<'0' || c>'9') return 0;
        long n=0;
        while(1) {
            if (c>='0' && c<='9') n = n*10 + (c-'0');
            else if (c==-1 || !isPrintableChar(c)) break;
            else return 0;
            c = readByte();
        }
        return n*sign;
    }
    int nextInt() { return (int)nextLong(); }
    int readByte() { return hasNextByte() ? buffer[ptr++] : -1; }
} FastScanner;

int main() {
    FastScanner fs;
    char *str = fs.next();
    if (!str || strlen(str)<6) { printf("No\n"); return 0; }
    if (str[2]==str[3] && str[4]==str[5]) printf("Yes\n");
    else printf("No\n");
    free(str);
    return 0;
}
// End of Code
