#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
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
