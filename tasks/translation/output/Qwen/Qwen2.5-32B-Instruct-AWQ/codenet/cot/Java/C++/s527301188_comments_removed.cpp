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
        switch (token[0]) {
            case '+':
                top--;
                nums[top-1] = nums[top - 1] + nums[top];
                break;
            case '-':
                top--;
                nums[top-1] = nums[top - 1] - nums[top];
                break;
            case '*':
                top--;
                nums[top-1] = nums[top - 1] * nums[top];
                break;
            default:
                nums.push_back(std::stoi(token));
                top++;
                break;
        }
    }
    std::cout << nums[0] << std::endl; // End of Code
