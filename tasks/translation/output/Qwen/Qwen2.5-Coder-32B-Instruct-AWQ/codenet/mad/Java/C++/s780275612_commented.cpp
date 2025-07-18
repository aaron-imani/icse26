#include <iostream>
#include <cmath>

int main() {
    // Read an integer from standard input
    int intA;
    std::cin >> intA;

    // Calculate the cube of the integer
    double dbAncer = std::pow(intA, 3);
    int intAncer = static_cast<int>(dbAncer);
    std::cout << intAncer << std::endl;

    return 0;
}
// End of Code
