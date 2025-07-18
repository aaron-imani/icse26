#include <iostream>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;
    int ans = 0;
    for (int x = 0; x <= K; ++x) {
        for (int y = 0; y <= K; ++y) {
            int wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// End of Code
