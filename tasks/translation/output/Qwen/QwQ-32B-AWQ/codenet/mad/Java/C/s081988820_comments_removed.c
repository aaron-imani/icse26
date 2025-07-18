#include <stdio.h>

int main() {
    int H, W;
    int c[10][10];
    int min[10];
    int ans = 0;
    int i, j, tc, h, w, A;

    scanf("%d %d", &H, &W);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    for (i = 0; i < 10; i++) {
        min[i] = c[i][1];
    }

    for (tc = 0; tc < 10; tc++) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (c[i][j] + min[j] < min[i]) {
                    min[i] = c[i][j] + min[j];
                }
            }
        }
    }

    for (h = 0; h < H; h++) {
        for (w = 0; w < W; w++) {
            scanf("%d", &A);
            if (A >= 0) {
                ans += min[A];
            }
        }
    }

    printf("%d\n", ans);
}
// End of Code
