#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<std::string> strs;
    std::string temp;
    
    while (iss >> temp) {
        strs.push_back(temp);
    }
    
    std::vector<int> nums(strs.size());
    int top = 0;
    
    for (int i = 0; i < strs.size(); i++) {
        switch (strs[i][0]) {
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
                nums[top] = std::stoi(strs[i]);
                top++;
                break;
        }
    }
    
    std::cout << nums[0] << std::endl;
    
    return 0;
}
// End of Code
