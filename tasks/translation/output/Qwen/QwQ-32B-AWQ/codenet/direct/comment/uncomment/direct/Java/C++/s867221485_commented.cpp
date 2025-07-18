#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin.ignore();
    getline(cin, s);

    bool flag = false;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    bool first = true;

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
            else {
                // temp += dot;
            }
            sha++;
        }
        else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    }
    else {
        // temp += dot;
    }

    cout << ans + dot << endl;
    return 0;
}
// End of Code
