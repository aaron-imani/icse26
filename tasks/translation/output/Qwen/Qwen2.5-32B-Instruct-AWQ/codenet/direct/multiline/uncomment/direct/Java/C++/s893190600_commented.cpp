#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;

class Solver {
public:
    Solver() {}

    void solve() {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));

        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                cin >> C[i][j];
            }
        }

        if (H == 1 && W == 1) {
            cout << "No" << endl;
            return;
        }

        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    cout << "No" << endl;
                    return;
                }
            }
        }

        cout << "Yes" << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver solver;
    solver.solve();

    return 0;
}

// End of Code
