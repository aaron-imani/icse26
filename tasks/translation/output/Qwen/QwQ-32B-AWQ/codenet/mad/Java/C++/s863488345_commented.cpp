#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mapNum;
int h, w;
vector<vector<char>> battleTown;
int bomberActNum;
string bomberAct;
int xOfTank, yOfTank, xOfBomber, yOfBomber;
int s, k, a, b;
int x, y;

void moveBomber(int a, int b);

int main() {
    cin >> mapNum;
    for (int i = 0; i < mapNum; i++) {
        if (i >= 1 && i < mapNum) cout << endl;
        cin >> h >> w;
        battleTown.resize(h, vector<char>(w));
        for (int j = 0; j < h; j++) {
            string line;
            cin >> line;
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = line[k];
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        cin >> bomberActNum >> bomberAct;
        if (0 <= x && x <= h && 0 <= y && y <= w) {
            for (int l = 0; l < bomberActNum; l++) {
                char c = bomberAct[l];
                if (c == 'U') {
                    battleTown[x][y] = '^';
                    if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                        battleTown[x - 1][y] = '^';
                        battleTown[x][y] = '.';
                        x--;
                    }
                } else if (c == 'D') {
                    battleTown[x][y] = 'v';
                    if (x + 1 < h && battleTown[x + 1][y] == '.') {
                        battleTown[x + 1][y] = 'v';
                        battleTown[x][y] = '.';
                        x++;
                    }
                } else if (c == 'L') {
                    battleTown[x][y] = '<';
                    if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                        battleTown[x][y - 1] = '<';
                        battleTown[x][y] = '.';
                        y--;
                    }
                } else if (c == 'R') {
                    battleTown[x][y] = '>'; 
                    if (y + 1 < w && battleTown[x][y + 1] == '.') {
                        battleTown[x][y + 1] = '>'; 
                        battleTown[x][y] = '.';
                        y++;
                    }
                } else if (c == 'S') {
                    xOfBomber = x;
                    yOfBomber = y;
                    moveBomber(xOfBomber, yOfBomber);
                }
            }
            for (s = 0; s < h; s++) {
                for (k = 0; k < w; k++) {
                    cout << battleTown[s][k];
                }
                cout << endl;
            }
        }
    }
    return 0;
}

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        char dir = battleTown[a][b];
        int currentX = a, currentY = b;
        switch (dir) {
            case '^':
                currentX--;
                while (currentX >= 0) {
                    char cell = battleTown[currentX][currentY];
                    if (cell == '*') {
                        battleTown[currentX][currentY] = '.';
                        return;
                    } else if (cell == '#') {
                        return;
                    }
                    currentX--;
                }
                break;
            case 'v':
                currentX++;
                while (currentX < h) {
                    char cell = battleTown[currentX][currentY];
                    if (cell == '*') {
                        battleTown[currentX][currentY] = '.';
                        return;
                    } else if ( blir cell == '#') {
                        return;
                    }
                    currentX++;
                }
                break;
            case '<':
                currentY--;
                while (currentY >= 0) {
                    char cell = battleTown[currentX][currentY];
                    if (cell == '*') {
                        battleTown[currentX][currentY] = '.';
                        return;
                    } else if (cell == '#') {
                        return;
                    }
                    currentY--;
                }
                break;
            case '>':
                currentY++;
                while (currentY < w) {
                    char cell = battleTown[currentX][currentY];
                    if (cell == '*') {
                        battleTown[currentX][currentY] = '.';
                        return;
                    } else if (cell == '#') {
                        return;
                    }
                    currentY++;
                }
                break;
        }
    }
}
// End of Code
