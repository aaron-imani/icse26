#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mapNum;
int h, w;
vector<vector<char>> battleTown;
int bomberActNum;
vector<char> bomberAct;
int xOfTank, yOfTank, xOfBomber, yOfBomber, s, k, a, b, x, y;
int tank[2]; 

void moveBomber(int a, int b) {
    if (0 <= a && a <= h && 0 <= b && b <= w) {
        char dir = battleTown[a][b];
        if (dir == '^') {
            for (int i = a - 1; i >= 0; i--) {
                if (a <= 0) return;
                if (battleTown[a-1][b] == '*') {
                    battleTown[a-1][b] = '.';
                    return;
                } else if (battleTown[a-1][b] == '#') {
                    return;
                } else {
                    a--;
                    if (a == 0) return;
                }
            }
        } else if (dir == 'v') {
            for (int i = a + 1; i < h; i++) {
                if (battleTown[a+1][b] == '*') {
                    battleTown[a+1][b] = '.';
                    return;
                } else if (battleTown[a+1][b] == '#') {
                    return;
                } else {
                    a++;
                    if (a == h) return;
                }
            }
        } else if (dir == '<') {
            for (int i = b - 1; i >= 0; i--) {
                if (battleTown[a][b-1] == '*') {
                    battleTown[a][b-1] = '.';
                    return;
                } else if (battleTown[a][b-1] == '#') {
                    return;
                } else {
                    b--;
                    if (b == 0) return;
                }
            }
        } else if (dir == '>') {
            for (int i = b + 1; i < w; i++) {
                if (battleTown[a][b+1] == '*') {
                    battleTown[a][b+1] = '.';
                    return;
                } else if (battleTown[a][b+1] == '#') {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> mapNum;

    for (int i = 0; i < mapNum; ++i) {
        if (1 <= i && i < mapNum) {
            cout << endl;
        }

        cin >> h >> w;
        battleTown = vector<vector<char>>(h, vector<char>(w));

        for (int j = 0; j < h; ++j) {
            string line;
            cin >> line;

            for (int k = 0; k < w; ++k) {
                battleTown[j][k] = line[k];

                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || 
                    battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        cin >> bomberActNum;
        string actStr;
        cin >> actStr;
        bomberAct = vector<char>(actStr.begin(), actStr.end());

        if (0 <= x && x <= h && 0 <= y && y <= w) {
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
                    a = x;
                    b = y;
                    moveBomber(a, b);
                }
            }

            for (s = 0; s < h; ++s) {
                for (k = 0; k < w; ++k) {
                    cout << battleTown[s][k];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// End of Code
