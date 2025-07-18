#include <stdio.h>
#include <stdlib.h>

int n;
int **a;
int *memo;

int bit_count(int m) {
    int cnt = 0;
    while (m) {
        cnt += m & 1;
        m >>= 1;
    }
    return cnt;
}

int dp(int fliped, int idx, int msk) {
    int pos = fliped * ((n + 1) * (1 << n)) + idx * (1 << n) + msk;
    if (memo[pos] != -1) return memo[pos];
    if (msk == ((1 << n) - 1)) {
        memo[pos] = 0;
        return 0;
    }
    int x = bit_count(msk);
    int ans = 1e9;
    int ff = 0;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int new_fliped = (nf + (ff % 2)) % 2;
            int current_val = (idx == n) ? 0 : a[fliped][idx];
            int next_val = a[new_fliped][i];
            if (idx == n || current_val <= next_val) {
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_fliped, i, new_msk);
                if (res < ans) ans = res;
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[pos] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);
    a = (int**)malloc(2 * sizeof(int*));
    a[0] = (int*)malloc(n * sizeof(int));
    a[1] = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);

    int size = 2 * (n + 1) * (1 << n);
    memo = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) memo[i] = -1;

    int ans = dp(0, n, 0);
    if (ans >= 1e9) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    free(a[0]);
    free(a[1]);
    free(a);
    free(memo);

    return 0;
}

// End of Code
