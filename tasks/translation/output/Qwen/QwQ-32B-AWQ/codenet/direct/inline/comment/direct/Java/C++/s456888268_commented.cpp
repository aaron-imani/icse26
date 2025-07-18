#include <iostream>
#include <string>

using namespace std;

void solve(const string& s) {
    int n = s.size();
    int ans = 0, cnt = 0;
    for (char c : s) {
        if (c == 'S') {
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
    string tmp;
    cin >> tmp;
    solve(tmp);
    return 0;
}
// End of Code
