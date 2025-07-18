#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    int top = 0;

    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            int a = nums[top - 2];
            int b = nums[top - 1];
            if (token == "+") {
                nums[top - 2] = a + b;
            } else if (token == "-") {
                nums[top - 2] = a - b;
            } else if (token == "*") {
                nums[top - 2] = a * b;
            }
            top -= 1;
        } else {
            nums.push_back(std::stoi(token));
            top++;
        }
    }
    std::cout << nums[0] << std::endl;
    // End of Code
