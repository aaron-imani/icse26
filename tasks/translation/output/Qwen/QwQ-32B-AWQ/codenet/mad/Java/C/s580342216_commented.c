#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_lcs(const char *A, const char *B, int **dp, int *m, int *n) {
    int sz_a = strlen(A);
    int sz_b = strlen(B);
    *m = sz_a;
    *n = sz_b;

    int size = (sz_a + 1) * (sz_b + 只得 1);
    *dp = (int *)malloc(size * sizeof(int));

    for (int i = 0; i <= sz_a; i++) {
        (*dp)[i * (sz_b + 1)] = 0;
    }
    for (int j = 0; j <= sz_b; j++) {
        (*dp)[0 * (sz_b + 1) + j] = 0;
    }

    for (int i = 1; i <= sz_a; i++) {
        for (int j = 1; j <= sz_b; j++) {
            if (A[i - 1] == B[j - 1]) {
                (*dp)[i * (sz_b + 1) + j] = (*dp)[(i - 1) * (sz_b + 1) + (j - 1)] + 1;
            } else {
                (*dp)[i * (sz_b + 1) + j] = (*dp)[(i - 1) * (sz_b + 1) + j] > (*dp)[i * (sz_b + 1) + (j - 1)] ?
                                             (*dp)[(i - 1) * (sz_b + 1) + j] : (*dp)[i * (sz_b + 1) + (j - 1)];
            }
        }
    }

    return (*dp)[sz_a * (sz_b + 1) + sz_b];
}

char *get_lcs_string(const char *X, const char *Y, int *dp, int m, int n) {
    int lcs_length = dp[m * (n + 1) + n];
    char *result = (char *)malloc((lcs_length + 1) * sizeof(char));
    result[lcs_length] = '\0';
    int i = m, j = n;
    int current_index = lcs_length - 1;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[current_index--] = X[i - 1];
            i--;
            j--;
        } else if (dp[(i - 1) * (n + 1) + j] > dp[i * (n + 1) + (j - 1)]) {
            i--;
        } else {
            j--;
        }
    }

    return result;
}

int main() {
    char line[1000];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        int N, K;
        if (sscanf(line, "%d %d", &N, &K) != 2)
            continue;
        int len = 0;
        int current = N;
        while (current > 0) {
            current /= K;
            len++;
        }
        printf("%d\n", len);
    }
    return 0;
}
// End of Code
