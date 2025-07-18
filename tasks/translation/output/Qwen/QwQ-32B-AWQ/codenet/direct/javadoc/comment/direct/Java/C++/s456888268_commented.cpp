#include <iostream>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();
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
    std::cout << (n - 2 * ans) << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
// End of Code
