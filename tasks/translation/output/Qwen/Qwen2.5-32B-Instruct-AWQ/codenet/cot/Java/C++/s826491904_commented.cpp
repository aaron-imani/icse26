#include <iostream>
#include <algorithm>

class Main {
public:
    void solve() {
        int N;
        std::cin >> N;
        int max, min;
        max = min = std::cin.get();
        for (int i = 1; i < N; i++) {
            int in;
            std::cin >> in;
            max = std::max(max, in);
            min = std::min(min, in);
        }
        std::cout << max - min << std::endl;
    }
};

int main() {
    Main().solve();
    // End of Code
}
