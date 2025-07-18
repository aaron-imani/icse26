#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mapNum;
int h, w;
int bomberActNum;
int xOfTank, yOfTank;
int xOfBomber, yOfBomber;
int s, k, a, b;
int x, y;
vector<vector<char>> battleTown;

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
                }
            }
        }
    }
}

int main() {
    cin >> mapNum;
    for (int i = 0; i < mapNum; i++) {
        if (i > 0) {
            cout << endl;
        }
        cin >> h >> w;
        battleTown = vector<vector<char>>(h, vector<char>(w));
        x = -1;
        y = -1;
        for (int j = 0; j < h; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = s[k];
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || 
                    battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }
        cin >> bomberActNum;
        string act;
        cin >> act;
        for (int l = 0; l < bomberActNum; l++) {
            char c = act[l];
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
                a = x;
                b = y;
                moveBomber(a, b);
            }
        }
        for (s = 0; s < h; s++) {
            for (k = 0; k < w; k++) {
                cout << battleTown[s][k];
            }
            cout << endl;
        }
    }
    return 0;
}
// End of Code
