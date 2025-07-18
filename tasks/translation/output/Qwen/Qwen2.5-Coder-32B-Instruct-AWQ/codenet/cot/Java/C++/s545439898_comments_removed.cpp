#include <iostream>
#include <vector>

int main() {
    std::vector<int> givingNumbers;
    int count;
    std::cin >> count;
    givingNumbers.resize(count);

    for(int i = 0; i < count; i++) {
        std::cin >> givingNumbers[i];
    }

    for(int i = count - 1; i >= 0; i--) {
        std::cout << givingNumbers[i];
        if(i > 0) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
// End of Code
