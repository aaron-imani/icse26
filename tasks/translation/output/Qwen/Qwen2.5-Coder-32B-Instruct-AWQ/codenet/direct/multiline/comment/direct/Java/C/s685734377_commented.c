#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

long pow_mod(long base, long exp, long mod) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    char a[MAXN][MAXN];
    long P = 37, Q = 47;
    long powP[MAXN + 1], powQ[MAXN + 1];
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = (powP[i - 1] * P) % 1000000007;
        powQ[i] = (powQ[i - 1] * Q) % 1000000007;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    long hashRow[MAXN][MAXN], hashCol[MAXN][MAXN];
    memset(hashRow, 0, sizeof(hashRow));
    memset(hashCol, 0, sizeof(hashCol));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] = (hashRow[i][k] + ((a[i][j] - 'a') * powP[(j - k + n) % n]) % 1000000007) % 1000000007;
                hashCol[j][k] = (hashCol[j][k] + ((a[i][j] - 'a') * powP[(i - k + n) % n]) % 1000000007) % 1000000007;
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);

    return 0;
}
// End of Code
