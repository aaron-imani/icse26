#include <stdio.h>
#include <stdlib.h>

int mapNum;
int h, w;
int x, y;
char **battleTown;
char *bomberAct;

void moveBomber(int a, int b, char **battleTown, int h, int w) {
    char direction = battleTown[a][b];
    switch (direction) {
        case '^': {
            int current_x = a - 1;
            int current_y = b;
            while (current_x >= 0) {
                char cell = battleTown[current_x][current_y];
                if (cell == '*') {
                    battleTown[current_x][current_y] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_x--;
                }
            }
            return;
        }
        case 'v': {
            int current_x = a + 1;
            int current_y = b;
            while (current_x < h) {
                char cell = battleTown[current_x][current_y];
                if (cell == '*') {
                    battleTown[current_x][current_y] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_x++;
                }
            }
            return;
        }
        case '<': {
            int current_x = a;
            int current_y = b - 1;
            while (current_y >= 0) {
                char cell = battleTown[current_x][current_y];
                if (cell == '*') {
                    battleTown[current_x][current_y] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_y--;
                }
            }
            return;
        }
        case '>': {
            int current_x = a;
            int current_y = b + 1;
            while (current_y < w) {
                char cell = battleTown[current_x][current_y];
                if (cell == '*') {
                    battleTown[current_x][current_y] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_y++;
                }
            }
            return;
        }
        default:
            return;
    }
}

int main() {
    scanf("%d", &mapNum);
    int first = 1;
    for (int i = 0; i < mapNum; i++) {
        if (i != 0) {
            printf("\n");
        }
        scanf("%d %d", &h, &w);
        battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc((w + 1) * sizeof(char));
        }
        x = -1;
        y = -1;
        for (int j = 0; j < h; j++) {
            char tempRow[w + 1];
            scanf("%s", tempRow);
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = tempRow[k];
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' ||
                    battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        int bomberActNum;
        scanf("%d", &bomberActNum);
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
            } else if (action == 'D') {
                battleTown[x][y] = 'v';
                if (x + 1 < h && battleTown[x + 1][y] == '.') {
                    battleTown[x + 1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            } else if (action == 'L') {
                battleTown[x][y] = '<';
                if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y - 1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            } else if (action == 'R') {
                battleTown[x][y] = '>';
                if (y + 1 < w && battleTown[x][y + 1] == '.') {
                    battleTown[x][y + 1] = '>';
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
        free(bomberAct);
        for (int j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
    }
    return 0;
} // End of Code
