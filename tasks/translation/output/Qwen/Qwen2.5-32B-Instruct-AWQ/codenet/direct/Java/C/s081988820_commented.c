#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

int H, W;
int c[MAX_SIZE][MAX_SIZE];
int min[MAX_SIZE];

void solve() {
    for (int i = 0; i < MAX_SIZE; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < MAX_SIZE; tc++) {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
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
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    solve();
    return 0;
}

// End of Code
