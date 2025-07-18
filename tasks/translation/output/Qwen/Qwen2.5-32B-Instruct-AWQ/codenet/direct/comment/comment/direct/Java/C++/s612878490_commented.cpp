#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string line;
    std::getline(std::cin, line);
    
    size_t spacePos = line.find(' ');
    int N = std::stoi(line.substr(0, spacePos));
    int M = std::stoi(line.substr(spacePos + 1));
    
    std::vector<int> shortage(M);
    
    for (int i = 0; i < M; ++i) {
        std::getline(std::cin, line);
        spacePos = line.find(' ');
        int A = std::stoi(line.substr(0, spacePos));
        shortage[i] = N > A ? N - A : 0;
    }
    
    std::sort(shortage.begin(), shortage.end());
    
    int ans = 0;
    
    for (int i = 0; i < M - 1; ++i) {
        ans += shortage[i];
    }
    
    std::cout << ans << std::endl;
    
    return 0; // End of Code
}
