#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char **grid = (char**)malloc((H + 2) * sizeof(char*));
    for (int i = 0; i < H + 2; i++) {
        grid[i] = (char*)malloc((W + 2) * sizeof(char));
        memset(grid[i], '.', W + 2);
    }
    for (int i = 0; i < H; i++) {
        char line[W + 2];
        fgets(line, W + 2, stdin);
        line[strcspn(line, "\n")] = '\0';
        for (int j = 0; j < W; j++) {
            grid[i + 1][j + 1] = line[j];
        }
    }
    if (H == 1 && W == 1) {
        printf("No\n");
        goto cleanup;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#' && 
                grid[i - 1][j] != '#' && 
                grid[i + 1][j] != '#' && 
                grid[i][j - 1] != '#' && 
                grid[i][j + 1] != '#') {
                printf("No\n");
                goto cleanup;
            }
        }
    }
    printf("Yes\n");
cleanup:
    for (int i = 0; i < H + 2; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
// End of Code
