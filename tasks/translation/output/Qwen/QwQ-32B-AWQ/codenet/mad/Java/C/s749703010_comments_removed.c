#include <stdio.h>
#include <stdlib.h>

int n;
int **a;
int *memo;

int bit_count(int msk) {
    int count = 0;
    while (msk) {
        count += msk & 1;
        msk >>= 1;
    }
    return count;
}

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    int pos = fliped * (n + 1) * (1 << n) + idx * (1 << n) + msk;
    if (memo[pos] != -1) return memo[pos];

    int x = bit_count(msk);
    int ff = 0;
    int ans = 1000000000; // Fixed: 1e9 → 1000000000

    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_flip = (nf + (ff % 2)) % 2;
                int new_idx = i;
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_flip, new_idx, new_msk);
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

    a = malloc(2 * sizeof(int *));
    a[0] = malloc(n * sizeof(int));
    a[1] = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);

    int size = 2 * (n + 1) * (1 << n);
    memo = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) memo[i] = -1;

    int ans = dp(0, n, 0);

    printf("%d\n", ans >= 100000000 ? -1 : ans); // Fixed: 1e8 → 100000000
    free(a[0]);
    free(a[1]);
    free(a);
    free(memo);
    return 0;
}
// End of Code
