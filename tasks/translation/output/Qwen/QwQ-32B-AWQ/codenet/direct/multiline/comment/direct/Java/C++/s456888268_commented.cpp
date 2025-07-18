#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
// End of Code
