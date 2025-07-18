#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **create_dp(int m, int n) {
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    return dp;
}

void free_dp(int **dp, int m) {
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
}

int compute_lcs(const char *A, const char *B, int **dp, int m, int n) {
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

char *get_lcs(const char *X, const char *Y, int **dp, int m, int n) {
    int index = dp[m][n];
    int temp = index;
    char *lcs_str = (char *)malloc((index + 1) * sizeof(char));
    lcs_str[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs_str;
}

int main() {
    char line[1024];
    while (fgets(line, sizeof(line), stdin)) {
        int N, K;
        sscanf(line, "%d %d", &N, &K);
        int len = 0;
        while (N > 0) {
            N /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
