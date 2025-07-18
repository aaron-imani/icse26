#include <iostream>

bool read(int &d) {
    if (!(std::cin >> d)) return false;
    return true;
}

int solve(int d) {
    int ans = 0;
    for (int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    int d;
    while (read(d)) {
        std::cout << solve(d) << std::endl;
    }
    return 0;
}
// End of Code
