#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a % 2 == 0 || b % 2 == 0)
        std::cout << "No";
    else
        std::cout << "Yes";
    return 0;
}
// End of Code
