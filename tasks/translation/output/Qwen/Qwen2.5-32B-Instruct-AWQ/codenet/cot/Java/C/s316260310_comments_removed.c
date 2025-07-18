#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long MOD;
    int MAXN;
    int *sieve;
    int *factorial;
    int *primes;
    int primesSize;
} Helper;

Helper *createHelper(long mod, int maxn) {
    Helper *hp = (Helper *)malloc(sizeof(Helper));
    hp->MOD = mod;
    hp->MAXN = maxn;
    hp->sieve = (int *)malloc(maxn * sizeof(int));
    hp->factorial = (long *)malloc(maxn * sizeof(long));
    hp->primes = (int *)malloc(maxn * sizeof(int));
    hp->primesSize = 0;
    return hp;
}

void setSieve(Helper *hp) {
    int i, j;
    memset(hp->sieve, 0, hp->MAXN * sizeof(int));
    for (i = 2; i < hp->MAXN; ++i)
        if (hp->sieve[i] == 0) {
            hp->primes[hp->primesSize++] = i;
            for (j = i; j < hp->MAXN; j += i) {
                hp->sieve[j] = i;
            }
        }
}

void setFactorial(Helper *hp) {
    hp->factorial[0] = 1;
    for (int i = 1; i < hp->MAXN; ++i) hp->factorial[i] = hp->factorial[i - 1] * i % hp->MOD;
}

long getFactorial(Helper *hp, int n) {
    if (hp->factorial == NULL) setFactorial(hp);
    return hp->factorial[n];
}

long ncr(Helper *hp, int n, int r) {
    if (r > n) return 0;
    if (hp->factorial == NULL) setFactorial(hp);
    long numerator = hp->factorial[n];
    long denominator = hp->factorial[r] * hp->factorial[n - r] % hp->MOD;
    return numerator * pow(denominator, hp->MOD - 2, hp->MOD) % hp->MOD;
}

long *getLongArray(Helper *hp, int size) {
    long *ar = (long *)malloc(size * sizeof(long));
    for (int i = 0; i < size; ++i) ar[i] = nextLong(hp);
    return ar;
}

int *getIntArray(Helper *hp, int size) {
    int *ar = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) ar[i] = nextInt(hp);
    return ar;
}

char **getStringArray(Helper *hp, int size) {
    char **ar = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; ++i) ar[i] = next(hp);
    return ar;
}

char *joinElements(long *ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) sprintf(sb + strlen(sb), "%ld ", ar[i]);
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *joinElements(int *ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) sprintf(sb + strlen(sb), "%d ", ar[i]);
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *joinElements(char **ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) sprintf(sb + strlen(sb), "%s ", ar[i]);
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

char *joinElements(void *ar, int size) {
    char *sb = (char *)malloc(size * 20 * sizeof(char));
    for (int i = 0; i < size; ++i) sprintf(sb + strlen(sb), "%d ", ((int *)ar)[i]);
    sb[strlen(sb) - 1] = '\0';
    return sb;
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long max(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret > ar[i] ? ret : ar[i];
    return ret;
}

int max(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret > ar[i] ? ret : ar[i];
    return ret;
}

long min(long *ar, int size) {
    long ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret < ar[i] ? ret : ar[i];
    return ret;
}

int min(int *ar, int size) {
    int ret = ar[0];
    for (int i = 1; i < size; ++i) ret = ret < ar[i] ? ret : ar[i];
    return ret;
}

long sum(long *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) sum += ar[i];
    return sum;
}

long sum(int *ar, int size) {
    long sum = 0;
    for (int i = 0; i < size; ++i) sum += ar[i];
    return sum;
}

void shuffle(int *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = rand() % size;
        if (r != i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void shuffle(long *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = rand() % size;
        if (r != i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void reverse(int *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = size - 1 - i;
        if (r > i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

void reverse(long *ar, int size) {
    int r;
    for (int i = 0; i < size; ++i) {
        r = size - 1 - i;
        if (r > i) {
            ar[i] ^= ar[r];
            ar[r] ^= ar[i];
            ar[i] ^= ar[r];
        }
    }
}

long pow(long base, long exp, long MOD) {
    base %= MOD;
    long ret = 1;
    while (exp > 0) {
        if ((exp & 1) == 1) ret = ret * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return ret;
}

#define BUFSIZE (1 << 20)
char buf[BUFSIZE];
int index = 0, total = 0;
FILE *in, *out;

void initIO(FILE *is, FILE *os) {
    in = is;
    out = os;
    buf[0] = 0;
    index = total = 0;
}

char *next(Helper *hp) {
    int c;
    for (c = fgetc(in); c <= 32; c = fgetc(in)) ;
    char *sb = (char *)malloc(20 * sizeof(char));
    int i = 0;
    for (; c > 32; c = fgetc(in))
        sb[i++] = c;
    sb[i] = '\0';
    return sb;
}

int nextInt(Helper *hp) {
    int c, val = 0;
    for (c = fgetc(in); c <= 32; c = fgetc(in)) ;
    int neg = c == '-';
    if (c == '-' || c == '+')
        c = fgetc(in);
    for (; c >= '0' && c <= '9'; c = fgetc(in))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

long nextLong(Helper *hp) {
    int c;
    long val = 0;
    for (c = fgetc(in); c <= 32; c = fgetc(in)) ;
    int neg = c == '-';
    if (c == '-' || c == '+')
        c = fgetc(in);
    for (; c >= '0' && c <= '9'; c = fgetc(in))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

void print(Helper *hp, void *a) {
    fprintf(out, "%s", (char *)a);
}

void printsp(Helper *hp, void *a) {
    print(hp, a);
    print(hp, " ");
}

void println(Helper *hp) {
    fprintf(out, "\n");
}

void println(Helper *hp, void *a) {
    print(hp, a);
    println(hp);
}

void flush(Helper *hp) {
    fflush(out);
}

void run(Helper *hp) {
    try {
        solve(hp);
        exit(0);
    } catch (Exception | Error e) {
        e.printStackTrace();
        exit(1);
    }
}

void solve(Helper *hp) {
    int tc = hp->TESTCASES ? nextInt(hp) : 1;
    for (int tce = 1; tce <= tc; ++tce) solve(hp, tce);
    hp->flush();
}

void solve(Helper *hp, int tc) {
    int N = nextInt(hp);
    long K = nextLong(hp);
    int *A = getIntArray(hp, N);

    int *straight = (int *)malloc(N * sizeof(int));
    int *cycle = (int *)malloc(N * sizeof(int));
    int *vis = (int *)malloc(N * sizeof(int));
    memset(vis, 0, N * sizeof(int));
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }

    int st = 0;
    while (st != curr) {
        straight[st] = st;
        st = A[st] - 1;
    }

    cycle[0] = curr;
    curr = A[curr] - 1;
    int cycleSize = 1;
    while (curr != cycle[0]) {
        cycle[cycleSize++] = curr;
        curr = A[curr] - 1;
    }

    if (K < st) {
        println(hp, straight[K] + 1);
    } else {
        K -= st;
        println(hp, cycle[K % cycleSize] + 1);
    }
}

int main() {
    Helper *hp = createHelper(MOD, MAXN);
    initIO(stdin, stdout);
    hp->setSieve();
    hp->setFactorial();
    run(hp);
    return 0;
}
// End of Code
