#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> a(2);
vector<vector<vector<int>>> memo;

int dp(int flipped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[flipped][idx][msk] != -1) return memo[flipped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 瞠;
    int ans = 1000000000;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int current_flipped = (nf + (ff % 2)) % 2;
            if (idx == n || a[flipped][idx] <= a[current_flipped][i]) {
                ans = min(ans, ff + dp(current_flipped, i, msk | (1 << i)));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[flipped][idx][msk] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a[0].resize(n);
    a[1].resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[1][i];
    }
    memo.resize(2);
    for (int i = 0; i < 2; i++) {
        memo[i].resize(n + 1);
        for (int j = 0; j <= n; j++) {
            memo[i][j].resize(1 << n, -1);
        }
    }
    int ans = dp(0, n, 0);
    cout << (ans >= 1000000000 ? -1 : ans) << endl;
    return 0;
}
// End of Code
