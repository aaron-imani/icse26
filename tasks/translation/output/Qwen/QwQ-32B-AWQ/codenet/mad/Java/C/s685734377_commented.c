#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // consume the newline after the number
    char a[n][n];
    char buffer[1024];
    for (int i = 0; i < n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        for (int j = 0; j < n; j++) {
            a[i][j] = buffer[j];
        }
    }

    long long powP[n+1];
    long long powQ[n+1];
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i-1] * 37;
        powQ[i] = powQ[i-1] * 47;
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
                int mod1 = (j - k + n) % n;
                hashRow[i][k] += (long long)a[i][j] * powP[mod1];
                int mod2 = (i - k + n) % n;
                hashCol[j][k] += (long long)a[i][j] * powP[mod2];
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
} // End of Code
