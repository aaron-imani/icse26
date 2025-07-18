#include <iostream>
#include <algorithm>

class Main {
public:
    void solve() {
        int N;
        std::cin >> N;
        int max, min;
        std::cin >> min; // Correctly read the first integer
        max = min;

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
    return 0; // Return 0 to indicate successful execution
    // End of Code
}
