#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int l;
    int r;
};

int n;
int **a;
int ***memo;

int bitcount(int m) {
    int cnt = 0;
    while (m) {
        cnt += m & 1;
        m >>= 1;
    }
    return cnt;
}

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = bitcount(msk);
    int ff = 0;
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int cost = ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i));
                if (cost < ans) ans = cost;
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
    a = malloc(2 * sizeof(int *));
    a[0] = malloc(n * sizeof(int));
    a[1] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    int mask_size = 1 << n;
    memo = malloc(2 * sizeof(int **));
    for (int i = 0; i < 2; i++) {
        memo[i] = malloc((n + 1) * sizeof(int *));
        for (int j = 0; j <= n; j++) {
            memo[i][j] = malloc(mask_size * sizeof(int));
            for (int k = 0; k < mask_size; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", ans >= 1000000000 ? -1 : ans);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);
    free(a[0]);
    free(a[1]);
    free(a);
    return 0;
}
// End of Code
