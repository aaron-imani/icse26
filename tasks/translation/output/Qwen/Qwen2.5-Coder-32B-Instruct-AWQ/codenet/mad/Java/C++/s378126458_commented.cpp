#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<int> pre(N + 1, 0);
    
    // Building the k array and prefix sum array in one loop
    for (int i = 1; i < N; i++) {
        pre[i] = (s[i - 1] == 'A' && s[i] == 'C') ? 1 : 0;
        pre[i] += pre[i - 1];
    }
    
    // Querying
    while (Q-- > 0) {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << endl;
    }
    
    return 0;
}
// End of Code
