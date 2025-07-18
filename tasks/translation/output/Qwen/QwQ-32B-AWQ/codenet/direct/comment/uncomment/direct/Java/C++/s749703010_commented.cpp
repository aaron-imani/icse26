#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int n;
vector<vector<vector<int>>> memo;

int dp(int fliped, int idx, int msk) {
    if (msk == ((1 << n) - 1)) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = (int)1e9;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int temp_flip = (nf + (ff % 2)) % 2;
            if (idx == n || a[fliped][idx] <= a[temp_flip][i]) {
                ans = min(ans, ff + dp(temp_flip, i, msk | (1 << i)));
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[fliped][idx][msk] = ans;
    return ans;
}

int main() {
    cin >> n;
    a.resize(2);
    a[0].resize(n);
    a[1].resize(n);
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];
    memo.resize(2);
    for (int i = 0; i < 2; i++) {
        memo[i].resize(n + 1);
        for (int j = 0; j <= n; j++) {
            memo[i][j].resize(1 << n, -1);
        }
    }
    int ans = dp(0, n, 0);
    cout << (ans >= 1e9 ? -1 : ans) << endl;
    return 0;
}
// End of Code
