#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    int n;
    scanf("%d", &n);

    char a[n][n];
    for (int i = 0; i < n; i++) {
        char line[n + 1];
        fgets(line, n + 1, stdin);
        line[strcspn(line, "\n")] = '\0';
        for (int j = 0; j < n; j++) {
            a[i][j] = line[j];
        }
    }

    uint64_t powP[n + 1];
    powP[0] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i] = powP[i - 1] * 37;
    }

    uint64_t hashRow[n][n];
    uint64_t hashCol[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hashRow[i][j] = 0;
            hashCol[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int exponent1 = (j - k + n) % n;
                hashRow[i][k] += (uint64_t)a[i][j] * powP[exponent1];

                int exponent2 = (i - k + n) % n;
                hashCol[j][k] += (uint64_t)a[i][j] * powP[exponent2];
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
    return 0;
}
// End of Code
