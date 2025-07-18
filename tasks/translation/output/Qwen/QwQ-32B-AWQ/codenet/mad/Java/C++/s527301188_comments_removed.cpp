#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream iss(line);
    vector<string> strs{istream_iterator<string>(iss), istream_iterator<string>()};
    
    vector<int> nums(strs.size());
    int top = 0;
    
    for (const auto& str : strs) {
        char op = str[0];
        switch(op) {
            case '+':
                top--;
                nums[top-1] += nums[top];
                break;
            case '-':
                top--;
                nums[top-1] -= nums[top];
                break;
            case '*':
                top--;
                nums[top-1] *= nums[top];
                break;
            default:
                nums[top] = stoi(str);
                top++;
                break;
        }
    }
    cout << nums[0] << endl;
    return 0;
}
// End of Code
