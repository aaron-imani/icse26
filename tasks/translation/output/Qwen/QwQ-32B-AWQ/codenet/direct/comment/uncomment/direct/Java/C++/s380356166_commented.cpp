#include <iostream>
using namespace std;

class Solver {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int K, S;
        in >> K >> S;
        int ans = 0;
        for (int x = 0; x <= K; ++x) {
            for (int y = 0; y <= K; ++y) {
                int z = S - x - y;
                if (z >= 0 && z <= K) {
                    ans++;
                }
            }
        }
        out << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solver solver;
    solver.solve(1, cin, cout);
    return 0;
}
// End of Code
