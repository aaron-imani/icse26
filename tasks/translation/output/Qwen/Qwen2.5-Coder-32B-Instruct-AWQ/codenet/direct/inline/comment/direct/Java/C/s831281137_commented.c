#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    int *v = (int *)malloc((N + 1) * sizeof(int));
    int *w = (int *)malloc((N + 1) * sizeof(int));

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }

    int **sumV = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        sumV[i] = (int *)malloc((W + 1) * sizeof(int));
        for (int j = 0; j <= W; j++) {
            sumV[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i - 1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i - 1][i_sum] > sumV[i - 1][i_sum - w[i]] + v[i]) ? sumV[i - 1][i_sum] : sumV[i - 1][i_sum - w[i]] + v[i];
        }
    }

    printf("%d\n", sumV[N][W]);

    for (int i = 0; i <= N; i++) {
        free(sumV[i]);
    }
    free(sumV);
    free(v);
    free(w);

    return 0;
}
// End of Code
