#include <stdio.h>
#include <stdlib.h>

int mapNum;
int h, w;
char **battleTown;
int x, y;
int bomberActNum;
char *bomberAct;

void moveBomber(int a, int b) {
    char dir = battleTown[a][b];
    int currentA, currentB;

    switch (dir) {
        case '^': // Up direction
            currentA = a - 1;
            currentB = b;
            while (currentA >= 0) {
                char c = battleTown[currentA][currentB];
                if (c == '*') {
                    battleTown[currentA][currentB] = '.';
                    return;
                } else if (c == '#') {
                    return;
                }
                currentA--;
            }
            return;
        case 'v': // Down direction
            currentA = a + 1;
            currentB = b;
            while (currentA < h) {
                char c = battleTown[currentA][currentB];
                if (c == '*') {
                    battleTown[currentA][currentB] = '.';
                    return;
                } else if (c == '#') {
                    return;
                }
                currentA++;
            }
            return;
        case '<': // Left direction
            currentA = a;
            currentB = b - 1;
            while (currentB >= 0) {
                char c = battleTown[currentA][currentB];
                if (c == '*') {
                    battleTown[currentA][currentB] = '.';
                    return;
                } else if (c == '#') {
                    return;
                }
                currentB--;
            }
            return;
        case '>': // Right direction
            currentA = a;
            currentB = b + 1;
            while (currentB < w) {
                char c = battleTown[currentA][currentB];
                if (c == '*') {
                    battleTown[currentA][currentB] = '.';
                    return;
                } else if (c == '#') {
                    return;
                }
                currentB++;
            }
            return;
        default:
            return;
    }
}

int main() {
    int i;
    scanf("%d", &mapNum);
    for (i = 0; i < mapNum; i++) {
        if (i > 0) {
            printf("\n");
        }
        scanf("%d %d", &h, &w);
        battleTown = (char **)malloc(h * sizeof(char *));
        for (int j = 0; j < h; j++) {
            battleTown[j] = (char *)malloc(w * sizeof(char));
        }
        x = -1;
        y = -1;
        for (int j = 0; j < h; j++) {
            char line[256];
            scanf("%s", line);
            for (int k = 0; k < w; k++) {
                char c = line[k];
                battleTown[j][k] = c;
                if (c == '^' || c == 'v' || c == '<' || c == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        scanf("%d", &bomberActNum);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);
        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            switch (action) {
                case 'U':
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x-1][y] == '.') {
                        battleTown[x][y] = '.';
                        x--;
                        battleTown[x][y] = '^';
                    }
                    break;
                case 'D':
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x+1][y] == '.') {
                        battleTown[x][y] = '.';
                        x++;
                        battleTown[x][y] = 'v';
                    }
                    break;
                case 'L':
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y-1] == '.') {
                        battleTown[x][y] = '.';
                        y--;
                        battleTown[x][y] = '<';
                    }
                    break;
                case 'R':
                    battleTown[x][y] = '>';
                    if (y + 1 < w && battleTown[x][y+1] == '.') {
                        battleTown[x][y] = '.';
                        y++;
                        battleTown[x][y] = '>';
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
        // Free the memory for this map
        for (int j = 0; j < h; j++) {
            free(battleTown[j]);
        }
        free(battleTown);
        free(bomberAct);
    }
    return 0;
}
// End of Code
