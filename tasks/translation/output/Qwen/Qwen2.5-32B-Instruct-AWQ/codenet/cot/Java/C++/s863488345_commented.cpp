#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Main {
public:
    static int mapNum; // Buttle Town図の数
    static int h; // 地図の大きさの縦
    static int w; // 地図の大きさの横
    static vector<vector<char>> battleTown; // Buttle Town地図取込用
    static int bomberActNum; // 指示された戦車の行動数
    static vector<char> bomberAct; // 指示された戦車の行動
    static int tank[2];
    static int xOfTank;
    static int yOfTank;
    static int xOfBomber;
    static int yOfBomber;
    static int s; // 表示用
    static int k; // 表示用
    static int a; // x Of Bomber
    static int b; // y Of Bomber
    static int x; // tankの位置x
    static int y; // tankの位置y

    static void main() {
        cin >> mapNum;

        for (int i = 0; i < mapNum; i++) {
            if (1 <= i && i < mapNum) {
                cout << endl;
            }
            cin >> h >> w;

            battleTown.resize(h, vector<char>(w));

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
            string act;
            cin >> act;
            bomberAct.resize(bomberActNum);
            for (int i = 0; i < bomberActNum; i++) {
                bomberAct[i] = act[i];
            }

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

    static void moveBomber(int a, int b) {
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
    }
};

int Main::mapNum;
int Main::h;
int Main::w;
vector<vector<char>> Main::battleTown;
int Main::bomberActNum;
vector<char> Main::bomberAct;
int Main::tank[2];
int Main::xOfTank;
int Main::yOfTank;
int Main::xOfBomber;
int Main::yOfBomber;
int Main::s;
int Main::k;
int Main::a;
int Main::b;
int Main::x;
int Main::y;

int main() {
    Main::main();
    return 0;
} // End of Code
