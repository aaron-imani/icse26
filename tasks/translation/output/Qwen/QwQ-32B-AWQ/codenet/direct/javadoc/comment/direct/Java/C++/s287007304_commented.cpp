#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int a, b;
    iss >> a >> b;
    if (b % a == 0) {
        cout << a + b << endl;
    } else {
        cout << b - a << endl;
    }
    return 0;
} // End of Code
