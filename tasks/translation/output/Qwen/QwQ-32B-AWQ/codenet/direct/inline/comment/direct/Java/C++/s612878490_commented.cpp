#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> shortage(M);

    for (int i = 0; i < M; ++i) {
        int A;
        std::cin >> A;
        shortage[i] = std::max(0, N - A);
    }

    std::sort(shortage.begin(), shortage.end());

    int ans = 0;
    for (int i = 0; i < M - 1; ++i) {
        ans += shortage[i];
    }

    std::cout << ans << '\n';
    return 0;
}
// End of Code
