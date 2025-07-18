#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF (int)1e8
#define INFL (long long)1e17
#define e97 ((long long)1e9 +7)

int getDigit2(long long num) {
    int d = 0;
    long long cf = 1;
    while (num >= cf) {
        d++;
        cf <<= 1;
    }
    return d;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;
    int d = getDigit2(soeji);
    long long ob_pow_2pow[64];
    ob_pow_2pow[0] = ob % p;
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
    while (bit != 0) {
        ans += bit & 1;
        bit >>= 1;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);
    
    char flaged[n];
    for (int i = 0; i < n; i++) {
        flaged[i] = (s[i] == '1');
    }
    
    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (flaged[i]) pop1st++;
    }
    
    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }
    
    long long surp9 = 0;
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
            long long dw = surp9;
            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            
            int ans = 1;
            while (dw != 0) {
                int cnt = countFlaged(dw);
                dw %= cnt;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);
            
            int ans = 1;
            while (dw != 0) {
                int cnt = countFlaged(dw);
                dw %= cnt;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
// End of Code
