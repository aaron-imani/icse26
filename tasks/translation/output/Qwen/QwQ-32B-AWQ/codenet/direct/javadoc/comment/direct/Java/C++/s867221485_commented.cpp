#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    cin.ignore();
    getline(cin, s);

    int ans = 0, sha = 0, dot = 0;
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
        dot = 0;
    }

    cout << ans + dot << endl;
}
// End of Code
