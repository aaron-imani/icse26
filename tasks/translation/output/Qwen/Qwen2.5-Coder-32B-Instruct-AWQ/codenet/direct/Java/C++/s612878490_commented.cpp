#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int N, M;
    iss >> N >> M;

    std::vector<int> shortage(M);

    for (int i = 0; i < M; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int A;
        iss >> A;
        shortage[i] = N > A ? N - A : 0;
    }

    std::sort(shortage.begin(), shortage.end());

    int ans = 0;

    for (int i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    std::cout << ans << std::endl;

    return 0;
}
// End of Code
