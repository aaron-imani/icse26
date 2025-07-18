#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; ++i) {
        cin >> list[i];
    }
    int current_max = 0;
    int output = 0;
    for (int num : list) {
        if (num >= current_max) {
            current_max = num;
            output++;
        }
    }
    cout << output << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
