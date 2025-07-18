#include <stdio.h>
#include <stdlib.h>

int n;
int *a[2];
int *memo;

int dp(int fliped, int idx, int msk);

int main() {
    scanf("%d", &n);
    a[0] = (int*)malloc(n * sizeof(int));
    a[1] = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    int total_size = 2 * (n + 1) * (1 << n);
    memo = (int*)malloc(total_size * sizeof(int));
    if (!memo) {
        printf("-1\n");
        return 1;
    }
    for (int i = 0; i < total_size; i++) memo[i] = -1;
    int ans = dp(0, n, 0);
    printf("%d\n", ans >= 1000000000 ? -1 : ans);
    free(a[0]);
    free(a[1]);
    free(memo);
    return 0;
}

int dp(int fliped, int idx, int msk) {
    int offset = fliped * (n + 1) * (1 << n) + idx * (1 << n) + msk;
    if (memo[offset] != -1) return memo[offset];
    int x = 0, temp;
    for (temp = msk; temp > 0; temp >>= 1) x += temp & 1;
    int ans = 1000000000;
    int ff = 0;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_fliped = (nf + (ff % 2)) % 2;
                int new_ans = ff + dp(new_fliped, i, msk | (1 << i));
                if (new_ans < ans) ans = new_ans;
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[offset] = ans;
    return ans;
}
// End of Code
