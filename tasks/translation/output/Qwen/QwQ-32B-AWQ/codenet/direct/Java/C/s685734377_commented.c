#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char grid[n][n+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    long long P = 37, Q = 47;
    long long powP[n+1], powQ[n+1];
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i-1] * P;
        powQ[i] = powQ[i-1] * Q;
    }

    long long hashRow[n][n], hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod_jk = (j - k + n) % n;
                hashRow[i][k] += ( (long long)( (unsigned char)grid[i][j] ) ) * powP[mod_jk];
                int mod_ik = (i - k + n) % n;
                hashCol[j][k] += ( (long long)( (unsigned char)grid[i][j] ) ) * powP[mod_ik];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row_iA = (i + A) % n;
                int col_iB = (i + B) % n;
                if (hashRow[row_iA][B] != hashCol[col_iB][A]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
