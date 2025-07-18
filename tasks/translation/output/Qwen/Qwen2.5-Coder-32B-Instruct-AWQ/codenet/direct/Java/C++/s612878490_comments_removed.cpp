#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    int N, M;
    std::istringstream iss(line);
    iss >> N >> M;

    std::vector<int> shortage(M);

    for (int i = 0; i < M; i++) {
        std::getline(std::cin, line);
        int A;
        std::istringstream iss(line);
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
