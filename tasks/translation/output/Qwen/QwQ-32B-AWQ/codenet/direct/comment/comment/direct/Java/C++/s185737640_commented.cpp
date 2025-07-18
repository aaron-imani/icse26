#include <iostream>
#include <string>

using namespace std;

bool isEvenString(const string& s) {
    size_t len = s.length();
    if (len % 2 != 0) return false;
    size_t half = len / 2;
    string a = s.substr(0, half);
    string b = s.substr(half);
    return a == b;
}

int main() {
    string S;
    getline(cin, S);

    size_t len = S.length();
    if (len % 2 == 1) {
        S = S.substr(0, len - 1);
    } else {
        S = S.substr(0, len - 2);
    }

    for( ; !S.empty(); ) {
        if (isEvenString(S)) {
            break;
        }
        S = S.substr(0, S.length() - 2);
    }

    cout << S.length() << endl;
    return 0;
}
// End of Code
