#include <stdio.h>

int nint() {
    int n;
    scanf("%d", &n);
    return n;
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

    int sumV[N+1][W+1];

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i-1][i_sum] > sumV[i-1][i_sum-w[i]] + v[i]) ? sumV[i-1][i_sum] : sumV[i-1][i_sum-w[i]] + v[i];
        }
    }

    printf("%d\n", sumV[N][W]); // End of Code
}
