#include <iostream>
#include <vector>
#include <string>
using namespace std;

int nint() {
    int x;
    cin >> x;
    return x;
}

long nlong() {
    long x;
    cin >> x;
    return x;
}

string nstr() {
    string s;
    cin >> s;
    return s;
}

vector<char> nsToChars() {
    string s = nstr();
    return vector<char>(s.begin(), s.end());
}

vector<long> nlongs(int n) {
    return nlongs(n, 0, 0);
}

vector<int> nints(int n) {
    return nints(n, 0, 0);
}

vector<int> nints(int n, int padL, int padR) {
    vector<int> a(padL + n + padR);
    for (int i = 0; i < n; i++) {
        a[padL + i] = nint();
    }
    return a;
}

vector<long> nlongs(int n, int padL, int padR) {
    vector<long> a(padL + n + padR);
    for (int i = 0; i < n; i++) {
        a[padL + i] = nlong();
    }
    return a;
}

vector<string> nstrs(int n) {
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = nstr();
    }
    return a;
}

vector<vector<char>> nsToChars2D(int h, int w) {
    return nsToChars2D(h, w, 0);
}

vector<vector<char>> nsToChars2D(int h, int w, int pad) {
    int total_h = h + 2 * pad;
    int total_w = w + 2 * pad;
    vector<vector<char>> a2(total_h, vector<char>(total_w));
    for (int i = 0; i < h; i++) {
        vector<char> row = nsToChars();
        for (int j = 0; j < row.size(); j++) {
            a2[i + pad][j + pad] = row[j];
        }
    }
    return a2;
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
        for (int i_sum = 0; i_sum < w[i] && i_sum <= W; i_sum++) { // Added condition to prevent overflow
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
