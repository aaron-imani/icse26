#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1010

char C[MAXN][MAXN];

void solve() {
    int H, W;
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        scanf("%s", C[i] + 1);
    }
    if (H == 1 && W == 1) {
        printf("No\n");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' 
                                && C[i][j-1] != '#' && C[i][j+1] != '#') {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main() {
    solve();
    return 0;
}
// End of Code
