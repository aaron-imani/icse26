#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* strToIntArray(const char* str, int* size) {
    char* copy = malloc(strlen(str) + 1);
    if (!copy) return NULL;
    strcpy(copy, str);
    char* token = strtok(copy, " \t\n");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    *size = count;
    int* res = malloc(count * sizeof(int));
    if (!res) {
        free(copy);
        return NULL;
    }
    char* copy2 = malloc(strlen(str) + 1);
    if (!copy2) {
        free(copy);
        free(res);
        return NULL;
    }
    strcpy(copy2, str);
    token = strtok(copy2, " \t\n");
    for (int i = 0; i < count; i++) {
        res[i] = atoi(token);
        token = strtok(NULL, " \t\n");
    }
    free(copy);
    free(copy2);
    return res;
}

int lcs(const char* A, const char* B) {
    int m = strlen(A);
    int n = strlen(B);
    int** dp = malloc((m + 1) * sizeof(int*));
    if (!dp) return -1;
    for (int i = 0; i <= m; i++) {
        dp[i] = calloc(n + 1, sizeof(int));
        if (!dp[i]) {
            for (int j = 0; j <= i; j++) free(dp[j]);
            free(dp);
            return -1;
        }
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
    int result = dp[m][n];
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return result;
}

char* getLCS(const char* X, const char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int** dp = malloc((m + 1) * sizeof(int*));
    if (!dp) return NULL;
    for (int i = 0; i <= m; i++) {
        dp[i] = calloc(n + 1, sizeof(int));
        if (!dp[i]) {
            for (int j = 0; j <= i; j++) free(dp[j]);
            free(dp);
            return NULL;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    int index = dp[m][n];
    char* lcs_str = malloc((index + 1) * sizeof(char));
    if (!lcs_str) {
        for (int i = 0; i <= m; i++) free(dp[i]);
        free(dp);
        return NULL;
    }
    lcs_str[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[--index] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    for (int i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return lcs_str;
}

int main() {
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';
        int N, K;
        sscanf(line, "%d %d", &N, &K);
        int lenDigits = 0;
        int temp = N;
        while (temp > 0) {
            temp /= K;
            lenDigits++;
        }
        printf("%d\n", lenDigits);
    }
    return 0;
}
// End of Code
