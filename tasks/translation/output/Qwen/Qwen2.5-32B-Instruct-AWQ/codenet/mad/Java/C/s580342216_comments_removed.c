#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_case() {
    char line[100];
    fgets(line, sizeof(line), stdin);
    int N, K;
    sscanf(line, "%d %d", &N, &K);

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int* strToIntArray(char* str, int* size) {
    char* token;
    int count = 0;
    char* temp = strdup(str);
    token = strtok(temp, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    *size = count;
    int* res = (int*)malloc(count * sizeof(int));
    token = strtok(str, " ");
    for (int i = 0; i < count; i++) {
        res[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(temp);
    return res;
}

int lcs(char* A, char* B) {
    int sz_a = strlen(A);
    int sz_b = strlen(B);
    int** dp = (int**)malloc((sz_a + 1) * sizeof(int*));
    for (int i = 0; i <= sz_a; i++) {
        dp[i] = (int*)malloc((sz_b + 1) * sizeof(int));
        dp[i][0]  = 0;
    }
    for (int j = 0; j <= sz_b; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= sz_a; i++) {
        for (int j = 1; j <= sz_b; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int result = dp[sz_a][sz_b];
    for (int i = 0; i <= sz_a; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

char* getLCS(char* X, char* Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
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
    char* lcs = (char*)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--index] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return lcs;
}

int main() {
    while (1) {
        run_case();
        if (feof(stdin)) break;
    }
    return 0;
}
// End of Code
