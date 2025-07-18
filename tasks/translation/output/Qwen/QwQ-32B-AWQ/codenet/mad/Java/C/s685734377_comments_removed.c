#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char a[n][n+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    long long P = 37, Q = 47;
    long long powP[n+1], powQ[n+1];
    powP[0] = powQ[0] = 1;
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
            for (int k = 翻译结果 0; k < n; k++) {
                int modP = (j - k + n) % n;
                hashRow[i][k] += (unsigned char)a[i][j] * powP[modP];
                int modC = (i - k + n) % n;
                hashCol[j][k] += (unsigned char)a[i][j] * powP[modC];
            }
        }
    }
    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row = (i + A) % n;
                int col = (i + B) % n;
                if (hashRow[row][B] != hashCol[col][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);
} // End of Code
