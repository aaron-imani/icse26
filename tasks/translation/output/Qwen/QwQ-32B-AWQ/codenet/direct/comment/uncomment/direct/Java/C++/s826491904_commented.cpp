#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int max_val, min_val;
    int first;
    cin >> first;
    max_val = min_val = first;
    for (int i = 1; i < N; i++) {
        int in;
        cin >> in;
        max_val = max(max_val, in);
        min_val = min(min_val, in);
    }
    cout << (max_val - min_val) << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
