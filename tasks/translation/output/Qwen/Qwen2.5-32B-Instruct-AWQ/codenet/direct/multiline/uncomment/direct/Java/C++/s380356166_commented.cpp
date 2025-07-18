#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solver {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int ans = 0;
        int K, S;
        in >> K >> S;
        int wk = 0;
        for(int x = 0; x <= K; x++) {
            for(int y = 0; y <= K; y++) {
                wk = S - x - y;
                if(wk >= 0 && wk <= K) {
                    ans++;
                }
            }
        }
        out << ans << endl;
    }
};

int main() {
    istream& in = cin;
    ostream& out = cout;
    Solver solver;
    solver.solve(1, in, out);
    return 0;
}

// End of Code
