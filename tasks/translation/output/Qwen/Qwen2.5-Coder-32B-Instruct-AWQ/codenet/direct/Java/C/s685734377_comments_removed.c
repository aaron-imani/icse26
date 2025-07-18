#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

long powP[MAXN + 1], powQ[MAXN + 1];

void precompute_powers(long P, long Q, int n) {
    powP[0] = powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char a[MAXN][MAXN];
    long hashRow[MAXN][MAXN], hashCol[MAXN][MAXN];
    long P = 37, Q = 47;

    precompute_powers(P, Q, n);

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    memset(hashRow, 0, sizeof(hashRow));
    memset(hashCol, 0, sizeof(hashCol));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
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
