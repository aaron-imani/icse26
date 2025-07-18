#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 100000000
#define INFL 10000000000000000LL
#define e97 1000000007LL

int abs(int a) { return (a >= 0) ? a : -a; }
long long abs(long long a) { return (a >= 0) ? a : -a; }

int min(int a, int b) { return (a > b) ? b : a; }
long long min(long long a, long long b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a > b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }

int minN(int *ins, int size) {
    int min = ins[0];
    for (int i = 1; i < size; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long long minN(long long *ins, int size) {
    long long min = ins[0];
    for (int i = 1; i < size; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int getDigit2(long long num) {
    long long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    long long ob_pow_2pow[d];
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long long bit) {
    int ans = 0;
    for (long long i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    bool flaged[n];
    memset(flaged, false, sizeof(flaged));

    long long pop1st = 0LL;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2LL;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0LL;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2LL;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;
            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

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
