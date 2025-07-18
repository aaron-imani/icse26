#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **dp;
    int m;
    int n;
} LCS;

int lcs(LCS *lcs_obj, const char *A, const char *B) {
    int m = strlen(A);
    int n = strlen(B);

    if (lcs_obj->dp) {
        for (int i = 0; i <= lcs_obj->m; i++) {
            free(lcs_obj->dp[i]);
        }
        free(lcs_obj->dp);
    }

    lcs_obj->dp = (int **)malloc((m + 1) * sizeof(int *));
    if (!lcs_obj->dp) return -1;
    for (int i = 0; i <= m; i++) {
        lcs_obj->dp[i] = (int *)malloc((n + 1) * sizeof(int));
        if (!lcs_obj->dp[i]) return -1;
    }

    for (int i = 0; i <= m; i++) lcs_obj->dp[i][0] = 0;
    for (int j = 0; j <= n; j++) lcs_obj->dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1])
                lcs_obj->dp[i][j] = lcs_obj->dp[i - 1][j - 1] + 1;
            else
                lcs_obj->dp[i][j] = (lcs_obj->dp[i - 1][j] > lcs_obj->dp[i][j - 1]) ? lcs_obj->dp[i - 1][j] : lcs_obj->dp[i][j - 1];
        }
    }

    lcs_obj->m = m;
    lcs_obj->n = n;
    return lcs_obj->dp[m][n];
}

char *getLCS(LCS *lcs_obj, const char *X, const char *Y) {
    int m = lcs_obj->m;
    int n = lcs_obj->n;
    int index = lcs_obj->dp[m][n];
    int temp = index;
    char *lcs_str = (char *)malloc((index + 1) * sizeof(char));
    if (!lcs_str) return NULL;
    lcs_str[index] = '\0';
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[--index] = X[i - 1];
            i--;
            j--;
        } else if (lcs_obj->dp[i - 1][j] > lcs_obj->dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs_str;
}

int* strToIntArray(const char *str, int *length) {
    char *copy = strdup(str);
    if (!copy) {
        *length = 0;
        return NULL;
    }
    char *token = strtok(copy, " \t");
    int count = 0;
    while (token) {
        count++;
        token = strtok(NULL, " \t");
    }
    int *res = (int *)malloc(count * sizeof(int));
    if (!res) {
        free(copy);
        *length = 0;
        return NULL;
    }
    char *copy2 = strdup(str);
    token = strtok(copy2, " \t");
    for (int i = 0; i < count; i++) {
        res[i] = atoi(token);
        token = strtok(NULL, " \t");
    }
    free(copy);
    free(copy2);
    *length = count;
    return res;
}

int main() {
    char line[1000];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        int N, K;
        sscanf(line, "%d %d", &N, &K);
        int len = 0;
        int n = N;
        while (n > 0) {
            n /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
