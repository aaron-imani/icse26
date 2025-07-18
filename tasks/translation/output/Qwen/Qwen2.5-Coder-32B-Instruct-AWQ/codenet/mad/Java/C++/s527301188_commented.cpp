#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums(1000); // Pre-allocate a large enough vector
    std::string token;
    int top = 0;

    while (iss >> token) {
        switch (token[0]) {
            case '+':
                top--;
                nums[top - 1] = nums[top - 1] + nums[top];
                break;
            case '-':
                top--;
                nums[top - 1] = nums[top - 1] - nums[top];
                break;
            case '*':
                top--;
                nums[top - 1] = nums[top - 1] * nums[top];
                break;
            default:
                nums[top] = std::stoi(token);
                top++;
                break;
        }
    }
    std::cout << nums[0] << std::endl;

    return 0;
}
// End of Code
