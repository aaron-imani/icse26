#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int min_cost[MAX];

void floyd_warshall(int c[MAX][MAX]) {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (c[i][k] + c[k][j] < c[i][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    int c[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    floyd_warshall(c);

    for (int i = 0; i < MAX; i++) {
        min_cost[i] = c[i][1];
    }

    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += min_cost[A];
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
// End of Code
