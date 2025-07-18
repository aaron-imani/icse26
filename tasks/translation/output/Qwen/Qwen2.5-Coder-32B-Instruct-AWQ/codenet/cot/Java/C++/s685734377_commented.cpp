#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class FastScanner {
    stringstream ss;
    string line;

public:
    FastScanner(istream& in) {
        getline(in, line);
        ss = stringstream(line);
    }

    int nextInt() {
        string token;
        ss >> token;
        return stoi(token);
    }

    string next() {
        string token;
        ss >> token;
        return token;
    }
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        long P = 37, Q = 47;
        vector<long> powP(n + 1, 1), powQ(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }
        for (int i = 0; i < n; i++) {
            string row = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = row[j];
            }
        }

        vector<vector<long>> hashRow(n, vector<long>(n, 0));
        vector<vector<long>> hashCol(n, vector<long>(n, 0));
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
    FastScanner in(cin);
    TaskB solver;
    solver.solve(1, in, cout);
    return 0;
}
// End of Code
