#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int **a;
int ***memo;

int dp(int fliped, int idx, int msk);

int main() {
    scanf("%d", &n);
    a = (int **)malloc(2 * sizeof(int *));
    a[0] = (int *)malloc(n * sizeof(int));
    a[1] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);

    memo = (int ***)malloc(2 * sizeof(int **));
    for (int f = 0; f < 2; f++) {
        memo[f] = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i <= n; i++) {
            memo[f][i] = (int *)malloc((1 << n) * sizeof(int));
            memset(memo[f][i], -1, (1 << n) * sizeof(int));
        }
    }

    int ans = dp(0, n, 0);

    if (ans >= 1000000000) printf("-1\n");
    else printf("%d\n", ans);

    for (int f = 0; f < 2; f++) {
        for (int i = 0; i <= n; i++) {
            free(memo[f][i]);
        }
        free(memo[f]);
    }
    free(memo);

    free(a[0]);
    free(a[1]);
    free(a);

    return 0;
}

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = 0;
    for (int tmp = msk; tmp; tmp &= tmp - 1) x++;
    int ff = 0;
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int new_flip = (nf + (ff % 2)) % 2;
            if (idx == n || a[fliped][idx] <= a[new_flip][i]) {
                int res = ff + dp(new_flip, i, msk | (1 << i));
                if (res < ans) ans = res;
            }
            ff++;
        }
    }
    memo[fliped][idx][msk] = ans;
    return ans;
} // End of Code
