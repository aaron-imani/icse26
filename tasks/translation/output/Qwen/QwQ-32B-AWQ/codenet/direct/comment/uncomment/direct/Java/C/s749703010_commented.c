#include <stdio.h>
#include <stdlib.h>

int n;
int *a0, *a1;
int *memo;

static int count_bits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

static int dp(int fliped, int idx, int msk) {
    int m_idx = fliped * (n + 1) * (1 << n) + idx * (1 << n) + msk;
    if (memo[m_idx] != -1) return memo[m_idx];
    if (msk == ((1 << n) - 1)) return 0;
    int ans = 1000000000;
    int x = count_bits(msk);
    int ff = 0;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int new_flip = (nf + (ff % 2)) % 2;
            int condition_met = 0;
            if (idx == n) {
                condition_met = 1;
            } else {
                int current_val = (fliped == 0) ? a0[idx] : a1[idx];
                int target_val = (new_flip == 0) ? a0[i] : a1[i];
                if (current_val <= target_val) {
                    condition_met = 1;
                }
            }
            if (condition_met) {
                int temp_ans = ff + dp(new_flip, i, msk | (1 << i));
                if (temp_ans < ans) ans = temp_ans;
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[m_idx] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);
    a0 = malloc(n * sizeof(int));
    a1 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a0[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }
    int total_size = 2 * (n + 1) * (1 << n);
    memo = malloc(total_size * sizeof(int));
    for (int i = 0; i < total_size; i++) {
        memo[i] = -1;
    }
    int ans = dp(0, n, 0);
    if (ans >= 1000000000) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    free(a0);
    free(a1);
    free(memo);
    return 0;
}
// End of Code
