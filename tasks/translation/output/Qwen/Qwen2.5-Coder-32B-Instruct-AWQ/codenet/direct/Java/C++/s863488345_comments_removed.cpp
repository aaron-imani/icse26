#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mapNum;
int h;
int w;
vector<vector<char>> battleTown;
int bomberActNum;
string bomberAct;
int x, y;

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        if (battleTown[a][b] == '^') {
            for (int i = a - 1; i >= 0; i--) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == 'v') {
            for (int i = a + 1; i < h; i++) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == '<') {
            for (int i = b - 1; i >= 0; i--) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        } else if (battleTown[a][b] == '>') {
            for (int i = b + 1; i < w; i++) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> mapNum;

    for (int i = 0; i < mapNum; i++) {
        if (1 <= i && i < mapNum) {
            cout << endl;
        }
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

        for (int l = 0; l < bomberActNum; l++) {
            if (bomberAct[l] == 'U') {
                if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                    battleTown[x - 1][y] = '^';
                    battleTown[x][y] = '.';
                    x--;
                }
            } else if (bomberAct[l] == 'D') {
                if (x + 1 < h && battleTown[x + 1][y] == '.') {
                    battleTown[x + 1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            } else if (bomberAct[l] == 'L') {
                if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y - 1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            } else if (bomberAct[l] == 'R') {
                if (y + 1 < w && battleTown[x][y + 1] == '.') {
                    battleTown[x][y + 1] = '>';
                    battleTown[x][y] = '.';
                    y++;
                }
            } else if (bomberAct[l] == 'S') {
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

    return 0;
}
// End of Code
