#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

class Main {
public:
    void solve() {
        int H, W;
        cin >> H >> W;
        vector<vector<int>> c(10, vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> c[i][j];
            }
        }
        vector<int> min(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = min(min[i], c[i][j] + min[j]);
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A;
                cin >> A;
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        cout << ans << endl;
    }
};

// End of Code
