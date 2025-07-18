#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> memo;
vector<vector<int>> a;
int n;

int dp(int flipped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[flipped][idx][msk] != -1) return memo[flipped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int nf_plus = (nf + (ff % 2)) % 2;
            if (idx == n || a[flipped][idx] <= a[nf_plus][i]) {
                ans = min(ans, ff + dp(nf_plus, i, msk | (1 << i)));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[flipped][idx][msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(2, vector<int>(n));
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
