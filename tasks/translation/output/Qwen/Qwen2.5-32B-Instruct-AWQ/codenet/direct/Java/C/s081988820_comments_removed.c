#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int H, W;
int c[MAX_SIZE][MAX_SIZE];
int min[MAX_SIZE];

void solve() {
    for (int i = 0; i < 10; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                min[i] = (min[i] < c[i][j] + min[j]) ? min[i] : c[i][j] + min[j];
            }
        }
    }
    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += min[A];
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    solve();
    return 0;
}

// End of Code
