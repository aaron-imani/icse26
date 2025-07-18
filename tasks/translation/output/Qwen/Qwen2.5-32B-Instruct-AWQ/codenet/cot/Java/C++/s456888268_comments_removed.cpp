#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    string tmp;
    cin >> tmp;
    char s[tmp.size()];
    for (int i = 0; i < tmp.size(); i++) {
        s[i] = tmp[i];
    }
    int n = tmp.size();
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'S') {
            cnt++;
        } else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << n - 2 * ans << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
