#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int lcs(const char *A, const char *B, int ***dp, int *m, int *n) {
    int m_val = strlen(A);
    int n_val = strlen(B);
    *m = m_val;
    *n = n_val;
    *dp = (int **)malloc((m_val + 1) * sizeof(int *));
    for (int i = 0; i <= m_val; i++) {
        (*dp)[i] = (int *)malloc((n_val + 1) * sizeof(int));
        for (int j = 0; j <= n_val; j++) {
            (*dp)[i][j] = 0;
        }
    }
    for (int i = 1; i <= m_val; i++) {
        for (int j = 1; j <= n_val; j++) {
            if (A[i - 1] == B[j - 1]) {
                (*dp)[i][j] = (*dp)[i - 1][j - 1] + 1;
            } else {
                (*dp)[i][j] = max((*dp)[i - 1][j], (*dp)[i][j - 1]);
            }
        }
    }
    return (*dp)[m_val][n_val];
}

char *getLCS(const char *X, const char *Y, int m, int n, int **dp) {
    int len = dp[m][n];
    char *result = (char *)malloc(len + 1);
    int i = m, j = n, idx = len - 1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[idx--] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    result[len] = '\0';
    return result;
}

int *strToIntArray(const char *str, int *size) {
    char *copy = strdup(str);
    char *token = strtok(copy, " \t\n");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    *size = count;
    if (count == 0) {
        free(copy);
        return NULL;
    }
    int *res = (int *)malloc(count * sizeof(int));
    if (res == NULL) {
        free(copy);
        return NULL;
    }
    char *copy2 = strdup(str);
    token = strtok(copy2, " \t\n");
    int i = 0;
    while (token != NULL) {
        res[i++] = atoi(token);
        token = strtok(NULL, " \t\n");
    }
    free(copy);
    free(copy2);
    return res;
}

void process_case(const char *line) {
    int N, K;
    sscanf(line, "%d %d", &N, &K);
    int len = 0;
    int num = N;
    while (num > 0) {
        num /= K;
        len++;
    }
    printf("%d\n", len);
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        process_case(line);
    }
    return 0;
}
// End of Code
