#include <iostream>
#include <vector>

int main() {
    std::cin >> std::ws;
    int count;
    std::cin >> count;
    std::vector<int> givingNumbers(count);

    // Read Numbers
    for (int i = 0; i < count; ++i) {
        std::cin >> givingNumbers[i];
    }

    // Reversing Numbers
    for (int i = count - 1; i >= 0; --i) {
        std::cout << givingNumbers[i];

        if (i > 0) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
// End of Code
