#include <stdio.h>
#include <stdlib.h>

int mapNum;
int h, w;
char **battleTown;
int bomberActNum;
char *bomberAct;
int x, y;

void moveBomber(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w) return;

    char dir = battleTown[a][b];
    int currentRow = a, currentCol = b;

    switch (dir) {
        case '^': // Up
            currentRow--;
            while (currentRow >= 0) {
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    currentRow--;
                }
            }
            return;
        case 'v': // Down
            currentRow++;
            while (currentRow < h) {
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    currentRow++;
                }
            }
            return;
        case '<': // Left
            currentCol--;
            while (currentCol >= 0) {
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    currentCol--;
                }
            }
            return;
        case '>': // Right
            currentCol++;
            while (currentCol < w) {
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    currentCol++;
                }
            }
            return;
    }
}

int main() {
    int i, j, k, l;

    scanf("%d", &mapNum);

    for (i = 0; i < mapNum; i++) {
        if (i > 0) {
            printf("\n");
        }

        scanf("%d %d", &h, &w);

        battleTown = (char **)malloc(h * sizeof(char *));
        for (j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc((w + 1) * sizeof(char));
        }

        x = -1;
        y = -1;

        for (j = 0; j < h; j++) {
            scanf("%s", battleTown[j]);
            for (k = 0; k < w; k++) {
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        scanf("%d", &bomberActNum);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);

        if (x >= 0 && x < h && y >= 0 && y < w) {
            for (l = 0; l < bomberActNum; l++) {
                char action = bomberAct[l];

                switch (action) {
                    case 'U':
                        if (x - 1 >= 0 && battleTown[x-1][y] == '.') {
                            battleTown[x][y] = '.';
                            x--;
                            battleTown[x][y] = '^';
                        }
                        break;
                    case 'D':
                        if (x + 1 < h && battleTown[x+1][y] == '.') {
                            battleTown[x][y] = '.';
                            x++;
                            battleTown[x][y] = 'v';
                        }
                        break;
                    case 'L':
                        if (y - 1 >= 0 && battleTown[x][y-1] == '.') {
                            battleTown[x][y] = '.';
                            y--;
                            battleTown[x][y] = '<';
                        }
                        break;
                    case 'R':
                        if (y + 1 < w && battleTown[x][y+1] == '.') {
                            battleTown[x][y] = '.';
                            y++;
                            battleTown[x][y] = '>';;
                        }
                        break;
                    case 'S':
                        moveBomber(x, y);
                        break;
                }
            }

            for (j = 0; j < h; j++) {
                printf("%s\n", battleTown[j]);
            }
        }

        for (j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
        free(bomberAct);
    }

    return 0;
}
// End of Code
