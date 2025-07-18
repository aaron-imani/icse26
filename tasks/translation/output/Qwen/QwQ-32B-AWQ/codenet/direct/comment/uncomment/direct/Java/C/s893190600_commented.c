#include <stdio.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    if (H == 1 && W == 1) {
        printf("No\n");
        return 0;
    }

    char grid[H+2][W+2];
    for (int i = 0; i <= H+1; i++) {
        for (int j = 0; j <= W+1; j++) {
            grid[i][j] = '.';
        }
    }

    for (int i = 1; i <= H; i++) {
        char line[W+2];
        scanf("%s", line);
        for (int j = 1; j <= W; j++) {
            grid[i][j] = line[j-1];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                if (grid[i-1][j] != '#' && grid[i+1][j] != '#' 
                    && grid[i][j-1] != '#' && grid[i][j+1] != '#') {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }

    printf("Yes\n");
    return 0;
}
// End of Code
