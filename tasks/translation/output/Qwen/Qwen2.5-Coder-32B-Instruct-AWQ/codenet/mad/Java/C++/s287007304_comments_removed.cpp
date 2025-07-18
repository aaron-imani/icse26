#include <iostream>
#include <sstream>
#include <string>

std::string readLine() {
    std::string line;
    if (std::getline(std::cin, line)) {
        return line;
    } else {
        return "Error reading line";
    }
}

int main() {
    std::string input = readLine();
    std::istringstream iss(input);
    int a, b;
    
    if (!(iss >> a >> b)) {
        std::cerr << "Error parsing integers" << std::endl;
        return 1;
    }

    if (b % a == 0) {
        std::cout << a + b << std::endl;
    } else {
        std::cout << b - a << std::endl;
    }

    return 0;
}
// End of Code
