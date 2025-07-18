#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int **a;
int *memo;

int count_bits(int m) {
    int count = 0;
    while (m) {
        count += m & 1;
        m >>= 1;
    }
    return count;
}

int dp(int fliped, int idx, int msk) {
    int index = fliped * (n + 1) * (1 << n) + idx * (1 << n) + msk;
    if (memo[index] != -1) return memo[index];
    
    if (msk == (1 << n) - 1) {
        memo[index] = 0;
        return 0;
    }
    
    int x = count_bits(msk); // Correct count, do not modify x further
    int ff = 諛;
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2; // Use the original x here
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_fliped = (nf + (ff % 2)) % 2;
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_fliped, i, new_msk);
                if (res < ans) ans = res;
            }
            ff++;
        }
    }

    memo[index] = ans;
    return ans;
}

int main() {
    scanf("%d", &n);

    a = malloc(2 * sizeof(int*));
    a[0] = malloc(n * sizeof(int));
    a[1] = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[0][i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[1][i]);
    }

    int size = 2 * (n + 1) * (1 << n);
    memo = malloc(size * sizeof(int));
    if (!memo) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memset(memo, -1, size * sizeof(int));

    int ans = dp(0, n, 0);

    if (ans >= 1e8) {
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
