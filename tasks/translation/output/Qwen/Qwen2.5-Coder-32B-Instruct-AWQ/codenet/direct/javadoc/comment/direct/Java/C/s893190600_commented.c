#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_H 1005
#define MAX_W 1005

char C[MAX_H][MAX_W];

void solve(int H, int W) {
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
    int H, W;
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%s", C[i+1]+1);
    }
    solve(H, W);
    return 0;
}
// End of Code
