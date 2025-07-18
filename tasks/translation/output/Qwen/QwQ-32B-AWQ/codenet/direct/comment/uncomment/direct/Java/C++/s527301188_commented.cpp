#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    vector<string> strs;
    stringstream ss(line);
    string token;
    while (ss >> token) {
        strs.push_back(token);
    }
    
    vector<int> nums(strs.size());
    int top = 0;
    for (const auto& s : strs) {
        char c = s[0];
        switch(c) {
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
                nums[top] = stoi(s);
                top++;
                break;
        }
    }
    cout << nums[0] << endl;
    return 0;
}
// End of Code
