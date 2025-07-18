#include <iostream>
#include <string>
#include <sstream>

std::string readLine() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main() {
    std::string input = readLine();
    std::istringstream iss(input);
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
