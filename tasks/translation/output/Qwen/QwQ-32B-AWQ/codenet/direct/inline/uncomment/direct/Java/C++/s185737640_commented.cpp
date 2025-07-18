#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s);

int main() {
    string S;
    getline(cin, S);

    if (S.size() % 2 == 1) {
        S = S.substr(0, S.size() - 1);
    } else {
        S = S.substr(0, S.size() - 2);
    }

    for (; S.size() > 0; S = S.substr(0, S.size() - 2)) {
        if (isEvenString(S)) {
            break;
        }
    }
    cout << S.size() << endl;
    return 0;
}

bool isEvenString(const string& s) {
    size_t half = s.size() / 2;
    string a = s.substr(0, half);
    string b = s.substr(half);
    return a == b;
}
// End of Code
