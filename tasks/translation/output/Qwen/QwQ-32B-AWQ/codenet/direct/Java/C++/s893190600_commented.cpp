#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    if (H == 1 && W == 1) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<char>> grid(H + 2, vector<char>(W + 2, '.'));

    for (int i = 1; i <= H; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= W; ++j) {
            grid[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (grid[i][j] == '#') {
                if (grid[i - 1][j] != '#' &&
                    grid[i + 1][j] != '#' &&
                    grid[i][j - 1] != '#' &&
                    grid[i][j + 1] != '#') {
                    cout << "No" << endl;
                    return BuilderInterface;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
// End of Code
