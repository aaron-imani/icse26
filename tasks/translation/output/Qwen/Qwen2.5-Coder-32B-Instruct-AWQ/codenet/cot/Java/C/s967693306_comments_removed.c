#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (LONG_MAX / 2)
#define MOD 1000000007
#define SIZE 1000000

typedef struct {
    long a, b;
} Pair;

int compare_pairs(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return (p1->b > p2->b) - (p1->b < p2->b);
}

typedef struct {
    FILE *in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

int hasNextByte(FastScanner *sc) {
    if (sc->ptr < sc->buflen) return 1;
    sc->ptr = 0;
    sc->buflen = fread(sc->buffer, 1, sizeof(sc->buffer), sc->in);
    return sc->buflen > 0;
}

int readByte(FastScanner *sc) {
    return hasNextByte(sc) ? sc->buffer[sc->ptr++] : -1;
}

int isPrintableChar(int c) {
    return c >= 33 && c <= 126;
}

int hasNext(FastScanner *sc) {
    while (hasNextByte(sc) && !isPrintableChar(readByte(sc)));
    return hasNextByte(sc);
}

char *next(FastScanner *sc) {
    if (!hasNext(sc)) exit(1);
    char *sb = (char *)malloc(1024);
    int b = readByte(sc);
    int len = 0;
    while (isPrintableChar(b)) {
        sb[len++] = b;
        b = readByte(sc);
    }
    sb[len] = '\0';
    return sb;
}

long nextLong(FastScanner *sc) {
    if (!hasNext(sc)) exit(1);
    long n = 0;
    int minus = 0;
    int b = readByte(sc);
    if (b == '-') {
        minus = 1;
        b = readByte(sc);
    }
    if (b < '0' || b > '9') exit(1);
    while (1) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
            return minus ? -n : n;
        } else {
            exit(1);
        }
        b = readByte(sc);
    }
}

int nextInt(FastScanner *sc) {
    long nl = nextLong(sc);
    if (nl < INT_MIN || nl > INT_MAX) exit(1);
    return (int)nl;
}

double nextDouble(FastScanner *sc) {
    char *str = next(sc);
    double result = atof(str);
    free(str);
    return result;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
        if (r & 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return sum;
}

long inv(long a) {
    return pow(a, MOD - 2);
}

long modFact(long n) {
    if (n == 0) return 1;
    return n * modFact(n - 1) % MOD;
}

long fact(long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void initCOMB(long *fac, long *inv, long *finv) {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long modComb(int n, int r, long *fac, long *finv) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

long comb(long n, long r) {
    long num = 1;
    for (long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int isPrime(long a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

char *nextPermutation(char *s) {
    int len = strlen(s);
    int pivotPos = -1;
    char pivot = 0;
    for (int i = len - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            pivotPos = i;
            pivot = s[i];
            break;
        }
    }
    if (pivotPos == -1 && pivot == 0) return NULL;

    int L = pivotPos + 1;
    int R = len - 1;
    int minPos = -1;
    char min = CHAR_MAX;
    for (int i = R; i >= L; i--) {
        if (pivot < s[i]) {
            if (s[i] < min) {
                min = s[i];
                minPos = i;
            }
        }
    }

    char temp = s[pivotPos];
    s[pivotPos] = s[minPos];
    s[minPos] = temp;

    qsort(s + L, R - L + 1, sizeof(char), (int (*)(const void *, const void *))strcmp);

    return s;
}

int find(long dest, long *a, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
}

int nextPermutationArray(long *a, int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int swapIndex = find(a[i - 1], a, i, n - 1);
            long temp = a[swapIndex];
            a[swapIndex] = a[i - 1];
            a[i - 1] = temp;
            qsort(a + i, n - i, sizeof(long), (int (*)(const void *, const void *))strcmp);
            return 1;
        }
    }
    return 0;
}

void elimination(int **a, int *b, int n) {
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = -a[i][k] / (double)a[k][k];
            for (int j = k + 1; j < n; j++) {
                a[i][j] += f * a[k][j];
            }
            b[i] += f * b[k];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                b[i] -= a[i][j] * b[j];
            }
            b[i] = b[i] / a[i][i];
        }
    }
}

void solve() {
    FastScanner sc;
    sc.in = stdin;
    sc.ptr = 0;
    sc.buflen = 0;

    int n = nextInt(&sc);
    int m = nextInt(&sc);
    int map[1001] = {0};

    for (int i = 0; i < m; i++) {
        int s = nextInt(&sc);
        int c = nextInt(&sc);
        if (map[s] != 0 && map[s] != c) {
            printf("-1\n");
            exit(0);
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[10];
        sprintf(s, "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != 0 && map[j + 1] != s[j] - '0') || (map[j + 1] == 0 && s[j] - '0' != 0)) {
                if (map[j + 1] == 0 && j == 0 && s[j] - '0' == 1) {
                    continue;
                }
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            exit(0);
        }
    }

    printf("-1\n");
}

int main() {
    solve();
    return 0;
}
// End of Code
