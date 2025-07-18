#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct {
    int H, W;
    int c[10][10];
    int min[10];
    int ans;
} Main;

void solve(Main *main) {
    int H, W;
    scanf("%d %d", &H, &W);
    main->H = H;
    main->W = W;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &main->c[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        main->min[i] = main->c[i][1];
    }

    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (main->min[i] > main->c[i][j] + main->min[j]) {
                    main->min[i] = main->c[i][j] + main->min[j];
                }
            }
        }
    }

    main->ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                main->ans += main->min[A];
            }
        }
    }

    printf("%d\n", main->ans);
}

int main() {
    Main main;
    solve(&main);
    return 0;
}
// End of Code
