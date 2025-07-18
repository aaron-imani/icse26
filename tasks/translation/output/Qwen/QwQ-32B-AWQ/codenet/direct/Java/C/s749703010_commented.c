#include <stdio.h>
#include <stdlib.h>

int n;
int **a;
int ***memo;

int dp(int fliped, int idx, int msk) {
    if (msk == ((1 << n) - 1)) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = 0;
    for (int k = 0; k < n; k++) {
        if (msk & (1 << k)) x++;
    }
    int ff = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int temp = ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i));
                if (temp < ans) ans = temp;
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[fliped][idx][msk] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);
    a = (int **)malloc(2 * sizeof(int *));
    a[0] = (int *)malloc(n * sizeof(int));
    a[1] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[0][i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[1][i]);
    }
    memo = (int ***)malloc(2 * sizeof(int **));
    for (int i = 0; i < 2; i++) {
        memo[i] = (int **)malloc((n + 1) * sizeof(int *));
        for (int j = 0; j <= n; j++) {
            memo[i][j] = (int *)malloc((1 << n) * sizeof(int));
            for (int k = 0; k < (1 << n); k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", (ans >= 1e9) ? -1 : ans);
    return 0;
}
// End of Code
