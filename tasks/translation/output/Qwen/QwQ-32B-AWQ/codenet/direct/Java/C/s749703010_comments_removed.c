#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l;
    int r;
} Pair;

int n;
int **a;
int ***memo;

int count_bits(int msk) {
    int count = 0;
    while (msk) {
        count += msk & 1;
        msk >>= 1;
    }
    return count;
}

int dp(int fliped, int idx, int msk) {
    if (msk == ((1 << n) - 1)) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    
    int x = count_bits(msk);
    int ff =  according to the Java code, but there was a missing value. Wait in the Java code, it's initialized to 0. So yes:
int ff = 0;
    int ans = 1000000000;
    
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int nf2 = (nf + (ff % 2)) % 2;
            if (idx == n || a[fliped][idx] <= a[nf2][i]) {
                int temp = ff + dp(nf2, i, msk | (1 << i));
                if (temp < ans) ans = temp;
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
    
    a = (int **)malloc(2 * sizeof(int *));
    a[0] = (int *)malloc(n * sizeof(int));
    a[1] = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    
    memo = (int ***)malloc(2 * sizeof(int **));
    for (int f = 0; f < 2; f++) {
        memo[f] = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i <= n; i++) {
            memo[f][i] = (int *)malloc((1 << n) * sizeof(int));
            memset(memo[f][i], -1, (1 << n) * sizeof(int));
        }
    }
    
    int ans = dp(0, n, 0);
    printf("%d\n", ans >= 1000000000 ? -1 : ans);
    
    return 0;
}
// End of Code
