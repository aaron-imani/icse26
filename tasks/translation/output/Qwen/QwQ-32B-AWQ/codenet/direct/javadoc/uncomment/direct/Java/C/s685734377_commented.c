#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char **a = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(n * sizeof(char));
    }

    char line[1024];
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j];
        }
    }

    const long long P = 37;
    long long *powP = malloc((n + 1) * sizeof(long long));
    powP[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
    }

    long long **hashRow = malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = calloc(n, sizeof(long long));
    }

    long long **hashCol = malloc(n * sizeof(long long *));
    for (int j = 0; j < n; j++) {
        hashCol[j] = calloc(n, sizeof(long long));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod_jk = (j - k + n) % n;
                long long term = (unsigned char)a[i][j] * powP[mod_jk];
                hashRow[i][k] += term;

                int mod_ik = (i - k + n) % n;
                term = (unsigned char)a[i][j] * powP[mod_ik];
                hashCol[j][k] += term;
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
            ans += ok;
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    free(powP);
    for (int i = 0; i < n; i++) free(hashRow[i]);
    free(hashRow);
    for (int j = 0; j < n; j++) free(hashCol[j]);
    free(hashCol);

    return 0;
}
// End of Code
