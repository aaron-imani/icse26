#include <stdio.h>

#define MAX_N 100
#define MAX_W 100

int v[MAX_N + 1];
int w[MAX_N + 1];
int sumV[MAX_N + 1][MAX_W + 1];

int nint() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int N = nint();
    int W = nint();

    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
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
