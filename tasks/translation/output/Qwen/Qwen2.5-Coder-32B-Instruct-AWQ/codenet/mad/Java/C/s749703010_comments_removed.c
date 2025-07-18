#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 20
#define INF 1000000000

int memo[2][MAX_N + 1][1 << MAX_N];
int a[2][MAX_N];
int n;

int bit_count(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = bit_count(msk);
    int ff = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = ans < ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)) ? ans : ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            memset(memo[i][j], -1, sizeof(memo[i][j]));
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", ans >= INF ? -1 : ans);
    return 0;
}
// End of Code
