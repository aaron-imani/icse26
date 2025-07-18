#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int a, b;
    if (ss >> a >> b) { // Ensure both values are read successfully
        if (b % a == 0) {
            std::cout << a + b << std::endl;
        } else {
            std::cout << b - a << std::endl;
        }
    }
    return 0;
}
// End of Code
