#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mapNum;
int h;
int w;
vector<vector<char>> battleTown;
int bomberActNum;
vector<char> bomberAct;
int tank[2];
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

int main() {
    int mapNum;
    cin >> mapNum;

    for (int i = 0; i < mapNum; i++) {
        if (1 <= i && i < mapNum) {
            cout << endl;
        }
        cin >> h >> w;

        battleTown = vector<vector<char>>(h, vector<char>(w));

        for (int j = 0; j < h; j++) {
            string c;
            cin >> c;
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = c[k];

                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        cin >> bomberActNum;
        string bomberActStr;
        cin >> bomberActStr;
        bomberAct = vector<char>(bomberActStr.begin(), bomberActStr.end());

        if (0 <= x && x <= h && 0 <= y && y <= w) {
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

void moveBomber(int a, int b) {
    if (0 <= a && a <= h && 0 <= b && b <= w) {
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
} // End of Code
