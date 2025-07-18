#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF (LONG_MAX / 2)
#define MOD 1000000007
#define SIZE 1000000

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

typedef struct {
    long a, b;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pa = (Pair *)a;
    Pair *pb = (Pair *)b;
    if (pa->b < pb->b) return -1;
    else if (pa->b > pb->b) return 1;
    else return 0;
}

int nextByte() {
    static char buf[1024];
    static size_t pos = 0, len = 0;
    if (pos == len) {
        len = fread(buf, 1, 1024, stdin);
        pos = 0;
    }
    return pos < len ? buf[pos++] : -1;
}

int nextInt() {
    int c = nextByte();
    while (c != -1 && (c < '0' || c > '9')) c = nextByte();
    int n = 0;
    while (c != -1 && '0' <= c && c <= '9') {
        n = n * 10 + (c - '0');
        c = nextByte();
    }
    return n;
}

void solve() {
    int n = nextInt();
    int m = nextInt();
    int map[1001] = {0};

    for (int i = 0; i < m; i++) {
        int s = nextInt();
        int c = nextInt();
        if (map[s] != 0 && map[s] != c) {
            printf("-1\n");
            exit(0);
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[4];
        sprintf(s, "%d", i);
        int flag = 1;
        if (strlen(s) < n) continue;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != 0 && map[j + 1] != s[j] - '0') || (map[j + 1] == 0 && s[j] - '0' != 0)) {
                if (map[j + 1] == 0 && j == 0 && s[j] - '0' == 1) continue;
                flag = 0;
                break;
            }
        }
        if (flag && strlen(s) == n) {
            printf("%s\n", s);
            exit(0);
        }
    }

    printf("-1\n");
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long inv(long a) {
    return pow(a, MOD - 2);
}

long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
        if ((r & 1) == 1) {
            sum *= a;
            sum %= MOD;
        }
        a *= a;
        a %= MOD;
        r >>= 1;
    }
    return sum;
}

long modFact(long n) {
    return n == 0 ? 1 : n * modFact(n - 1) % MOD;
}

long fact(long n) {
    return n == 0 ? 1 : n * fact(n - 1);
}

void initCOMB() {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long modComb(int n, int r) {
    return n < r || n < 0 || r < 0 ? 0 : fac[n] * finv[r] % MOD * finv[n - r] % MOD;
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
    char min = 127;
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
    qsort(s + L, R - L + 1, sizeof(char), compare);

    return s;
}

int nextPermutation(long *a, int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int swapIndex = find(a[i - 1], a, i, n - 1);
            long temp = a[swapIndex];
            a[swapIndex] = a[i - 1];
            a[i - 1] = temp;
            qsort(a + i, n - i, sizeof(long), compare);
            return 1;
        }
    }
    return 0;
}

int find(long dest, long *a, int s, int e) {
    if (s == e) return s;
    int m = (s + e + 1) / 2;
    return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
}

void elimination(int **a, int *b, int n) {
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = -a[i][k] / a[k][k];
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

int main() {
    solve();
    return 0;
} // End of Code
