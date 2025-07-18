#include <iostream>
#include <string>
#include <map>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> condition;
    for (int i = 0; i < m; ++i) {
        int s, c;
        cin >> s >> c;
        if (condition.find(s) != condition.end()) {
            if (condition[s] != c) {
                cout << -1 << endl;
                return;
            }
        }
        condition[s] = c;
    }

    for (int i = 0; i < 1000; ++i) {
        string s = to_string(i);
        if (s.length() != n) continue;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            int pos = j + 1;
            int digit = s[j] - '0';
            if (condition.count(pos)) {
                if (digit != condition[pos]) {
                    flag = false;
                    break;
                }
            } else {
                if (j == 0) {
                    if (digit != 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if (digit != 0) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            cout << s << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
// End of Code
