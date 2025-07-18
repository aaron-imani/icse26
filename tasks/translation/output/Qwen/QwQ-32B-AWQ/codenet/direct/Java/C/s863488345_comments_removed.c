#include <stdio.h>
#include <stdlib.h>

int mapNum;
int h, w;
char **battleTown;
int bomberActNum;
char *bomberAct;
int x, y;

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        if (battleTown[a][b] == '^') {
            for (int i = a - 1; i >= 0; i--) {
                if (a <= 0) return;
                if (battleTown[a - 1][b] == '*') {
                    battleTown[a - 1][b] = '.';
                    return;
                } else if (battleTown[a - 1][b] == '#') {
                    return;
                } else {
                    a--;
                    if (a == 0) return;
                }
            }
        }
        if (battleTown[a][b] == 'v') {
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
        }
        if (battleTown[a][b] == '<') {
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
        }
        if (battleTown[a][b] == '>') {
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
}

int main() {
    scanf("%d", &mapNum);
    for (int i = 0; i < mapNum; i++) {
        if (i > 0) printf("\n");
        scanf("%d %d", &h, &w);
        battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc((w + 1) * sizeof(char));
        }
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
        scanf("%d %s", &bomberActNum, bomberAct);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);
        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            if (action == 'U') {
                battleTown[x][y] = '^';
                if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                    battleTown[x - 1][y] = '^';
                    battleTown[x][y] = '.';
                    x--;
                }
            }
            if (action == 'D') {
                battleTown[x][y] = 'v';
                if (x + 1 < h && battleTown[x + 1][y] == '.') {
                    battleTown[x + 1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            }
            if (action == 'L') {
                battleTown[x][y] = '<';
                if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y - 1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            }
            if (action == 'R') {
                battleTown[x][y] = '>';
                if (y + 1 < w && battleTown[x][y + 1] == '.') {
                    battleTown[x][y + 1] = '>';
                    battleTown[x][y] = '.';
                    y++;
                }
            }
            if (action == 'S') {
                moveBomber(x, y);
            }
        }
        for (int s = 0; s < h; s++) {
            for (int k = 0; k < w; k++) {
                printf("%c", battleTown[s][k]);
            }
            printf("\n");
        }
        for (int j = 0; j < h; j++) free(battleTown[j]);
        free(battleTown);
    }
    return 0;
}
// End of Code
