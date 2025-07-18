Here is the translated C code based on the Java code provided:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* strToIntArray(char* str, int* size) {
    char* copy = strdup(str);
    if (!copy) return NULL;

    int count = 0;
    char* token = strtok(copy, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }

    *size = count;
    int* res = (int*)malloc(count * sizeof(int));
    if (!res) {
        free(copy);
        return NULL;
    }

    char* copy2 = strdup(str);
    if (!copy2) {
        free(res);
        free(copy);
        return NULL;
    }

    token = strtok(copy2, " \t\n");
    int i = 0;
    while (token != NULL) {
        res[i] = atoi(token);
        i++;
        token = strtok(NULL, " \t\n");
    }

    free(copy);
    free(copy2);
    return res;
}

void run_case(char* line) {
    char* token = strtok(line, " \t\n");
    int N = atoi(token);
    token = strtok(NULL, " \t\n");
    int K = atoi(token);

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int compute_lcs_length(const char* A, const char* B, int*** dp) {
    int m = strlen(A);
    int n = strlen(B);

    *dp = (int**)malloc((m + 1) * sizeof(int*));
    if (!*dp) return -1;

    for (int i = 0; i <= m; i++) {
        (*dp)[i] = (int*)malloc((n + 1) * sizeof(int));
        if (!(*dp)[i]) {
            for (int j = 0; j < i; j++) {
                free((*dp)[j]);
            }
            free(*dp);
            return -1;
        }
    }

    for (int i = 0; i <= m; i++) {
        (*dp)[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        (*dp)[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                (*dp)[i][j] = (*dp)[i - 1][j - 1] + 1;
            } else {
                (*dp)[i][j] = (*dp)[i - 1][j] > (*dp)[i][j - 1] ?
                              (*dp)[i - 1][j] : (*dp)[i][j - 1];
            }
        }
    }

    return (*dp)[m][n];
}

char* get_lcs_string(const char* X, const char* Y, int** dp, int m, int n) {
    int lcs_len = dp[m][n];
    char* result = (char*)malloc((lcs_len + 1) * sizeof(char));
    if (!result) return NULL;

    int i = m, j = n;
    int k = lcs_len;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[--k] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    result[lcs_len] = '\0';
    return result;
}

void free_dp(int** dp, int m) {
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main() {
    char line[1000];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';
        run_case(line);
    }
    return 0;
}
// End of Code
