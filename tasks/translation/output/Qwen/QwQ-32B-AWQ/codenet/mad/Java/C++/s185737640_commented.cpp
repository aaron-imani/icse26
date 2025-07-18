#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s) {
    int len = s.length();
    string a = s.substr(0, len/2);
    string b = s.substr(len/2, len/2);
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

    for (; S.length() > 0; S = S.substr(0, S.length()-2)) {
        if (isEvenString(S)) {
            break;
        }
    }
    cout << S.length() << endl;
    return 0;
}
// End of Code
