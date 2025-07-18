#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    int N = tokens.size();
    vector<int> nums(N);
    int top = 0;
    
    for (const string& s : tokens) {
        char c = s[0];
        if (c == '+' || c == '-' || c == '*') {
            top--;
            int a = nums[top];
            int b = nums[top-1];
            switch(c) {
                case '+':
                    nums[top-1] = b + a;
                    break;
                case '-':
                    nums[top-1] = b - a;
                    break;
                case '*':
                    nums[top-1] = b * a;
                    break;
            }
        } else {
            nums[top] = stoi(s);
            top++;
        }
    }
    cout << nums[0] << endl;
    return 0;
} // End of Code
