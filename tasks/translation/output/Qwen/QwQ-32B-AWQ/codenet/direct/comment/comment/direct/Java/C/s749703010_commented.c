#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int *a0, *a1;
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
            int new_flip = (nf + (ff % 2)) % 2;
            int val = new_flip ? a1[i] : a0[i];
            if (idx == n || ( (fliped ? a1[idx] : a0[idx]) <= val )) {
                int res = ff + dp(new_flip, i, msk | (1 << i));
                if (res < ans) ans = res;
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
    a0 = malloc(n * sizeof(int));
    a1 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a0[i]);
    for (int i = 0; i < n; i++) scanf("%d", &a1[i]);
    memo = malloc(2 * sizeof(int**));
    for (int i = 0; i < 2; i++) {
        memo[i] = malloc( (n + 1) * sizeof(int*) );
        for (int j = 0; j < n + 1; j++) {
            memo[i][j] = malloc( (1 << n) * sizeof(int) );
            memset(memo[i][j], -1, (1 << n) * sizeof(int));
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", ans >= 1000000000 ? -1 : ans);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n + 1; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);
    free(a0);
    free(a1);
    return 0;
}
// End of Code
