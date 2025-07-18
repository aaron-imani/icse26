#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char a[n][n];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    long long powP[n + 1];
    long long powQ[n + 1];
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * 37;
        powQ[i] = powQ[i - 1] * 47;
    }

    long long hashRow[n][n];
    long long hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int exp = (j - k + n) % n;
                hashRow[i][k] += a[i][j] * powP[exp];
                exp = (i - k + n) % n;
                hashCol[j][k] += a[i][j] * powP[exp];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row_i = (i + A) % n;
                int col_i = (i + B) % n;
                if (hashRow[row_i][B] != hashCol[col_i][A]) {
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
