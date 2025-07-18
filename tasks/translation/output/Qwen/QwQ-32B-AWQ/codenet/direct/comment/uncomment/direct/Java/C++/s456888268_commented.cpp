#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, cnt = 0;
    for (char c : s) {
        if (c == 'S') {
            cnt++;
        } else {
            if (cnt > 0) {
                ans++;
                cnt--;
            }
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
// End of Code
