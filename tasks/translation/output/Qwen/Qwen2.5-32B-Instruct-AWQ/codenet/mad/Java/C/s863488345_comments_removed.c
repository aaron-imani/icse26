#include <stdio.h>
#include <stdlib.h>

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
int s;
int k;
int a;
int b;
int x;
int y;

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        if (battleTown[a][b] == '^') {
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
                    if (a == 0) {
                        return;
                    }
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
                    if (a == h) {
                        return;
                    }
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
                    if (b == 0) {
                        return;
                    }
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
                    if (b == w) {
                        return;
                    }
                }
            }
        }
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
            battleTown[j] = (char *)malloc(w * sizeof(char));
        }
        for (j = 0; j < h; j++) {
            for (k = 0; k < w; k++) {
                scanf(" %c", &battleTown[j][k]);
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        scanf("%d", &bomberActNum);
        bomberAct = (char *)malloc((bomberActNum + 1) * sizeof(char));
        scanf("%s", bomberAct);
        if (0 <= x && x < h && 0 <= y && y < w) {
            for (l = 0; l < bomberActNum; l++) {
                if (bomberAct[l] == 'U') {
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                        battleTown[x - 1][y] = '^';
                        battleTown[x][y] = '.';
                        x--;
                    }
                }
                if (bomberAct[l] == 'D') {
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x + 1][y] == '.') {
                        battleTown[x + 1][y] = 'v';
                        battleTown[x][y] = '.';
                        x++;
                    }
                }
                if (bomberAct[l] == 'L') {
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                        battleTown[x][y - 1] = '<';
                        battleTown[x][y] = '.';
                        y--;
                    }
                }
                if (bomberAct[l] == 'R') {
                    battleTown[x][y] = '>'; 
                    if (y + 1 < w && battleTown[x][y + 1] == '.') {
                        battleTown[x][y + 1] = '>'; 
                        battleTown[x][y] = '.'; 
                        y++; 
                    } 
                } 
                if (bomberAct[l] == 'S') { 
                    xOfBomber = x; 
                    yOfBomber = y; 
                    moveBomber(xOfBomber, yOfBomber); 
                } 
            } 
            for (s = 0; s < h; s++) { 
                for (k = 0; k < w; k++) { 
                    printf("%c", battleTown[s][k]); 
                } 
                printf("\n"); 
            } 
        } 
        for (j = 0; j < h; j++) { 
            free(battleTown[j]); 
        } 
        free(battleTown); 
        free(bomberAct); 
    } 
    return 0; 
} // End of Code
