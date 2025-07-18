#include <stdio.h>
#include <stdlib.h>

long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int countFlaged(long long n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
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
        flaged[i] = (s[i] == '1') ? 1 : 0;
    }

    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (flaged[i]) pop1st++;
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
        surp9 = 0;
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
            long long pow_val = pow_mod(2, n - p - 1, pop1st - 1);
            dw = (dw - pow_val) % (pop1st - 1);
            if (dw < 0) dw += (pop1st - 1);
            dw = (dw + (pop1st - 1)) % (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                int cnt = countFlaged(dw);
                dw %= cnt;
                ans++;
                if (dw < 0) {
                    printf("1/0\n");
                    return 1;
                }
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long pow_val = pow_mod(2, n - p - 1, pop1st + 1);
            dw = (dw + pow_val) % (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                int cnt = countFlaged(dw);
                dw %= cnt;
                ans++;
                if (dw < 0) {
                    printf("1/0\n");
                    return 知道自己是正确的。0;
                    return 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
} // End of Code
