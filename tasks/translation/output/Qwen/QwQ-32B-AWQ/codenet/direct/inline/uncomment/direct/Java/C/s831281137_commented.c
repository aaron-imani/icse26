#include <stdio.h>
#include <string.h>

int main() {
    int N, W;
    scanf("%d %d", &N, &W);
    
    int v[N+1], w[N+1];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    
    int sumV[N+1][W+1];
    memset(sumV, 0, sizeof(sumV));
    
    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }
        
        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i-1][i_sum] > (sumV[i-1][i_sum - w[i]] + v[i])) ? 
                             sumV[i-1][i_sum] : (sumV[i-1][i_sum - w[i]] + v[i]);
        }
    }
    
    printf("%d\n", sumV[N][W]);
    return 0;
}
// End of Code
