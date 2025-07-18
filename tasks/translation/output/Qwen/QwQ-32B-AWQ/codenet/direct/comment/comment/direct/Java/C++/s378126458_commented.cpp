#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<int> pre(N+1, 0);

    for(int i = 1; i < N; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            pre[i] = 1;
        }
    }

    // Build prefix sum
    for(int i = 1; i < N; i++) {
        pre[i] += pre[i-1];
    }

    while(Q--) {
        int l, r;
        cin >> l >> r;
        r--;
        cout << (pre[r] - pre[l-1]) << endl;
    }
}
// End of Code
