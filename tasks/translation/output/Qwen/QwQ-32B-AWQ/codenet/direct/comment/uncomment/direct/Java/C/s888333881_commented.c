#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Edge {
    int from;
    int v2;
    long weight;
};

struct Edge2 {
    int v2;
    long cost1, cost2;
};

struct Vector {
    int x, y;
};

#define INF 100000000
#define INFL 10000000000000000LL
#define e97 1000000007LL

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    long result = 1;
    ob %= p;
    while (soeji > 0) {
        if (soeji % 2 == 1) {
            result = (result * ob) % p;
        }
        ob = (ob * ob) % p;
        soeji /= 2;
    }
    return result % p;
}

int countFlaged(long dw) {
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

    bool flaged[n];
    for (int i = 0; i < n; i++) {
        flaged[i] = false;
    }

    long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long surp1 = 0;
    long mod1 = pop1st + 1;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2 + (flaged[i] ? 1 : 0)) % mod1;
    }

    long surp9 = 0;
    if (pop1st > 1) {
        long mod9 = pop1st - 1;
        for (int i = 0; i < n; i++) {
            surp9 = (surp9 * 2 + (flaged[i] ? 1 : 0)) % mod9;
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
                int cnt = countFlaged(dw);
                dw %= cnt;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;
            long dif = pow10E97(2, n - p - 1, mod1);
            dw += dif;
            dw %= mod1;
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
