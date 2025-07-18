#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s) {
    int n = s.length();
    string a = s.substr(0, n/2);
    string b = s.substr(n/2);
    return a == b;
}

int main() {
    string S;
    getline(cin, S);

    if (S.length() % 2 == 1) {
        S = S.substr(0, S.length()-1);
    } else {
        S = S.substr(0, S.length()-2);
    }

    while (S.length() > 0) {
        if (isEvenString(S)) {
            break;
        }
        S = S.substr(0, S.length()-2);
    }

    cout << S.length() << endl;
}
// End of Code
