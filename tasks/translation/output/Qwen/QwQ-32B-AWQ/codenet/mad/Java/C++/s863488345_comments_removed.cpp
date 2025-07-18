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
int x, y;

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        char dir = battleTown[a][b];
        int currentRow = a, currentCol = b;
        if (dir == '^') {
            while (true) {
                currentRow--;
                if (currentRow < 0) break;
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                }
            }
        } else if (dir == 'v') {
            while (currentRow + 1 < h) {
                currentRow++;
                char cell = battleTown[currentRow][currentCol];
                if (cell == '*') {
                    battleTown[currentRow][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                }
            }
        } else if (dir == '<') {
            while (currentCol > 于 0) {
                currentCol--;
                char cell = battleTown[a][currentCol];
                if (cell == '*') {
                    battleTown[a][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                }
            }
        } else if (dir == '>') {
            while (currentCol + 1 < w) {
                currentCol++;
                char cell = battleTown[a][currentCol];
                if (cell == '*') {
                    battleTown[a][currentCol] = '.';
                    return;
                } else if (cell == '#') {
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> mapNum;
    for (int i = 0; i < mapNum; ++i) {
        if (i > 0) cout << endl;
        cin >> h >> w;
        battleTown.assign(h, vector<char>(w));
        x = -1;
        y = -1;
        for (int j = 0; j < h; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < w; ++k) {
                battleTown[j][k] = line[k];
                if (line[k] == '^' || line[k] == 'v' || line[k] == '<' || line[k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        cin >> bomberActNum >> bomberAct;
        if (x >= 0 && x < h && y >= 0 && y < w) {
            for (int l = 0; l < bomberActNum; ++l) {
                char action = bomberAct[l];
                if (action == 'U') {
                    if (x - 1 >= 0 && battleTown[x-1][y] == '.') {
                        battleTown[x][y] = '.';
                        x--;
                        battleTown[x][y] = '^';
                    }
                } else if (action == 'D') {
                    if (x + 1 < h && battleTown[x+1][y] == '.') {
                        battleTown[x][y] = '.';
                        x++;
                        battleTown[x][y] = 'v';
                    }
                } else if (action == 'L') {
                    if (y - 1 >= 0 && battleTown[x][y-1] == '.') {
                        battleTown[x][y] = '.';
                        y--;
                        battleTown[x][y] = '<';
                    }
                } else if (action == 'R') {
                    if (y + 1 < w && battleTown[x][y+1] == '.') {
                        battleTown[x][y] = '.';
                        y++;
                        battleTown[x][y] = '>'; 
                    }
                } else if (action == 'S') {
                    moveBomber(x, y);
                }
            }
            for (int s = 0; s < h; s++) {
                for (int k = 0; k < w; k++) {
                    cout << battleTown[s][k];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// End of Code
