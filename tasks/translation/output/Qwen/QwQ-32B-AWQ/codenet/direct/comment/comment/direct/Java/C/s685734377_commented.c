#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    char **grid = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        grid[i] = (char *)malloc((n + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    long long P = 37, Q = 47;
    long long *powP = (long long *)malloc((n + 1) * sizeof(long long));
    long long *powQ = (long long *)malloc((n + 1) * sizeof(long long));
    powP[0] = 1;
    powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * P;
        powQ[i] = powQ[i - 1] * Q;
    }

    long long **hashRow = (long long **)malloc(n * sizeof(long long *));
    long long **hashCol = (long long **)malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++) {
        hashRow[i] = (long long *)calloc(n, sizeof(long long));
        hashCol[i] = (long long *)calloc(n, sizeof(long long));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int mod_p = (j - k + n) % n;
                hashRow[i][k] += grid[i][j] * powP[mod_p];
                int mod_q = (i - k + n) % n;
                hashCol[j][k] += grid[i][j] * powP[mod_q];
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
            if (ok) ans++;
        }
    }
    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
        free(hashRow[i]);
        free(hashCol[i]);
    }
    free(grid);
    free(hashRow);
    free(hashCol);
    free(powP);
    free(powQ);
    return 0;
}
// End of Code
