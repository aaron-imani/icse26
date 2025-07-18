#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<size_t> pre(N+1, 0);
    for(size_t i = 1; i < N; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') {
            pre[i] = 1; // initially the prefix sum array is the k array
        }
    }
    // Building the psa
    for(size_t i = 1; i < N; i++) {
        pre[i] += pre[i-1];
    }
    // Querying
    while(Q-- > 0) {
        size_t l, r;
        cin >> l >> r;
        r--;
        cout << pre[r] - pre[l-1] << endl;
    }
}
// End of Code
