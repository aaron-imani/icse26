#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P 37
#define Q 47

int main() {
    int n;
    scanf("%d", &n);

    char **a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = (char *)malloc((n + 1) * sizeof(char));
        fgets(a[i], n + 1, stdin);
        a[i][strcspn(a[i], "\n")] = '\0';
    }

    long long powP[n + 1], powQ[n + 1];
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    long long hashRow[n][n];
    long long hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] =  RequestMethod: POST
hashCol[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod_jk = (j - k + n) % n;
                hashRow[i][k] += a[i][j] * powP[mod_jk];
                int mod_ik = (i - k + n) % n;
                hashCol[j][k] += a[i][j] * powP[mod_ik];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                int row_idx = (i + A) % n;
                int col_idx = (i + B) % n;
                if (hashRow[row_idx][B] != hashCol[col_idx][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
// End of Code
