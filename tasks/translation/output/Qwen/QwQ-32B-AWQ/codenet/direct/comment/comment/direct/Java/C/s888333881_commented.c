#include <stdio.h>
#include <stdbool.h>

int bit_count(long long n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    int flaged[n];
    int pop1st = 0;
    for (int i = 0; i < n; i++) {
        flaged[i] = (s[i] == '1') ? 1 : 0;
        if (flaged[i]) {
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % (pop1st + 1);
        if (flaged[i]) {
            surp1 = (surp1 + 1) % (pop1st + 1);
        }
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2) % (pop1st - 1);
            if (flaged[i]) {
                surp9 = (surp9 + 1) % (pop1st - 1);
            }
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;
            int exponent = n - p - 1;
            long long mod = pop1st - 1;
            long long diff = pow_mod(2, exponent, mod);
            dw = (dw - diff) % mod;
            if (dw < 0) {
                dw += mod;
            }
            int ans = 1;
            while (dw != 0) {
                int count = bit_count(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            int exponent = n - p - 1;
            long long mod = pop1st + 1;
            long long diff = pow_mod(2, exponent, mod);
            dw = (dw + diff) % mod;
            int ans = 1;
            while (dw != 0) {
                int count = bit_count(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
// End of Code
