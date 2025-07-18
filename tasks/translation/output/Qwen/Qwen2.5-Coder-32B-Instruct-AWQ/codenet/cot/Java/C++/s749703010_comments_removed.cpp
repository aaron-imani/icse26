#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <climits>

using namespace std;

struct Pair {
    int l, r;
    Pair(int a, int b) : l(a), r(b) {}
};

int memo[2][20][1 << 20];
int a[2][20];
int n;

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
                ans = min(ans, ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i));
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
    cout << (ans >= 1e8 ? -1 : ans) << endl;
    return 0;
}
// End of Code
