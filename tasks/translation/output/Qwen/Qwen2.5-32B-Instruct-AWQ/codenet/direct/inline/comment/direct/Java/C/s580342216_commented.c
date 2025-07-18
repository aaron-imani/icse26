#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **dp;
} LCS;

void free_memory(LCS *lcs, int size_a, int size_b) {
    for (int i = 0; i <= size_a; i++) {
        free(lcs->dp[i]);
    }
    free(lcs->dp);
}

int lcs(LCS *lcs, char *A, char *B) {
    int size_a = strlen(A), size_b = strlen(B);
    lcs->dp = (int **)malloc((size_a + 1) * sizeof(int *));
    for (int i = 0; i <= size_a; i++) {
        lcs->dp[i] = (int *)calloc(size_b + 1, sizeof(int));
    }

    for (int i = 1; i <= size_a; i++) {
        for (int j = 1; j <= size_b; j++) {
            if (A[i - 1] == B[j - 1]) {
                lcs->dp[i][j] = lcs->dp[i - 1][j - 1] + 1;
            } else {
                lcs->dp[i][j] = (lcs->dp[i - 1][j] > lcs->dp[i][j - 1]) ? lcs->dp[i - 1][j] : lcs->dp[i][j - 1];
            }
        }
    }

    return lcs->dp[size_a][size_b];
}

char* get_lcs(LCS *lcs, char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int index = lcs->dp[m][n];
    int temp = index;

    char *lcs_str = (char *)malloc((index + 2) * sizeof(char));
    lcs_str[index] = '\0';

    int i = m, j = n;
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

void run_case() {
    char line[100];
    fgets(line, sizeof(line), stdin);
    int N = atoi(strtok(line, " "));
    int K = atoi(strtok(NULL, " "));

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int main() {
    while (!feof(stdin)) {
        run_case();
    }
    return 0;
}

// End of Code
