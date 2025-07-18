#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dpx(vector<vector<int>>& arr, int n) {
    vector<vector<int>> dp(n, vector<int>(3));

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < n; i++) {
        for (int in = 0; in < 3; in++) {
            int j = 0, k = 0;
            if (in == 1) {
                j = 0;
                k = 2;
            } else if (in == 0) {
                j = 1;
                k = 2;
            } else {
                j = 0;
                k = 1;
            }
            dp[i][in] = max(dp[i - 1][k], dp[i - 1][j]) + arr[i][in];
        }
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = dpx(arr, n);
    cout << ans << endl;

    return 0;
}
// End of Code
