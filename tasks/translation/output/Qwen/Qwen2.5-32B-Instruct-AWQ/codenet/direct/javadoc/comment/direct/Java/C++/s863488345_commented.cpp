#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int mapNum; // Buttle Town图的数量
static int h; // 地图的大小的纵
static int w; // 地图的大小的横
static vector<vector<char>> battleTown; // Buttle Town地图读入用
static int bomberActNum; // 指示了战车的行为数量
static vector<char> bomberAct; // 指示了战车的行为
static int tank[2]; // 战车的位置
static int xOfTank; // 战车的x坐标
static int yOfTank; // 战车的y坐标
static int xOfBomber; // 炸弹的x坐标
static int yOfBomber; // 炸弹的y坐标
static int s; // 显示用
static int k; // 显示用
static int a; // 炸弹的x坐标
static int b; // 炸弹的y坐标
static int x; // 战车的位置x
static int y; // 战车的位置y

void moveBomber(int a, int b) {
    if (0 <= a && a < h && 0 <= b && b < w) {
        if ('^' == battleTown[a][b]) {
            for (int i = a - 1; i >= 0; i--) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        }
        if ('v' == battleTown[a][b]) {
            for (int i = a + 1; i < h; i++) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        }
        if ('<' == battleTown[a][b]) {
            for (int i = b - 1; i >= 0; i--) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        }
        if ('>' == battleTown[a][b]) {
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

                if ('^' == battleTown[j][k] || 'v' == battleTown[j][k] || '<' == battleTown[j][k] || '>' == battleTown[j][k]) {
                    x = j;
                    y = k;
                }
            }
        }

        cin >> bomberActNum;
        string actions;
        cin >> actions;
        bomberAct.assign(actions.begin(), actions.end());

        if (0 <= x && x < h && 0 <= y && y < w) {
            for (int l = 0; l < bomberActNum; l++) {
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
                    cout << battleTown[s][k];
                }
                cout << endl;
            }
        }
    }
}
// End of Code
