#include <stdio.h>

int nint() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int N = nint();
    int W = nint();

    int v[N+1];
    int w[N+1];

    // Initialize arrays to zero
    for (int i = 0; i <= N; i++) {
        v[i] = 0;
        w[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    int sumV[N+1][W+1];

    // Initialize the first row of sumV to zero
    for (int i_sum = 0; i_sum <= W; i_sum++) {
        sumV[0][i_sum] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i-1][i_sum] > sumV[i-1][i_sum-w[i]] + v[i]) ? sumV[i-1][i_sum] : sumV[i-1][i_sum-w[i]] + v[i];
        }
    }

    printf("%d\n", sumV[N][W]);
    return 0;
}
// End of Code
