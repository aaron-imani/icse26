#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int from;
    int v2;
    long weight;
};

struct Edge2 {
    int v2;
    long cost1;
    long cost2;
};

struct Vector {
    int x;
    int y;
};

struct Node0n {
    int *next_vs;
    int size;
    int capacity;
};

struct Graph0n {
    struct Node0n *dt;
    int size;
};

int count_set_bits(long num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

long pow_mod(long base, long exponent, long mod) {
    if (mod == 1) return 0;
    long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);

    char flaged[n];
    memset(flaged, 0, n);
    long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 = (surp1 * 2) % (pop1st + 1);
        if (flaged[i]) {
            surp1 = (surp1 + 1) % (pop1st + 1);
        }
    }

    long surp9 = 0;
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
            long dw = surp9;
            long dif = pow_mod(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw = (dw % (pop1st - 1) + (pop1st - 1)) % (pop1st - 1);
            int ans = 1;
            while (dw != 0) {
                int cnt = count_set_bits(dw);
                if (cnt == 0) {
                    printf("Error: division by zero\n");
                    exit(1);
                }
                dw %= cnt;
                ans++;
                if (dw < 0) {
                    printf("Error: negative value\n");
                    exit(1);
                }
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;
            long dif = pow_mod(2, n - p - 1, pop1st + 1);
            dw = (dw + dif) % (pop1st + 1);
            int ans = 1;
            while (dw != 0) {
                int cnt = count_set_bits(dw);
                if (cnt == 0) {
                    printf("Error: division by zero\n");
                    exit(1);
                }
                dw %= cnt;
                ans++;
                if (dw < 0) {
                    printf("Error: negative value\n");
                    exit(1);
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
// End of Code
