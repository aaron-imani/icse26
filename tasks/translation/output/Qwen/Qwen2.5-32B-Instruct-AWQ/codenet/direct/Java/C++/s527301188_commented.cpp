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
        if (token[0] == '+') {
            top--;
            nums[top - 1] = nums[top - 1] + nums[top];
        } else if (token[0] == '-') {
            top--;
            nums[top - 1] = nums[top - 1] - nums[top];
        } else if (token[0] == '*') {
            top--;
            nums[top - 1] = nums[top - 1] * nums[top];
        } else {
            nums.push_back(std::stoi(token));
            top++;
        }
    }
    std::cout << nums[0] << std::endl;
} // End of Code
