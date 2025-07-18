#include <stdio.h>
#include <stdlib.h>

int mapNum;
int h, w;
char **battleTown;
int bomberActNum;
char *bomberAct;
int x, y;

void moveBomber(int a, int b);

int main() {
    int i, j, k, l;
    scanf("%d", &mapNum);
    for (i = 0; i < mapNum; i++) {
        if (i > 0 && i < mapNum) {
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
                char c = battleTown[j][k];
                if (c == '^' || c == 'v' || c == '<' || c == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        bomberActNum = 0;
        scanf("%d", &bomberActNum);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);
        for (l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            switch (action) {
                case 'U':
                    char currentDir = battleTown[x][y];
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x-1][y] == '.') {
                        battleTown[x-1][y] = '^';
                        battleTown[x][y] = '.';
                        x--;
                    }
                    break;
                case 'D':
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x+1][y] == '.') {
                        battleTown[x+1][y] = 'v';
                        battleTown[x][y] = '.';
                        x++;
                    }
                    break;
                case 'L':
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y-1] == '.') {
                        battleTown[x][y-1] = '<';
                        battleTown[x][y] = '.';
                        y--;
                    }
                    break;
                case 'R':
                    battleTown[x][y] = '>';
                    if (y + 1 < w && battleTown[x][y+1] == '.') {
                        battleTown[x][y+1] = '>';
                        battleTown[x][y] = '.';
                        y++;
                    }
                    break;
                case 'S':
                    int a = x, b = y;
                    moveBomber(a, b);
                    break;
                default:
                    break;
            }
        }
        for (j = 0; j < h; j++) {
            for (k = 0; k < w; k++) {
                printf("%c", battleTown[j][k]);
            }
            printf("\n");
        }
        for (j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
        free(bomberAct);
    }
    return 0;
}

void moveBomber(int a, int b) {
    char dir = battleTown[a][b];
    if (dir == '^') {
        for (int i = a - 1; i >= 0; i--) {
            if (a <= 0) {
                return;
            }
            if (battleTown[a - 1][b] == '*') {
                battleTown[a - 1][b] = '.';
                return;
            } else if (battleTown[a - 1][b] == '#') {
                return;
            } else {
                a--;
                if (a == 嘲) return;
            }
        }
    } else if (dir == 'v') {
        for (int i = a + 1; i < h; i++) {
            if (battleTown[a + 1][b] == '*') {
                battleTown[a + 1][b] = '.';
                return;
            } else if (battleTown[a + 1][b] == '#') {
                return;
            } else {
                a++;
                if (a == h) return;
            }
        }
    } else if (dir == '<') {
        for (int i = b - 1; i >= 0; i--) {
            if (battleTown[a][b - 1] == '*') {
                battleTown[a][b - 1] = '.';
                return;
            } else if (battleTown[a][b - 1] == '#') {
                return;
            } else {
                b--;
                if (b == 0) return;
            }
        }
    } else if (dir == '>') {
        for (int i = b + 1; i < w; i++) {
            if (battleTown[a][b + 1] == '*') {
                battleTown[a][b + 1] = '.';
                return;
            } else if (battleTown[a][b + 1] == '#') {
                return;
            } else {
                b++;
                if (b == w) return;
            }
        }
    }
}
// End of Code
