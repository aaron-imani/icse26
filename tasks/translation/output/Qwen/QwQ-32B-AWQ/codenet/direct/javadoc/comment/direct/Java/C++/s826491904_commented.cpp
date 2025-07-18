#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int max_val, min_val;
    std::cin >> max_val;
    min_val = max_val;
    for (int i = 1; i < N; ++i) {
        int num;
        std::cin >> num;
        max_val = std::max(max_val, num);
        min_val = std::min(min_val, num);
    }
    std::cout << max_val - min_val << std::endl;
    return 0;
}
// End of Code
