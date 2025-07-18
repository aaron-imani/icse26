#include <stdio.h>
#include <stdlib.h>

long pow_mod(long base, long exponent, long mod) {
    if (mod == 1) return 0;
    long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int count_set_bits(long dw) {
    int count = 0;
    while (dw != 0) {
        count += dw & 1;
        dw >>= 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    
    int flaged[n];
    for (int i = 0; i < n; i++) {
        flaged[i] = (s[i] == '1');
    }
    
    long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (flaged[i]) pop1st++;
    }
    
    long surp1 = 0;
    long mod_s1 = pop1st + 1;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % mod_s1;
        if (flaged[i]) {
            surp1 = (surp1 + 1) % mod_s1;
        }
    }
    
    long surp9 = 0;
    long mod_s9 = pop1st - 1;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2) % mod_s9;
            if (flaged[i]) {
                surp9 = (surp9 + 1) % mod_s9;
            }
        }
    }
    
    for (int p = 0; p < n; p++) {
        long ans = 1;
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long dw = surp9;
            long exponent = n - p - 1;
            long mod_value = mod_s9;
            long pow_val = pow_mod(2, exponent, mod_value);
            dw = (dw - pow_val + mod_value) % mod_value;
            while (dw != 0) {
                int count = count_set_bits(dw);
                if (count == 0) break;
                dw %= count;
                ans++;
            }
            printf("%ld\n", ans);
        } else {
            long dw = surp1;
            long exponent = n - p - 1;
            long mod_value = mod_s1;
            long pow_val = pow_mod(2, exponent, mod_value);
            dw = (dw + pow_val) % mod_value;
            while (dw != 0) {
                int count = count_set_bits(dw);
                if (count == 0) break;
                dw %= count;
                ans++;
            }
            printf("%ld\n", ans);
        }
    }
    return 0;
}
// End of Code
