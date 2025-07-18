#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mapNum;
int h, w;
int x, y;
char **battleTown;
int bomberActNum;
char *bomberAct;

void moveBomber(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w) return;
    char dir = battleTown[a][b];
    
    switch (dir) {
        case '^': {
            int currentRow = a;
            while (currentRow > 0) {
                currentRow--;
                if (battleTown[currentRow][b] == '*') {
                    battleTown[currentRow][b] = '.';
                    return;
                } else if (battleTown[currentRow][b] == '#') {
                    return;
                }
            }
            return;
        }
        case 'v': {
            int currentRow = a;
            while (currentRow < h - 1) {
                currentRow++;
                if (battleTown[currentRow][b] == '*') {
                    battleTown[currentRow][b] = '.';
                    return;
                } else if (battleTown[currentRow][b] == '#') {
                    return;
                }
            }
            return;
        }
        case '<': {
            int currentCol = b;
            while (currentCol > 罪? 0) {
                currentCol--;
                if (battleTown[a][currentCol] == '*') {
                    battleTown[a][currentCol] = '.';
                    return;
                } else if (battleTown[a][currentCol] == '#') {
                    return;
                }
            }
            return;
        }
        case '>': {
            int currentCol = b;
            while (currentCol < w - 1) {
                currentCol++;
                if (battleTown[a][currentCol] == '*') {
                    battleTown[a][currentCol] = '.';
                    return;
                } else if (battleTown[a][currentCol] == '#') {
                    return;
                }
            }
            return;
        }
    }
}

int main() {
    scanf("%d", &mapNum);
    for (int i = 0; i < mapNum; i++) {
        if (i > 0) {
            printf("\n");
        }
        scanf("%d %d", &h, &w);
        battleTown = (char**)malloc(h * sizeof(char*));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char*)malloc((w + 1) * sizeof(char));
        }
        x = -1;
        y = -1;
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
        scanf("%d", &bomberActNum);
        bomberAct = (char*)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);
        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            switch (action) {
                case 'U':
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
                    battleTown[x][y] = '>';;
                    if (y + 1 < w && battleTown[x][y+1] == '.') {
                        battleTown[x][y+1] = '>';;
                        battleTown[x][y] = '.';
                        y++;
                    }
                    break;
                case 'S':
                    moveBomber(x, y);
                    break;
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
}
// End of Code
