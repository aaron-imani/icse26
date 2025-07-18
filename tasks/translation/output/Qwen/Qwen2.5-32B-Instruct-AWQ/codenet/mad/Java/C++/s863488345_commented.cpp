#include <iostream>
#include <vector>
#include <string>

int mapNum; // Buttle Town図の数
int h; // 地図の大きさの縦
int w; // 地図の大きさの横
std::vector<std::vector<char>> battleTown; // Buttle Town地図取込用
int bomberActNum; // 指示された戦車の行動数
std::vector<char> bomberAct; // 指示された戦車の行動
int xOfTank;
int yOfTank;
int xOfBomber;
int yOfBomber;    
int s; // 表示用
int k; // 表示用
int a; // x Of Bomber
int b; // y Of Bomber
int x; // tankの位置x
int y; // tankの位置y

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
        }
        if (battleTown[a][b] == 'v') {
            for (int i = a + 1; i < h; i++) {
                if (battleTown[i][b] == '*') {
                    battleTown[i][b] = '.';
                    return;
                } else if (battleTown[i][b] == '#') {
                    return;
                }
            }
        }
        if (battleTown[a][b] == '<') {
            for (int i = b - 1; i >= 0; i--) {
                if (battleTown[a][i] == '*') {
                    battleTown[a][i] = '.';
                    return;
                } else if (battleTown[a][i] == '#') {
                    return;
                }
            }
        }
        if (battleTown[a][b] == '>') {
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
    std::cin >> mapNum;

    for (int i = 0; i < mapNum; i++) {
        if (i > 0) {
            std::cout << std::endl;
        }
        std::cin >> h >> w;
        battleTown.resize(h, std::vector<char>(w));

        for (int j = 0; j < h; j++) {
            std::string line;
            std::cin >> line;
            for (int k = 0; k < w; k++) {
                battleTown[j][k] = line[k];
                if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                    x = j;
                    y = k;
                }
            }
        }

        std::cin >> bomberActNum;
        std::string actions;
        std::cin >> actions;
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
                    std::cout << battleTown[s][k];
                }
                std::cout << std::endl;
            }
        }
    }
}
// End of Code
