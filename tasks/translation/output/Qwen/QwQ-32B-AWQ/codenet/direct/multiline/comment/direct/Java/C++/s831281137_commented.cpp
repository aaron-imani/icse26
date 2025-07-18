#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nint() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int N = nint();
    int W = nint();

    vector<int> v(N+1);
    vector<int> w(N+1);
    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    vector<vector<int>> sumV(N+1, vector<int>(W+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i-1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum - w[i]] + v[i]);
        }
    }

    cout << sumV[N][W] << endl;
    return 0;
}
// End of Code
