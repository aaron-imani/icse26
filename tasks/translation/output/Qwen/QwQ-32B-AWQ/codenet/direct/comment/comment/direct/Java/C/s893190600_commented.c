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

    int rows = H + 2;
    int cols = W + 2;
    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)calloc(cols, sizeof(char));
    }

    for (int i = 1; i <= H; i++) {
        char line[cols];
        fgets(line, cols, stdin);
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        for (int j = 0; j < strlen(line); j++) {
            grid[i][j + 1] = line[j];
        }
    }

    int found = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] == '#') {
                if (grid[i - 1][j] != '#' &&
                    grid[i + 1][j] != '#' &&
                    grid[i][j - 1] != '#' &&
                    grid[i][j + 1] != '#') {
                    found = 1;
                    goto end;
                }
            }
        }
    }

end:
    if (found) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
// End of Code
