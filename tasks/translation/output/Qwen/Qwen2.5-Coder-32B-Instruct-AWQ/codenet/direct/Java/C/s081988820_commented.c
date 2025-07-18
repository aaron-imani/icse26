#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    int c[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    int min[MAX];
    for (int i = 0; i < MAX; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < MAX; tc++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (min[i] > c[i][j] + min[j]) {
                    min[i] = c[i][j] + min[j];
                }
            }
        }
    }
    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += min[A];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
