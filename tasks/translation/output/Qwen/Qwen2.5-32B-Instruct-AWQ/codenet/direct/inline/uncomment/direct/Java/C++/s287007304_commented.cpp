#include <iostream>
#include <sstream>

std::string readLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
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
