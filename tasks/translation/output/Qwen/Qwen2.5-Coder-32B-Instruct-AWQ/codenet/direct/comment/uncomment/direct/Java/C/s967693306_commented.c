#include <stdio.h>
#include <stdlib.h>

#define INF 9223372036854775803L
#define MOD 1000000007
#define SIZE 1000000

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

typedef struct {
    long a;
    long b;
} Pair;

int compare_pairs(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    if (pa.b < pb.b) return -1;
    else if (pa.b > pb.b) return 1;
    else return 0;
}

int is_printable_char(int c) {
    return 33 <= c && c <= 126;
}

int has_next_byte(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    if (*ptr < *buflen) {
        return 1;
    } else {
        *ptr = 0;
        *buflen = fread(buffer, 1, sizeof(buffer), in);
        if (*buflen <= 0) {
            return 0;
        }
    }
    return 1;
}

int read_byte(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    if (has_next_byte(in, buffer, ptr, buflen)) return buffer[(*ptr)++];
    else return -1;
}

int has_next(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    while (has_next_byte(in, buffer, ptr, buflen) && !is_printable_char(buffer[*ptr])) (*ptr)++;
    return has_next_byte(in, buffer, ptr, buflen);
}

char *next(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    if (!has_next(in, buffer, ptr, buflen)) exit(EXIT_FAILURE);
    char *sb = (char *)malloc(1024);
    int b = read_byte(in, buffer, ptr, buflen);
    int len = 0;
    while (is_printable_char(b)) {
        sb[len++] = b;
        b = read_byte(in, buffer, ptr, buflen);
    }
    sb[len] = '\0';
    return sb;
}

long next_long(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    if (!has_next(in, buffer, ptr, buflen)) exit(EXIT_FAILURE);
    long n = 0;
    int minus = 0;
    int b = read_byte(in, buffer, ptr, buflen);
    if (b == '-') {
        minus = 1;
        b = read_byte(in, buffer, ptr, buflen);
    }
    if (b < '0' || '9' < b) {
        exit(EXIT_FAILURE);
    }
    while (1) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !is_printable_char(b)) {
            return minus ? -n : n;
        } else {
            exit(EXIT_FAILURE);
        }
        b = read_byte(in, buffer, ptr, buflen);
    }
}

int next_int(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    long nl = next_long(in, buffer, ptr, buflen);
    if (nl < INT_MIN || nl > INT_MAX) exit(EXIT_FAILURE);
    return (int) nl;
}

double next_double(FILE *in, unsigned char buffer[], int *ptr, int *buflen) {
    char *str = next(in, buffer, ptr, buflen);
    double result = atof(str);
    free(str);
    return result;
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long lcm(long a, long b) {
    return a * b / gcd(a, b);
}

long mod_inverse(long a, long mod) {
    long m0 = mod, t, q;
    long x0 = 0, x1 = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long mod_pow(long a, long r, long mod) {
    long res = 1;
    a = a % mod;
    while (r > 0) {
        if (r & 1) res = (res * a) % mod;
        r = r >> 1;
        a = (a * a) % mod;
    }
    return res;
}

long mod_fact(long n, long mod) {
    if (n == 0) return 1;
    return (n * mod_fact(n - 1, mod)) % mod;
}

long fact(long n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

void init_comb(long mod) {
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = mod - (inv[mod % i] * (mod / i)) % mod;
        finv[i] = (finv[i - 1] * inv[i]) % mod;
    }
}

long mod_comb(int n, int r, long mod) {
    if (n < r || n < 0 || r < 0) return 0;
    return (((fac[n] * finv[r]) % mod) * finv[n - r]) % mod;
}

long comb(long n, long r) {
    long num = 1;
    for (long i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int is_prime(long a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

void elimination(int **a, int *b, int n) {
    double f;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            f = - (double)a[i][k] / a[k][k];
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
    FILE *in = stdin;
    unsigned char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    int n = next_int(in, buffer, &ptr, &buflen);
    int m = next_int(in, buffer, &ptr, &buflen);
    int *map = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) map[i] = -1;

    for (int i = 0; i < m; i++) {
        int s = next_int(in, buffer, &ptr, &buflen);
        int c = next_int(in, buffer, &ptr, &buflen);
        if (map[s] != -1 && map[s] != c) {
            printf("-1\n");
            free(map);
            fclose(in);
            return 0;
        }
        map[s] = c;
    }

    for (int i = 0; i < 1000; i++) {
        char s[10];
        snprintf(s, sizeof(s), "%d", i);
        int len = strlen(s);
        if (len < n) continue;
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if ((map[j + 1] != -1 && map[j + 1] != s[j] - '0') || (map[j + 1] == -1 && s[j] - '0' != 0)) {
                if (map[j + 1] == -1 && j == 0 && s[j] - '0' == 1) {
                    continue;
                }
                flag = 0;
                break;
            }
        }
        if (flag && len == n) {
            printf("%s\n", s);
            free(map);
            fclose(in);
            return 0;
        }
    }

    printf("-1\n");
    free(map);
    fclose(in);
    return 0;
}
// End of Code
