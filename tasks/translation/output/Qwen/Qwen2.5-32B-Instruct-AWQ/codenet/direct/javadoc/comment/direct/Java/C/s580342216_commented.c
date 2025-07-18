#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **dp;
} LCS;

void free_lcs(LCS *lcs) {
    for (int i = 0; i <= strlen(lcs->dp[0]); i++) {
        free(lcs->dp[i]);
    }
    free(lcs->dp);
}

int lcs(LCS *lcs, const char *A, const char *B) {
    int sz_a = strlen(A), sz_b = strlen(B);
    lcs->dp = malloc((sz_a + 1) * sizeof(int *));
    for (int i = 0; i <= sz_a; i++) {
        lcs->dp[i] = calloc(sz_b + 1, sizeof(int));
    }

    for (int i = 1; i <= sz_a; i++) {
        for (int j = 1; j <= sz_b; j++) {
            if (A[i - 1] == B[j - 1]) {
                lcs->dp[i][j] = lcs->dp[i - 1][j - 1] + 1;
            } else {
                lcs->dp[i][j] = (lcs->dp[i - 1][j] > lcs->dp[i][j - 1]) ? lcs->dp[i - 1][j] : lcs->dp[i][j - 1];
            }
        }
    }

    return lcs->dp[sz_a][sz_b];
}

char* get_lcs(LCS *lcs, const char *X, const char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int index = lcs->dp[m][n];
    int temp = index;

    char *lcs_str = malloc((index + 2) * sizeof(char));
    lcs_str[index] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (lcs->dp[i - 1][j] > lcs->dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs_str;
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int N = atoi(strtok(line, " "));
        int K = atoi(strtok(NULL, " "));

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
