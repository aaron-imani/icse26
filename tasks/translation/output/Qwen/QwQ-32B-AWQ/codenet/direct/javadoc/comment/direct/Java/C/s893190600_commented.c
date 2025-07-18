#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    if (H == 1 && W == 1) {
        printf("No\n");
        return 0;
    }
    
    char **grid;
    grid = (char **)malloc((H + 2) * sizeof(char *));
    for (int i = 0; i < H + 2; i++) {
        grid[i] = (char *)malloc((W + 2) * sizeof(char));
        memset(grid[i], 0, (W + 2) * sizeof(char));
    }
    
    for (int i = 1; i <= H; i++) {
        scanf("%s", grid[i] + 1);
    }
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                if (grid[i-1][j] != '#' && 
                    grid[i+1][j] != '#' && 
                    grid[i][j-1] != '#' && 
                    grid[i][j+1] != '#') {
                    printf("No\n");
                    for (int k = 0; k < H + 2; k++) free(grid[k]);
                    free(grid);
                    return 0;
                }
            }
        }
    }
    
    printf("Yes\n");
    for (int i = 0; i < H + 2; i++) free(grid[i]);
    free(grid);
    return 0;
}
// End of Code
