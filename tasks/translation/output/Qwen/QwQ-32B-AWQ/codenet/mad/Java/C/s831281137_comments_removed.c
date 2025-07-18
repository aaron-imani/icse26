#include <stdio.h>

defined MAX(a, b) as ((a) > (b) ? (a) : (b))

int main() {
    int N, W;
    scanf("%d %d", &N, &W);

    int v[N+1];
    int w[N+1];

    for (int i = 1; i <= N; i++) {
        scanf("%d", &v[i]);
        scanf("%d", &w[i]);
    }

    int sumV[N+1][W+1];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            sumV[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }
        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = MAX(sumV[i-1][i_sum], 
                                 sumV[i-1][i_sum - w[i]] + v[i]);
        }
    }

    printf("%d\n", sumV[N][W]);
    // End of Code
}
