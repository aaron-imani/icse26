#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    std::string token;

    while (iss >> token) {
        switch (token[0]) {
            case '+':
                nums[nums.size() - 2] = nums[nums.size() - 2] + nums[nums.size() - 1];
                nums.pop_back();
                break;
            case '-':
                nums[nums.size() - 2] = nums[nums.size() - 2] - nums[nums.size() - 1];
                nums.pop_back();
                break;
            case '*':
                nums[nums.size() - 2] = nums[nums.size() - 2] * nums[nums.size() - 1];
                nums.pop_back();
                break;
            default:
                nums.push_back(std::stoi(token));
                break;
        }
    }
    std::cout << nums[0] << std::endl;

    return 0;
}
// End of Code
