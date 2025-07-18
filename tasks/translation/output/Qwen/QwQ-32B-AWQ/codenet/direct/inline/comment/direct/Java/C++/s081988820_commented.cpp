#include <iostream>
#include <algorithm>
using namespace std;

class Main {
public:
    void solve() {
        int H, W;
        cin >> H >> W;
        int c[10][10];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> c[i][j];
            }
        }
        int min_cost[10];
        for (int i = 0; i < 10; ++i) {
            min_cost[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; ++tc) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j]);
                }
            }
        }
        int ans = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                int A;
                cin >> A;
                if (A >= 0) {
                    ans += min_cost[A];
                }
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
