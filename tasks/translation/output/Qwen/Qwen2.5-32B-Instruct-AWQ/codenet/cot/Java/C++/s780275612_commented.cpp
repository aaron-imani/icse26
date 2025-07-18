#include <iostream>
#include <cmath>

int main() {
    // Input reading
    int intA;
    std::cin >> intA;

    // Calculation
    double dbAncer = pow(intA, 3);
    int intAncer = static_cast<int>(dbAncer);

    // Output
    std::cout << intAncer << std::endl;
    // End of Code
