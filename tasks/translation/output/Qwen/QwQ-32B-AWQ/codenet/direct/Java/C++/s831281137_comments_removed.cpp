#include <iostream>
#include <vector>
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

    vector<vector<int>> sumV(N+1, vector<int>(W+1));

    for (int i = 1; i <= N; i++) {
        for (int s = 0; s < w[i]; s++) {
            sumV[i][s] = sumV[i-1][s];
        }
        for (int s = w[i]; s <= W; s++) {
            sumV[i][s] = max(sumV[i-1][s], sumV[i-1][s - w[i]] + v[i]);
        }
    }

    cout << sumV[N][W] << endl;
    return 0;
} // End of Code
