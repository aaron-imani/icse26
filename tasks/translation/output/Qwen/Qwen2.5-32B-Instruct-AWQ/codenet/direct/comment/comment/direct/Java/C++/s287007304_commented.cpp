#include <iostream>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int a, b;
    iss >> a >> b;

    if (b % a == 0) {
        std::cout << a + b << std::endl;
    } else {
        std::cout << b - a << std::endl;
    }
    return 0;
}
// End of Code
