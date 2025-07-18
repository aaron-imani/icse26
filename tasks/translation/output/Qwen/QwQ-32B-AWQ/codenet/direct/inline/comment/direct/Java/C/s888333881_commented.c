#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long mod_pow(long base, long exp, long mod) {
    long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

int count_bits(long x) {
    int count = 0;
    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char s[n + 1];
    fgets(s, n + 1, stdin);
    s[strcspn(s, "\n")] = '\0';

    char flaged[n];
    memset(flaged, 0, sizeof(flaged));
    long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long surp1 = 0, mod1 = pop1st + 1;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % mod1;
        if (flaged[i]) surp1 = (surp1 + 1) % mod1;
    }

    long surp9 = 0, mod9 = pop1st - 1;
    if (pop1st > 1) {
        surp9 = 0;
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2) % mod9;
            if (flaged[i]) surp9 = (surp9 + 1) % mod9;
        }
    }

    for (int p = 0; p < n; p++) {
        long dw;
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            dw = surp9;
            long exp = n - p - 1;
            long mod_val = mod9;
            long dif = mod_pow(2, exp, mod_val);
            dw = (dw - dif + mod_val) % mod_val;
            int ans = 1;
            while (dw != 0) {
                int cnt = count_bits(dw);
                dw %= cnt;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            dw = surp1;
            long exp = n - p - 1;
            long mod_val = mod1;
            long dif = mod_pow(2, exp, mod_val);
            dw = (dw + dif) % mod_val;
            int ans = 1;
            while (dw != 0) {
                int cnt = count_bits(dw);
                dw %= cnt;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
// End of Code
