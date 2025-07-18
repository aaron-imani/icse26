#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    int N, M;
    N = std::stoi(line.substr(0, line.find(' ')));
    M = std::stoi(line.substr(line.find(' ') + 1));

    std::vector<int> shortage(M);

    for (int i = 0; i < M; i++) {
        std::getline(std::cin, line);
        int A = std::stoi(line.substr(0, line.find(' ')));
        shortage[i] = N > A ? N - A : 0;
    }

    std::sort(shortage.begin(), shortage.end());

    int ans = 0;

    for (int i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    std::cout << ans << std::endl;

    // End of Code
}
