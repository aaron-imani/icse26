#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    while (iss >> input) {
        if (input == "+" || input == "-" || input == "*") {
            int b = nums.back();
            nums.pop_back();
            int a = nums.back();
            nums.pop_back();
            if (input == "+") {
                nums.push_back(a + b);
            } else if (input == "-") {
                nums.push_back(a - b);
            } else if (input == "*") {
                nums.push_back(a * b);
            }
        } else {
            nums.push_back(std::stoi(input));
        }
    }
    std::cout << nums.front() << std::endl;
} // End of Code
