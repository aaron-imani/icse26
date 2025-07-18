#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> nums(100); // Initialize with a fixed size to avoid out-of-bounds errors
    int top = 0;

    std::string token;
    while (iss >> token) {
        if (token[0] == '+') {
            top--;
            nums[top-1] = nums[top - 1] + nums[top];
        } else if (token[0] == '-') {
            top--;
            nums[top-1] = nums[top - 1] - nums[top];
        } else if (token[0] == '*') {
            top--;
            nums[top-1] = nums[top - 1] * nums[top];
        } else {
            nums[top] = std::stoi(token);
            top++;
        }
    }
    std::cout << nums[0] << std::endl;
} // End of Code
