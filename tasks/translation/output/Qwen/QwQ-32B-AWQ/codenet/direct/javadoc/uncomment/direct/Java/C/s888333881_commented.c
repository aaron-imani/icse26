#include <stdio.h>
#include <string.h>

int modpow(int base, int exp, int mod) {
    if (mod == 1) return 0;
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int count_set_bits(int num) {
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

    int flaged[n];
    int pop1st = 0;
    for (int i = 0; i < n; i++) {
        flaged[i] = (s[i] == '1');
        pop1st += flaged[i];
    }

    int mod1 = pop1st + 1;
    int surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % mod1;
        if (flaged[i]) {
            surp1 = (surp1 + 1) % mod1;
        }
    }

    int surp9 = 0;
    if (pop1st > 1) {
        int mod2 = pop1st - 1;
        surp9 = 0;
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2) % mod2;
            if (flaged[i]) {
                surp9 = (surp9 + 1) % mod2;
            }
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            int mod2 = pop1st - 1;
            int dw = surp9;
            int exponent = n - p - 1;
            int dif = modpow(2, exponent, mod2);
            dw -= dif;
            dw %= mod2;
            if (dw < 0) dw += mod2;
            int ans = 1;
            while (dw != 0) {
                int count = count_set_bits(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            int mod1_val = mod1;
            int dw = surp1;
            int exponent = n - p - 1;
            int dif = modpow(2, exponent, mod1_val);
            dw += dif;
            dw %= mod1_val;
            if (dw < 0) dw += mod1_val;
            int ans = 1;
            while (dw != 0) {
                int count = count_set_bits(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
// End of Code
