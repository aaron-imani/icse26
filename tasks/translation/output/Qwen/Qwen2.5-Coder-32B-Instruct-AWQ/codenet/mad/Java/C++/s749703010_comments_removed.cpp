#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

const int MAX_N = 20;
const int INF = 1e9;

int memo[2][MAX_N + 1][1 << MAX_N];
int a[2][MAX_N];
int n;

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = __builtin_popcount(msk);
    int ff = 0;
    int ans = INF;
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
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 0; i < n; i++) cin >> a[1][i];
    memset(memo, -1, sizeof(memo));
    int ans = dp(0, n, 0);
    cout << (ans >= INF ? -1 : ans) << endl;
    return 0;
}
// End of Code
