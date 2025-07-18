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

    if (S.length() % 2 != 0) {
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
}
// End of Code
