#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            int b = nums.back();
            nums.pop_back();
            int a = nums.back();
            nums.pop_back();

            if (token == "+") {
                nums.push_back(a + b);
            } else if (token == "-") {
                nums.push_back(a - b);
            } else if (token == "*") {
                nums.push_back(a * b);
            }
        } else {
            nums.push_back(std::stoi(token));
        }
    }

    std::cout << nums.front() << std::endl;
} // End of Code
