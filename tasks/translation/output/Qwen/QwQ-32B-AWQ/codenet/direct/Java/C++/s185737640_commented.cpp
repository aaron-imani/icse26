#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s) {
    return s.substr(0, s.size()/2) == s.substr(s.size()/2);
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
    return 0;
} // End of Code
