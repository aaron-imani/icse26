#include <iostream>
#include <vector>
#include <climits>
#include <bitset>

using namespace std;

class Pair {
public:
    int l, r;
    Pair(int a, int b) : l(a), r(b) {}
    
    string toString() {
        return to_string(l) + " " + to_string(r);
    }
};

int n;
vector<vector<int>> a;
vector<vector<vector<int>>> memo;

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | (1 << i)));
            }
            ff++;
        } else x--;
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(2, vector<int>(n));
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];
    memo.resize(2, vector<vector<int>>(n + 1, vector<int>(1 << n, -1)));
    int ans = dp(0, n, 0);
    cout << (ans >= 1e8 ? -1 : ans) << endl;
    return 0;
}
// End of Code
