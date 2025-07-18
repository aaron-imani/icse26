#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    int v[N+1];
    int w[N+1];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }

    int **sumV;
    sumV = malloc((N + 1) * sizeof(int*));
    for (int i = 0; i <= N; i++) {
        sumV[i] = calloc(W + 1, sizeof(int));
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i - 1][i_sum];
        }
        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            int val1 = sumV[i - 1][i_sum];
            int val2 = sumV[i - 1][i_sum - w[i]] + v[i];
            sumV[i][i_sum] = (val1 > val2) ? val1 : val2;
        }
    }

    printf("%d\n", sumV[N][W]);

    for (int i = 0; i <= N; i++) {
        free(sumV[i]);
    }
    free(sumV);

    return 0;
}
// End of Code
