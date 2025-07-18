#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    int a, b;
    ss >> a >> b;
    if (b % a == 0) {
        std::cout << a + b << std::endl;
    } else {
        std::cout << b - a << std::endl;
    }
    return 0;
}
// End of Code
