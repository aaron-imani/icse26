#include <iostream>
#include <string>
using namespace std;

bool isEvenString(const string& s) {
    size_t mid = s.size() / 2;
    string a = s.substr(0, mid);
    string b = s.substr(mid, mid);
    return a == b;
}

int main() {
    string S;
    getline(cin, S);

    if (S.size() % 2 != 0) {
        S = S.substr(0, S.size() - 1);
    } else {
        S = S.substr(0, S.size() - 2);
    }

    while (S.size() > 0) {
        if (isEvenString(S)) {
            break;
        }
        S = S.substr(0, S.size() - 2);
    }
    cout << S.size() << endl;
}
// End of Code
