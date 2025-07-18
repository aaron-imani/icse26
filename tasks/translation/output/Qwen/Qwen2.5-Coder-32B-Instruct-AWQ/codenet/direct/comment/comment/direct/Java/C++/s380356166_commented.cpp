#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solver {
public:
    void solve(int testNumber) {
        int ans = 0;
        int K, S;
        cin >> K >> S;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - x - y;
                if (z >= 0 && z <= K) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Solver solver;
    solver.solve(1);
    return 0;
}
// End of Code
