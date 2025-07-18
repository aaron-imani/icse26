#include <iostream>
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
        int min[10];
        for (int i = 0; i < 10; ++i) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; ++tc) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (min[i] > c[i][j] + min[j]) {
                        min[i] = c[i][j] + min[j];
                    }
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; ++h) {
            for (int w = 1; w <= W; ++w) {
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

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
