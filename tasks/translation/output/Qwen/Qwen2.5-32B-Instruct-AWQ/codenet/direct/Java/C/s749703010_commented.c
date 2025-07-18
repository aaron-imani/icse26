#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20
#define INF 1000000000

typedef struct {
    int l, r;
} Pair;

int memo[2][MAX_N + 1][1 << MAX_N];
int a[2][MAX_N];
int n;

int dp(int flipped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[flipped][idx][msk] != -1) return memo[flipped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = (ans < (ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i))) ? ans : (ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i))));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[flipped][idx][msk] = ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[0][i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[1][i]);
    }
    memset(memo, -1, sizeof(memo));
    int ans = dp(0, n, 0);
    printf("%d\n", (ans >= INF) ? -1 : ans);
    return 0;
}
// End of Code
