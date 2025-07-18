#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_W 100

int nint() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int N = nint();
    int W = nint();

    int v[MAX_N + 1];
    int w[MAX_N + 1];

    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    int sumV[MAX_N + 1][MAX_W + 1];

    for (int i = 0; i <= N; i++) {
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

    return 0;
}
// End of Code
