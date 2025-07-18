#include <stdio.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);

    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int min[10];
    for (int i = 0; i < 10; i++) {
        min[i] = c[i][1];
    }

    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (min[i] > min[j] + c[i][j]) {
                    min[i] = min[j] + c[i][j];
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
