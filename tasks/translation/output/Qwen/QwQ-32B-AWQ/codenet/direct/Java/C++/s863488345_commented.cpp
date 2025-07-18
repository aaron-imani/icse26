#include <iostream>
#include <vector>
#include <string>
using namespace std;

void moveBomber(vector<vector<char>>& battleTown, int a, int b) {
    char direction = battleTown[a][b];
    if (direction == '^') {
        int current_row = a - 1;
        while (current_row >= 0) {
            char cell = battleTown[current_row][b];
            if (cell == '*') {
                battleTown[current_row][b] = '.';
                return;
            } else if (cell == '#') {
                return;
            } else {
                current_row--;
            }
        }
    } else if (direction == 'v') {
        int current_row = a + 1;
        while (current_row < battleTown.size()) {
            char cell = battleTown[current_row][b];
            if (cell == '*') {
                battleTown[current_row][b] = '.';
                return;
            } else if (cell == '#') {
                return;
            } else {
                current_row++;
            }
        }
    } else if (direction == '<') {
        int current_col = b - 1;
        while (current_col >= 0) {
            char cell = battleTown[a][current_col];
            if (cell == '*') {
                battleTown[a][current_col] = '.';
                return;
            } else if (cell == '#') {
                return;
            } else {
                current_col--;
            }
        }
    } else if (direction == '>') {
        int current_col = b + 1;
        while (current_col < battleTown[0].size()) {
            char cell = battleTown[a][current_col];
            if (cell == '*') {
                battleTown[a][current_col] = '.';
                return;
            } else if (cell == '#') {
                return;
            } else {
                current_col++;
            }
        }
    }
}

int main() {
    int mapNum;
    cin >> mapNum;

    for (int i = 0; i < mapNum; i++) {
        if (i > 0) {
            cout << endl;
        }

        int h, w;
        cin >> h >> w;

        vector<vector<char>> battleTown(h, vector<char>(w));
        int x = -1, y = -1;

        for (int j = 0; j < h; j++) {
            string line;
            cin >> line;
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = line[k];
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' ||
                    battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        int bomberActNum;
        cin >> bomberActNum;
        string bomberActStr;
        cin >> bomberActStr;
        vector<char> bomberAct(bomberActStr.begin(), bomberActStr.end());

        for (int l = 0; l < bomberActNum; l++) {
            char action = bomberAct[l];
            if (action == 'U') {
                battleTown[x][y] = '^';
                if (x > 0 && battleTown[x - 1][y] == '.') {
                    battleTown[x][y] = '.';
                    x--;
                    battleTown[x][y] = '^';
                }
            } else if (action == 'D') {
                battleTown[x][y] = 'v';
                if (x + 1 < h && battleTown[x + 1][y] == '.') {
                    battleTown[x][y] = '.';
                    x++;
                    battleTown[x][y] = 'v';
                }
            } else if (action == 'L') {
                battleTown[x][y] = '<';
                if (y > 0 && battleTown[x][y - 1] == '.') {
                    battleTown[x][y] = '.';
                    y--;
                    battleTown[x][y] = '<';
                }
            } else if (action == 'R') {
                battleTown[x][y] = '>';
                if (y + 1 < w && battleTown[x][y + 1] == '.') {
                    battleTown[x][y] = '.';
                    y++;
                    battleTown[x][y] = '>';
                }
            } else if (action == 'S') {
                moveBomber(battleTown, x, y);
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
} // End of Code
