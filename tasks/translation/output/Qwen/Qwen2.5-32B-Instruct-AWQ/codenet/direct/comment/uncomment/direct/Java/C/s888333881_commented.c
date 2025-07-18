#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000000
#define INFL 1000000000000000000LL
#define e97 1000000007LL

typedef struct {
    int x, y;
} Vector;

typedef struct {
    int from, v2;
    long weight;
} Edge;

typedef struct {
    int v2;
    long cost1, cost2;
} Edge2;

void fill(int *ob, int len, int res) {
    for (int i = 0; i < len; i++) {
        ob[i] = res;
    }
}

int abs(int a) {
    return (a >= 0) ? a : -a;
}

long abs(long a) {
    return (a >= 0) ? a : -a;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

long min(long a, long b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long max(long a, long b) {
    return (a > b) ? a : b;
}

int minN(int *ins, int len) {
    int min = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long minN(long *ins, int len) {
    long min = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN(int *ins, int len) {
    int max = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

long maxN(long *ins, int len) {
    long max = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd(int *dt, int len, int ad) {
    int min = INF;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

long minExAd(long *dt, int len, int ad) {
    long min = INFL;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int minExVal(int *dt, int len, int ex_val) {
    int min = INF;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

long minExVal(long *dt, int len, long ex_val) {
    long min = INFL;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int maxExAd(int *dt, int len, int ad) {
    int max = -INF;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

long maxExAd(long *dt, int len, int ad) {
    long max = -INFL;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int maxExVal(int *dt, int len, int ex_val) {
    int max = -INF;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

long maxExVal(long *dt, int len, long ex_val) {
    long max = -INFL;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int sumA(int *dt, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

long sumA(long *dt, int len) {
    long sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

double hypod(double a, double b) {
    return sqrt(a * a + b * b);
}

long factorial(int n) {
    long ans = 1;
    for (int i = n; i > 0; i--) {
        ans *= i;
    }
    return ans;
}

long facP(int n, long p) {
    long ans = 1;
    for (int i = n; i > 0; i--) {
        ans *= i;
        ans %= p;
    }
    return ans;
}

long lcm(long m, long n) {
    long ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

long pow(long n, int k) {
    long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2(int in) {
    return in * in;
}

long pow2(long in) {
    return in * in;
}

double pow2(double in) {
    return in * in;
}

int getDigit2(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d; // numはd桁の数で、2^dより小さい
}

int getDigit10(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d; // numはd桁の数で、10^dより小さい
}

int is_prime(long a) {
    if (a == 1) return 0;
    for (long i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

long modinv(long a, long p) {
    long b = p, u = 1, v = 0;
    while (b > 0) {
        long t = a / b;
        long pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    long *ob_pow_2pow = malloc(d * sizeof(long));

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

int countFlaged(long bit) {
    int ans = 0;
    for (long i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    int flaged[n];
    fill(flaged, n, 0);

    long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long dw = surp9;

            long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;

            long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

// End of Code
