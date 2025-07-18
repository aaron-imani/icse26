#include <stdio.h>
#include <stdlib.h>

int nint() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int N = nint();
    int W = nint();

    int v[N+1];
    int w[N+1];
    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    int **sumV = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++) {
        sumV[i] = (int *)calloc(W + 1, sizeof(int));
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }
        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i-1][i_sum] > (sumV[i-1][i_sum - w[i]] + v[i])) ? sumV[i-1][i_sum] : (sumV[i-1][i_sum - w[i]] + v[i]);
        }
    }

    printf("%d\n", sumV[N][W]);

    for (int i = 0; i <= N; i++) {
        free(sumV[i]);
    }
    free(sumV);

    return 0;
} // End of Code
