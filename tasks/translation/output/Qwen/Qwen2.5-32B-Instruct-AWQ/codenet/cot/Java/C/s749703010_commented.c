#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l, r;
} Pair;

int memo[2][100][1024];
int a[2][100];
int n;

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = (ans < (ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i))) ? ans : (ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i))));
            }
            ff++;
        } else x--;
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    a[0] = (int *)malloc(n * sizeof(int));
    a[1] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n + 1; j++) {
            for (int k = 0; k < (1 << n); k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", (ans >= 100000000 ? -1 : ans));
    return 0;
}
// End of Code
