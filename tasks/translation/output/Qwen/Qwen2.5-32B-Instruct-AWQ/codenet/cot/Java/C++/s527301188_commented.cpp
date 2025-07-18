#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    int top = 0;

    std::string token;
    while (iss >> token) {
        if (token[0] == '+' || token[0] == '-' || token[0] == '*') {
            int result = 0;
            if (token[0] == '+') {
                result = nums[top - 2] + nums[top - 1];
            } else if (token[0] == '-') {
                result = nums[top - 2] - nums[top - 1];
            } else if (token[0] == '*') {
                result = nums[top - 2] * nums[top - 1];
            }
            nums[top - 2] = result;
            nums.pop_back();
            top--;
        } else {
            nums.push_back(std::stoi(token));
            top++;
        }
    }
    std::cout << nums[0] << std::endl; // End of Code
