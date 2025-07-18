#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int l, r;
    Pair(int a, int b) : l(a), r(b) {}
};

vector<vector<int>> a(2); // a[0] and a[1] are the two arrays
int n;
vector<vector<vector<int>>> memo; // memo[fliped][idx][msk]

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ans = 1e9;
    int ff = 0;
    for (int i = 0; i < n; ++i) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            int current = (idx == n) ? 0 : a[fliped][idx];
            int compare = a[(nf + (ff % 2)) % 2][i];
            if (idx == n || current <= compare) {
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a[0].resize(n);
    a[1].resize(n);
    for (int i = 0; i < n; ++i) cin >> a[0][i];
    for (int i = 0; i < n; ++i) cin >> a[1][i];
    memo.resize(2);
    for (int f = 0; f < 2; ++f) {
        memo[f].resize(n + 1);
        for (int idx = 0; idx <= n; ++idx) {
            memo[f][idx].resize(1 << n, -1);
        }
    }
    int ans = dp(0, n, 0);
    cout << (ans >= 1e9 ? -1 : ans) << endl;
    return 0;
}
// End of Code
