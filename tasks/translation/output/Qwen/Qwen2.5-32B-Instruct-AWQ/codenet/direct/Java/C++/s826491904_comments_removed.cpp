#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    int max, min;
    max = min = std::cin.get();
    
    for (int i = 1; i < N; i++) {
        int in;
        std::cin >> in;
        max = std::max(max, in);
        min = std::min(min, in);
    }
    std::cout << max - min << std::endl;
}

// End of Code
