#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<int> v, w;
vector<vector<int>> sumV;

int nint() {
    int x;
    cin >> x;
    return x;
}

int main() {
    N = nint();
    W = nint();

    v.resize(N + 1);
    w.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    sumV.resize(N + 1, vector<int>(W + 1));

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i - 1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = max(sumV[i - 1][i_sum], sumV[i - 1][i_sum - w[i]] + v[i]);
        }
    }

    cout << sumV[N][W] << endl;
}

// End of Code
