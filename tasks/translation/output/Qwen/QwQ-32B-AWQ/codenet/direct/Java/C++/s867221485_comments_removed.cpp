#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string s;
    getline(cin, s);

    bool first = true;
    int ans = 0;
    int sha = 0, dot = 0;

    for (int i = 0; i < N; i++) {
        char c = s[i];
        if (c == '#') {
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
        dot = 0;
    }

    cout << ans + dot << endl;
    return 0;
} // End of Code
