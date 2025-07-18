#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a < b && b < c && a < c) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    // End of Code
}
