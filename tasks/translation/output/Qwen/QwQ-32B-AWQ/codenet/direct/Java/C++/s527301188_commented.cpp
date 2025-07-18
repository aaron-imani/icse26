#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::vector<std::string> strs;
    std::string token;
    while (iss >> token) {
        strs.push_back(token);
    }

    int size = strs.size();
    std::vector<int> nums(size);
    int top = 0;

    for (const auto& s : strs) {
        char firstChar = s[0];
        switch (firstChar) {
            case '+':
                top--;
                nums[top-1] = nums[top-1] + nums[top];
                break;
            case '-':
                top--;
                nums[top-1] = nums[top-1] - nums[top];
                break;
            case '*':
                top--;
                nums[top-1] = nums[top-1] * nums[top];
                break;
            default:
                nums[top] = std::stoi(s);
                top++;
                break;
        }
    }

    std::cout << nums[0] << std::endl;

    return 0;
} // End of Code
