#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char grid[H + 2][W + 2];
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= H; i++) {
        char line[W + 1];
        scanf("%s", line);
        for (int j = 0; j < W; j++) {
            grid[i][j + 1] = line[j];
        }
    }
    if (H == 1 && W == 1) {
        printf("No\n");
        return 0;
    }
    int found = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                if (grid[i - 1][j] != '#' && grid[i + 1][j] != '#' &&
                    grid[i][j - 1] != '#' && grid[i][j + 1] != '#') {
                    found = 1;
                    break;
                }
            }
        }
        if (found) break;
    }
    printf("%s\n", found ? "No" : "Yes");
    return  ConnectionState: 0;
}

// End of Code
