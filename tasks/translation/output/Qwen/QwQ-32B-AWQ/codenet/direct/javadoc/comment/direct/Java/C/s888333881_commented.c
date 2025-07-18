#include <stdio.h>
#include <stdlib.h>

long long powmod(long long base, long long exponent, long long mod) {
    if (mod == 1) return 0;
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}

int count_set_bits(long long num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    bool *flaged = (bool *)malloc(n * sizeof(bool));
    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        flaged[i] = (s[i] == '1');
        if (flaged[i]) pop1st++;
    }

    long long surp1 = 0;
    long long mod_surp1 = pop1st + 1;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2 + (flaged[i] ? 1 : 0)) % mod_surp1;
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        long long mod_surp9 = pop1st - 1;
        surp9 = 0;
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2 + (flaged[i] ? 1 : 0)) % mod_surp9;
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;
            long long mod = pop1st - 1;
            long long dif = powmod(2, n - p - 1, mod);
            dw -= dif;
            dw += mod;
            dw %= mod;
            int ans = 1;
            while (dw != 0) {
                int count = count_set_bits(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long mod = pop1st + 1;
            long long dif = powmod(2, n - p - 1, mod);
            dw += dif;
            dw %= mod;
            int ans = 1;
            while (dw != 0) {
                int count = count_set_bits(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    free(flaged);
    return 0;
}
// End of Code
