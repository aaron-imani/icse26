#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

typedef struct {
    int l, r;
} Pair;

int bitCount(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int dp(int fliped, int idx, int msk, int*** memo, int** a, int n) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = bitCount(msk);
    int ff = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i, memo, a, n));
            }
            ff++;
        } else x--;
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    int** a = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    int*** memo = (int***)malloc(2 * sizeof(int**));
    for (int i = 0; i < 2; i++) {
        memo[i] = (int**)malloc((n + 1) * sizeof(int*));
        for (int j = 0; j < n + 1; j++) {
            memo[i][j] = (int*)malloc((1 << n) * sizeof(int));
            memset(memo[i][j], -1, (1 << n) * sizeof(int));
        }
    }
    int ans = dp(0, n, 0, memo, a, n);
    printf("%d\n", ans >= INF ? -1 : ans);
    for (int i = 0; i < 2; i++) free(a[i]);
    free(a);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n + 1; j++) free(memo[i][j]);
        free(memo[i]);
    }
    free(memo);
    return 0;
}
// End of Code
