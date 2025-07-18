#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mapNum;
int h;
int w;
char **battleTown;
int bomberActNum;
char *bomberAct;
int xOfTank;
int yOfTank;
int xOfBomber;
int yOfBomber;
int x;
int y;

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        if (battleTown[a][b] == '^') {
            for (int i = a - 1; i >= 0; i--) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == 'v') {
            for (int i = a + 1; i < h; i++) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == '<') {
            for (int i = b - 1; i >= 0; i--) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == '>') {
            for (int i = b + 1; i < w; i++) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &mapNum);

    for (int i = 0; i < mapNum; i++) {
        if (1 <= i && i < mapNum) {
            printf("\n");
        }
        scanf("%d %d", &h, &w);

        battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc((w + 1) * sizeof(char)); // +1 for null terminator
            scanf("%s", battleTown[j]);

            for (int k = 0; k < w; k++) {
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        scanf("%d", &bomberActNum);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char)); // +1 for null terminator
        scanf("%s", bomberAct);

        if (0 <= x && x < h && 0 <= y && y < w) {
            for (int l = 0; l < bomberActNum; l++) {
                if (bomberAct[l] == 'U') {
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                        battleTown[x - 1][y] = '^';
                        battleTown[x][y] = '.';
                        x--;
                    }
                } else if (bomberAct[l] == 'D') {
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x + 1][y] == '.') {
                        battleTown[x + 1][y] = 'v';
                        battleTown[x][y] = '.';
                        x++;
                    }
                } else if (bomberAct[l] == 'L') {
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                        battleTown[x][y - 1] = '<';
                        battleTown[x][y] = '.';
                        y--;
                    }
                } else if (bomberAct[l] == 'R') {
                    battleTown[x][y] = '>';n                    if (y + 1 < w && battleTown[x][y + 1] == '.') {
                        battleTown[x][y + 1] = '>';n                        battleTown[x][y] = '.';
                        y++;
                    }
                } else if (bomberAct[l] == 'S') {
                    xOfBomber = x;
                    yOfBomber = y;
                    moveBomber(xOfBomber, yOfBomber);
                }
            }

            for (int s = 0; s < h; s++) {
                for (int k = 0; k < w; k++) {
                    printf("%c", battleTown[s][k]);
                }
                printf("\n");
            }

            for (int j = 0; j < h; j++) {
                free(battleTown[j]);
            }
            free(battleTown);
            free(bomberAct);
        }
    }

    return 0;
}
// End of Code
