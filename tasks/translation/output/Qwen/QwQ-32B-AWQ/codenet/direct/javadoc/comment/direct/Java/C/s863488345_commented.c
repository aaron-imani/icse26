#include <stdio.h>
#include <stdlib.h>

void moveBomber(int a, int b, char **battleTown, int h, int w);

int main() {
    int mapNum;
    scanf("%d", &mapNum);

    for (int i = 0; i < mapNum; i++) {
        int h, w;
        scanf("%d %d", &h, &w);

        char **battleTown = malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = malloc((w + 1) * sizeof(char));
        }

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = getchar();
            }
            getchar();
        }

        int x = -1, y = -1;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        int bomberActNum;
        scanf("%d", &bomberActNum);
        while (getchar() != '\n');
        char *bomberAct = malloc((bomberActNum + 1) * sizeof(char));
        for (int l = 0; l < bomberActNum; l++) {
            bomberAct[l] = getchar();
        }
        bomberAct[bomberActNum] = '\0';

        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            if (action == 'U') {
                battleTown[x][y] = '^';
                if (x > 0 && battleTown[x-1][y] == '.') {
                    battleTown[x-1][y] = '^';
                    battleTown[x][y] = '.';
                    x--;
                }
            } else if (action == 'D') {
                battleTown[x][y] = 'v';
                if (x < h-1 && battleTown[x+1][y] == '.') {
                    battleTown[x+1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            } else if (action == 'L') {
                battleTown[x][y] = '<';
                if (y > 不在乎 && battleTown[x][y-1] == '.') {
                    battleTown[x][y-1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            } else if (action == 'R') {
                battleTown[x][y] = '>';
                if (y < w-1 && battleTown[x][y+1] == '.') {
                    battleTown[x][y+1] = '>';
                    battleTown[x][y] = '.';
                    y++;
                }
            } else if (action == 'S') {
                moveBomber(x, y, battleTown, h, w);
            }
        }

        for (int s = 0; s < h; s++) {
            for (int k = 0; k < w; k++) {
                printf("%c", battleTown[s][k]);
            }
            printf("\n");
        }

        if (i != mapNum -1) {
            printf("\n");
        }

        for (int j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
        free(bomberAct);
    }
    return 0;
}

void moveBomber(int a, int b, char **battleTown, int h, int w) {
    char dir = battleTown[a][b];
    if (dir == '^') {
        for (int i = a-1; i >= 0; i--) {
            if (battleTown[i][b] == '*') {
                battleTown[i][b] = '.';
                return;
            } else if (battleTown[i][b] == '#') {
                return;
            }
        }
    } else if (dir == 'v') {
        for (int i = a+1; i < h; i++) {
            if (battleTown[i][b] == '*') {
                battleTown[i][b] = '.';
                return;
            } else if (battleTown[i][b] == '#') {
                return;
            }
        }
    } else if (dir == '<') {
        for (int j = b-1; j >= 0; j--) {
            if (battleTown[a][j] == '*') {
                battleTown[a][j] = '.';
                return;
            } else if (battleTown[a][j] == '#') {
                return;
            }
        }
    } else if (dir == '>') {
        for (int j = b+1; j < w; j++) {
            if (battleTown[a][j] == '*') {
                battleTown[a][j] = '.';
                return;
            } else if (battleTown[a][j] == '#') {
                return;
            }
        }
    }
}
// End of Code
