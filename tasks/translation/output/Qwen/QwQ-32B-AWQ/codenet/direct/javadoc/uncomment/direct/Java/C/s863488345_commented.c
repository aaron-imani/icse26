#include <stdio.h>
#include <stdlib.h>

void moveBomber(char **battleTown, int h, int w, int a, int b) {
    char dir = battleTown[a][b];
    if (dir == '^') {
        for (int i = a - 1; i >= 0; i--) {
            if (a <= 0) return;
            else {
                if (battleTown[a - 1][b] == '*') {
                    battleTown[a - 1][b] = '.';
                    return;
                } else if (battleTown[a - 1][b] == '#') {
                    return;
                } else {
                    a--;
                }
            }
        }
    } else if (dir == 'v') {
        for (int i = a + 1; i < h; i++) {
            if (a >= h - 1) return;
            else {
                if (battleTown[a + 1][b] == '*') {
                    battleTown[a + 1][b] = '.';
                    return;
                } else if (battleTown[a + 1][b] == '#') {
                    return;
                } else {
                    a++;
                }
            }
        }
    } else if (dir == '<') {
        for (int i = b - 1; i >= 0; i--) {
            if (b <= 0) return;
            else {
                if (battleTown[a][b - 1] == '*') {
                    battleTown[a][b - 1] = '.';
                    return;
                } else if (battleTown[a][b - 1] == '#') {
                    return;
                } else {
                    b--;
                }
            }
        }
    } else if (dir == '>') {
        for (int i = b + 1; i < w; i++) {
            if (b >= w - 1) return;
            else {
                if (battleTown[a][b + 1] == '*') {
                    battleTown[a][b + 1] = '.';
                    return;
                } else if (battleTown[a][b + 1] == '#') {
                    return;
                } else {
                    b++;
                }
            }
        }
    }
}

int main() {
    int mapNum;
    scanf("%d", &mapNum);
    for (int i = 0; i < mapNum; i++) {
        int h, w;
        scanf("%d %d", &h, &w);
        char **battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc((w + 1) * sizeof(char));
        }
        int x = -1, y = -1;
        for (int j = 0; j < h; j++) {
            scanf("%s", battleTown[j]);
            for (int k = 0; k < w; k++) {
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' ||
                    battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        int bomberActNum;
        scanf("%d", &bomberActNum);
        char bomberAct[bomberActNum + 1];
        scanf("%s", bomberAct);
        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            if (action == 'U') {
                if (x > 0 && battleTown[x - 1][y] == '.') {
                    battleTown[x][y] = '.';
                    x--;
                    battleTown[x][y] = '^';
                }
            } else if (action == 'D') {
                if (x < h - 1 && battleTown[x + 1][y] == '.') {
                    battleTown[x][y] = '.';
                    x++;
                    battleTown[x][y] = 'v';
                }
            } else if (action == 'L') {
                if (y > 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y] = '.';
                    y--;
                    battleTown[x][y] = '<';
                }
            } else if (action == 'R') {
                if (y < w - 1 && battleTown[x][y + 1] == '.') {
                    battleTown[x][y] = '.';
                    y++;
                    battleTown[x][y] = '>';
                }
            } else if (action == 'S') {
                moveBomber(battleTown, h, w, x, y);
            }
        }
        for (int s = 0; s < h; s++) {
            printf("%s\n", battleTown[s]);
        }
        for (int j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
    }
    return 0;
}
// End of Code
