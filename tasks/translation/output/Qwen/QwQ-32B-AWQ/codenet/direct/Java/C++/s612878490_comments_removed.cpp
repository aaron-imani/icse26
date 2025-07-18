#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> shortage;
    for (int i = 0; i < M; ++i) {
        int A;
        std::cin >> A;
        shortage.push_back(std::max(N - A, 0));
    }

    std::sort(shortage.begin(), shortage.end());

    int ans = 0;
    for (int i = 0; i < M - 1; ++i) {
        ans += shortage[i];
    }

    std::cout << ans << std::endl;
    return 0;
}
// End of Code
