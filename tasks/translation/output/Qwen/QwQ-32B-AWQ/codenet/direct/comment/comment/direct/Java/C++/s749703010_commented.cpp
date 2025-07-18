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
            if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_flipped = (nf + (ff % 2)) % 2;
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_flipped, i, new_msk);
                ans = min(ans, res);
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[flipped][idx][msk] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    a.resize(2);
    a[0].resize(n);
    a[1].resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = ,0; i < n; i++) {
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

    cout << (ans >= 1e9 ? -1 : ans) << endl;

    return 0;
}
// End of Code
Wait, there is a typo in the second loop in main:

for (int i = ,0; i < n; i++) should be for (int i = 0; i < n; i++).

So correcting that:


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
        if ((msk & (1 << i)) == )
        {
            int nf = x % 2;
            if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_flipped = (nf + (ff % 2)) % 2;
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_flipped, i, new_msk);
                ans = min(ans, res);
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[flipped][idx][msk] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    a.resize(2);
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

    cout << (ans >= 1e9 ? -1 : ans) << endl;

    return 0;
}
// End of Code
Wait, in the first for loop in dp function, there's a missing condition in the if statement. The line:

if ((msk & (1 << i)) == )

should be:

if ((msk & (1 << i)) == 0) 

So the correct code for that part is:


if ((msk & (1 << i)) == 0) {
Correcting that:


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
            if (idx == n || a[flipped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                int new_flipped = (nf + (ff % 2)) % 2;
                int new_msk = msk | (1 << i);
                int res = ff + dp(new_flipped, i, new_msk);
                ans = min(ans, res);
            }
            ff++;
        } else {
            x--;
        }
    }
    memo[flipped][idx][msk] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    a.resize(2);
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

    cout << (ans >= 1e9 ? -1 : ans) << endl;

    return 0;
}
// End of Code
This should be the correct translation with all the fixes applied.
