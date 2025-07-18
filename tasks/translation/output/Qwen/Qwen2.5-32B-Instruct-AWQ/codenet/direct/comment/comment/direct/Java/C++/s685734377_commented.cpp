#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TaskB {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<char>> a(n, vector<char>(n));
        long long P = 37, Q = 47;
        vector<long long> powP(n + 1), powQ(n + 1);
        powP[0] = powQ[0] = 1;
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }
        for (int i = 0; i < n; i++) {
            string s;
            in >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];
            }
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n)), hashCol(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    hashRow[i][k] += a[i][j] * powP[(j - k + n) % n];
                    hashCol[j][k] += a[i][j] * powP[(i - k + n) % n];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; A++) {
            for (int B = 0; B < n; B++) {
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    ok &= hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A];
                }
                ans += ok ? 1 : 0;
            }
        }
        out << ans << endl;
    }
};

int main() {
    istream& in = cin;
    ostream& out = cout;
    TaskB solver;
    solver.solve(1, in, out);
    return 0;
}
// End of Code
