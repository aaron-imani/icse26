#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

class Main {
public:
    void solve() {
        std::cin >> H >> W;
        c.resize(10, std::vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cin >> c[i][j];
            }
        }
        min.resize(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = std::min(min[i], c[i][j] + min[j]);
                }
            }
        }
        ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A;
                std::cin >> A;
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        std::cout << ans << std::endl;
    }

private:
    int H, W, ans;
    std::vector<std::vector<int>> c;
    std::vector<int> min;
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
