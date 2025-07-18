#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    vector<string> strs;
    istringstream iss(line);
    string token;
    while (iss >> token) {
        strs.push_back(token);
    }
    vector<int> nums(strs.size());
    int top = 0;
    for (int i = 0; i < strs.size(); i++) {
        const string& s = strs[i];
        char c = s[0];
        switch (c) {
            case '+':
                top--;
                nums[top - 1] += nums[top];
                break;
            case '-':
                top--;
                nums[top - 1] -= nums[top];
                break;
            case '*':
                top--;
                nums[top - 1] *= nums[top];
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
