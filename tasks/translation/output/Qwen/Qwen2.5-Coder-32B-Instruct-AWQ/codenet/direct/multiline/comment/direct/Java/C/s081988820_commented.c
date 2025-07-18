#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    int c[MAX_N][MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    int min[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < MAX_N; tc++) {
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
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
