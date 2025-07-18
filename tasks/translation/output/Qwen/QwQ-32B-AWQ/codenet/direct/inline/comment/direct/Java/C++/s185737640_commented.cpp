#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s) {
    size_t mid = s.length() / 2;
    string a = s.substr(0, mid);
    string b = s.substr(mid);
    return a == b;
}

int main() {
    string S;
    getline(cin, S);

    if (S.length() % 2 == 1) {
        S = S.substr(0, S.length() - 1);
    } else {
        S = S.substr(0, S.length() - 2);
    }

    while (true) {
        if (S.empty()) break;
        if (isEvenString(S)) break;
        S = S.substr(0, S.length() - 2);
    }

    cout << S.length() << endl;
    return 0;
}
// End of Code
