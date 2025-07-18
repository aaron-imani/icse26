#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    
    size_t space_pos = line.find(' ');
    int N = std::stoi(line.substr(0, space_pos));
    int M = std::stoi(line.substr(space_pos + 1));
    
    std::vector<int> shortage(M);
    
    for (int i = 0; i < M; i++) {
        std::getline(std::cin, line);
        space_pos = line.find(' ');
        int A = std::stoi(line.substr(0, space_pos));
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
