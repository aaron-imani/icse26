#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int mapNum;
static int h, w;
static char **battleTown;
static int bomberActNum;
static char bomberAct[200000];
static int x, y;

void moveBomber(int a, int b) {
    char dir = battleTown[a][b];
    switch (dir) {
        case '^':
        {
            int current_row = a - 1;
            while (current_row >= 0) {
                char cell = battleTown[current_row][b];
                if (cell == '*') {
                    battleTown[current_row][b] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_row--;
                }
            }
            return;
        }
        case 'v':
        {
            int current_row = a + 1;
            while (current_row < h) {
                char cell = battleTown[current_row][b];
                if (cell == '*') {
                    battleTown[current_row][b] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_row++;
                }
            }
            return;
        }
        case '<':
        {
            int current_col = b - 1;
            while (current_col >= 0) {
                char cell = battleTown[a][current_col];
                if (cell == '*') {
                    battleTown[a][current_col] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_col--;
                }
            }
            return;
        }
        case '>':
        {
            int current_col = b + 1;
            while (current_col < w) {
                char cell = battleTown[a][current_col];
                if (cell == '*') {
                    battleTown[a][current_col] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                } else {
                    current_col++;
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
    for (int i = 0; i < mapNum; i++) {
        if (battleTown != NULL) {
            for (int j = 0; j < h; j++) {
                free(battleTown[j]);
            }
            free(battleTown);
        }
        scanf("%d %d", &h, &w);
        battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc(w * sizeof(char));
        }
        x = -1;
        y = -1;
        for (int j = 0; j < h; j++) {
            char buffer[1024];
            fgets(buffer, 1024, stdin);
            buffer[strlen(buffer) - 1] = '\0';
            for (int k = 0; k < w; k++) {
                char c = buffer[k];
                battleTown[j][k] = c;
                if (c == '^' || c == 'v' || c == '<' || c == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        scanf("%d %s", &bomberActNum, bomberAct);
        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            switch (action) {
                case 'U':
                {
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                        battleTown[x - 1][y] = '^';
                        battleTown[x][y] = '.';
                        x--;
                    }
                    break;
                }
                case 'D':
                {
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x + 1][y] == '.') {
                        battleTown[x + 1][y] = 'v';
                        battleTown[x][y] = '.';
                        x++;
                    }
                    break;
                }
                case 'L':
                {
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                        battleTown[x][y - 1] = '<';
                        battleTown[x][y] = '.';
                        y--;
                    }
                    break;
                }
                case 'R':
                {
                    battleTown[x][y] = '>';
                    if (y + 1 < w && battleTown[x][y + 1] == '.') {
                        battleTown[x][y + 1] = '>';
                        battleTown[x][y] = '.';
                        y++;
                    }
                    break;
                }
                case 'S':
                {
                    moveBomber(x, y);
                    break;
                }
            }
        }
        for (int s = 0; s < h; s++) {
            for (int k = 0; k < w; k++) {
                printf("%c", battleTown[s][k]);
            }
            printf("\n");
        }
        if (i != mapNum - 1) {
            printf("\n");
        }
    }
    return 0;
} // End of Code
