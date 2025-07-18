#include <iostream>
#include <vector>
using namespace std;

static int mapNum;
static int h, w;
static vector<vector<char>> battleTown;
static int bomberActNum;
static vector<char> bomberAct;
static int xOfTank, yOfTank, xOfBomber, yOfBomber, s, k, a, b, x, y;

static void moveBomber(int a, int b) {
    if (0 <= a && a <= h && 0 <= b && b <= w) {
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
        } else if (battleTown[a][b] == 'v') {
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
        } else if (battleTown[a][b] == '<') {
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
        } else if (battleTown[a][b] == '>') {
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
    cin >> mapNum;
    for (int i = 0; i < mapNum; i++) {
        if (i > 0) cout << endl;
        cin >> h >> w;
        battleTown.resize(h);
        for (int j = 0; j < h; j++) {
            string line;
            cin >> line;
            battleTown[j].resize(w);
            for (int k = 0; k < w; k++) {
                char c = line[k];
                battleTown[j][k] = c;
                if (c == '^' || c == 'v' || c == '<' || c == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        cin >> bomberActNum;
        string actStr;
        cin >> actStr;
        bomberAct = vector<char>(actStr.begin(), actStr.end());
        for (int l = 0; l < bomberActNum; l++) {
            char cmd = bomberAct[l];
            if (cmd == 'U') {
                battleTown[x][y] = '^';
                if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                    battleTown[x - 1][y] = '^';
                    battleTown[x][y] = '.';
                    x--;
                }
            } else if (cmd == 'D') {
                battleTown[x][y] = 'v';
                if (x + 1 < h && battleTown[x + 1][y] == '.') {
                    battleTown[x + 1][y] = 'v';
                    battleTown[x][y] = '.';
                    x++;
                }
            } else if (cmd == 'L') {
                battleTown[x][y] = '<';
                if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y - 1] = '<';
                    battleTown[x][y] = '.';
                    y--;
                }
            } else if (cmd == 'R') {
                battleTown[x][y] = '>';
                if (y + 1 < w && battleTown[x][y + 1] == '.') {
                    battleTown[x][y + 1] = '>';
                    battleTown[x][y] = '.';
                    y++;
                }
            } else if (cmd == 'S') {
                xOfBomber = x;
                yOfBomber = y;
                moveBomber(xOfBomber, yOfBomber);
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
