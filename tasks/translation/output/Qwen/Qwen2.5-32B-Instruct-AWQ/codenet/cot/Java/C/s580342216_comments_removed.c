#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *scanner;
} Solution;

Solution *new_solution() {
    Solution *solution = (Solution *)malloc(sizeof(Solution));
    solution->scanner = stdin;
    return solution;
}

void run_case(Solution *solution) {
    char line[100];
    fgets(line, sizeof(line), solution->scanner);
    int N = atoi(strtok(line, " "));
    int K = atoi(strtok(NULL, " "));

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int *str_to_int_array(char *str, int *size) {
    char *token = strtok(str, " ");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    *size = count;
    int *res = (int *)malloc(count * sizeof(int));
    token = strtok(str, " ");
    for (int i = 0; i < count; i++) {
        res[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    return res;
}

typedef struct {
    int **dp;
} LCS;

LCS *new_lcs() {
    LCS *lcs = (LCS *)malloc(sizeof(LCS));
    lcs->dp = NULL;
    return lcs;
}

int lcs(LCS *lcs, char *A, char *B) {
    int sz_a = strlen(A), sz_b = strlen(B);
    lcs->dp = (int **)malloc((sz_a + 1) * sizeof(int *));
    for (int i = 0; i <= sz_a; i++) {
        lcs->dp[i] = (int *)malloc((sz_b + 1) * sizeof(int));
        for (int j = 0; j <= sz_b; j++) {
            lcs->dp[i][j] = 0;
        }
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

char *get_lcs(LCS *lcs, char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int index = lcs->dp[m][n];
    int temp = index;
    char *lcs_str = (char *)malloc((index + 2) * sizeof(char));
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
    Solution *solution = new_solution();
    while (!feof(solution->scanner)) {
        run_case(solution);
    }
    free(solution);

    LCS *lcs = new_lcs();
    char *A = "AGGTAB";
    char *B = "GXTXAYB";
    int length = lcs(lcs, A, B);
    printf("Length of LCS is %d\n", length);
    char *lcs_str = get_lcs(lcs, A, B);
    printf("LCS is %s\n", lcs_str);
    free(lcs_str);
    for (int i = 0; i <= strlen(A); i++) {
        free(lcs->dp[i]);
    }
    free(lcs->dp);
    free(lcs);
    return 0;
} // End of Code
