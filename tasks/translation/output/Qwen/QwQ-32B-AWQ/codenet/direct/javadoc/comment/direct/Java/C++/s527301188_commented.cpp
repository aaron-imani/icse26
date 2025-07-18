#include <iostream>
#include <vector>
#include <string>
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
    
    int n = strs.size();
    vector<int> nums(n);
    int top = 0;
    
    for (const string& s : strs) {
        char op = s[0];
        switch(op) {
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
                nums[top] = stoi(s);
                top++;
                break;
        }
    }
    cout << nums[0] << endl;
    return 0;
}
// End of Code
