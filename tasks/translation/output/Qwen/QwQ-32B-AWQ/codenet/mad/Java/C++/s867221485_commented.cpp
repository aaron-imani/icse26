#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string s;
    getline(cin, s);

    int ans = 0;
    int sha = 0;
    int dot = 0;

    for (char c : s) {
        if (c == '#') {
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    }

    cout << ans + dot << endl;
    return 0;
}
// End of Code
