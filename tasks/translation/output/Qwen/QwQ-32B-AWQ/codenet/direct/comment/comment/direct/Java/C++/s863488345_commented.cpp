#include <iostream>
#include <vector>
using namespace std;

static int mapNum;
static int h, w;
static vector<vector<char>> battleTown;
static int bomberActNum;
static vector<char> bomberAct;
static int x, y;

void moveBomber(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w) {
        return;
    }

    char direction = battleTown[a][b];
    if (direction == '^') {
        for (int i = a - 1; i >= 0; --i) {
            char current = battleTown[i][b];
            if (current == '*') {
                battleTown[i][b] = '.';
                return;
            } else if (current == '#') {
                return;
            }
        }
    } else if (direction == 'v') {
        for (int i = a + 1; i < h; ++i) {
            char current = battleTown[i][b];
            if (current == '*') {
                battleTown[i][b] = '.';
                return;
            } else if (current == '#') {
                return;
            }
        }
    } else if (direction == '<') {
        for (int j = b - 1; j >= 0; --j) {
            char current = battleTown[a][j];
            if (current == '*') {
                battleTown[a][j] = '.';
                return;
            } else if (current == '#') {
                return;
            }
        }
    } else if (direction == '>') {
        for (int j = b + 1; j < w; ++j) {
            char current = battleTown[a][j];
            if (current == '*') {
                battleTown[a][j] = '.';
                return;
            } else if (current == '#') {
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> mapNum;

    for (int i = 0; i < mapNum; ++i) {
        if (i != 0) {
            cout << endl;
        }

        cin >> h >> w;

        battleTown.resize(h);
        for (int j = 0; j < h; ++j) {
            battleTown[j].resize(w);
            string line;
            cin >> line;
            for (int k = 0; k < w; ++k) {
                battleTown[j][k] = line[k];

                if (battleTown[j][k] == '^' || 
                    battleTown[j][k] == 'v' || 
                    battleTown[j][k] == '<' || 
                    battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        cin >> bomberActNum;
        string actions;
        cin >> actions;
        bomberAct.assign(actions.begin(), actions.end());

        for (int l = 0; l < bomberActNum; ++l) {
            char action = bomberAct[l];

            if (action == 'U') {
                battleTown[x][y] = '^';
                if (x - 1 >= 0 && battleTown[x-1][y] == '.') {
                    battleTown[x-1][y] = '^';
                    battleTown[x][y] = '.';
                    x--;
                }
            } else if (action == 'D') {
                battleTown[x][y] = 'v';
                if (x + 1 < h && battleTown[x+1][y] == '.') {
                    battleTown[x+1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            } else if (action == 'L') {
                battleTown[x][y] = '<';
                if (y - 1 >= 0 && battleTown[x][y-1] == '.') {
                    battleTown[x][y-1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            } else if (action == 'R') {
                battleTown[x][y] = '>';
                if (y + 1 < w && battleTown[x][y+1] == '.') {
                    battleTown[x][y+1] = '>';
                    battleTown[x][y] = '.';
                    y++;
                }
            } else if (action == 'S') {
                moveBomber(x, y);
            }
        }

        for (int s = 0; s < h; ++s) {
            for (int k = 0; k < w; ++k) {
                cout << battleTown[s][k];
            }
            cout << endl;
        }
    }

    return 0;
}

// End of Code
