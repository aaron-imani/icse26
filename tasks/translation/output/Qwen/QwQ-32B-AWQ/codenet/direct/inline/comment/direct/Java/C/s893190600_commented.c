#include <stdio.h>
#include <string.h>

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
        fgets(line, W+2, stdin);
        line[strcspn(line, "\n")] = '\0';
        for (int j = 1; j <= W; j++) {
            grid[i][j] = line[j-1];
        }
    }
    int valid = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                int has_adj = 0;
                if (grid[i-1][j] == '#') has_adj = 1;
                if (grid[i+1][j] == '#') has_adj = 1;
                if (grid[i][j-1] == '#') has_adj = 1;
                if (grid[i][j+1] == '#') has_adj = 1;
                if (!has_adj) {
                    valid = 0;
                    break;
                }
            }
        }
        if (!valid) break;
    }
    printf("%s\n", valid ? "Yes" : "No");
    return 0;
}
// End of Code
