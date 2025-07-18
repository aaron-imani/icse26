#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

class Solver {
public:
    istream& in;
    ostream& out;

    Solver(istream& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H, W;
        in >> H >> W;
        vector<vector<char>> C(H + 2, vector<char>(W + 2, '.'));
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                in >> C[i][j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

struct PP {
    int key, val;
    PP(int key, int val) : key(key), val(val) {}
};

struct PPL {
    long key, val;
    PPL(long key, long val) : key(key), val(val) {}
};

struct PPDL {
    long key;
    vector<long> val;
    PPDL(long key, const vector<long>& val) : key(key), val(val) {}
};

struct PPKEY {
    int key, val;
    PPKEY(int key, int val) : key(key), val(val) {}
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
};

struct PPLKEY {
    long key, val;
    PPLKEY(long key, long val) : key(key), val(val) {}
    bool operator==(const PPLKEY& other) const {
        return key == other.key && val == other.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solver solver(cin, cout);
    solver.solve();

    return 0;
}
// End of Code
