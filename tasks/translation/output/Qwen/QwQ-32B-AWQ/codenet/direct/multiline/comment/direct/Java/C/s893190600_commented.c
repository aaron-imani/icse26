#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int H, W;
    if (scanf("%d %d", &H, &W) != 2) {
        return 1;
    }

    char **grid = (char **)malloc((H + 2) * sizeof(char *));
    if (!grid) {
        return 1;
    }
    for (int i = 0; i < H + 2; i++) {
        grid[i] = (char *)malloc((W + 2) * sizeof(char));
        if (!grid[i]) {
            for (int j = 0; j < i; j++) {
                free(grid[j]);
            }
            free(grid);
            return 1;
        }
        for (int j = 0; j < W + 2; j++) {
            grid[i][j] = '.';
        }
    }

    for (int i = 1; i <= H; i++) {
        char line[1001];
        if (fgets(line, sizeof(line), stdin) == NULL) {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        for (int j = 1; j <= W; j++) {
            grid[i][j] = line[j - 1];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                int has_neighbor = 0;
                if (grid[i - 1][j] == '#') has_neighbor = 1;
                if (grid[i + 1][j] == '#') has_neighbor = 1;
                if (grid[i][j - 1] == '#') has_neighbor = 1;
                if (grid[i][j + 1] == '#') has_neighbor = 1;
                if (!has_neighbor) {
                    printf("No\n");
                    for (int k = 0; k < H + 2; k++) {
                        free(grid[k]);
                    }
                    free(grid);
                    return  RequestMethod;
                }
            }
        }
    }

    printf("Yes\n");

    for (int i = 0; i < H + 2; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
// End of Code
