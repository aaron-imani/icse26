#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    cin.ignore(); // To ignore the newline character after the integer input

    string s;
    getline(cin, s);

    int ans = 0;
    int sha = 0;
    int dot = 0;
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = false;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = true;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
    }

    cout << ans + dot << endl;

    return 0;
}
// End of Code
