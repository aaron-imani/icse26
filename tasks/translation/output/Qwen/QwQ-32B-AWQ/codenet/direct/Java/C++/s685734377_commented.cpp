#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

class FastScanner {
private:
    istream& in;
    queue<string> tokens;

public:
    FastScanner(istream& in) : in(in) {}

    string next() {
        if (tokens.empty()) {
            string line;
            if (!getline(in, line)) return "";
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) return "";
        string res = tokens.front();
        tokens.pop();
        return res;
    }

    int nextInt() {
        return stoi(next());
    }
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        long long P = 37, Q = 47;
        vector<long long> powP(n + 1, 1);
        vector<long long> powQ(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }

        for (int i = 0; i < n; ++i) {
            string s = in.next();
            for (int j = 0; j < n; ++j) {
                a[i][j] = s[j];
            }
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int exponent = (j - k + n) % n;
                    hashRow[i][k] += a[i][j] * powP[exponent];
                    exponent = (i - k + n) % n;
                    hashCol[j][k] += a[i][j] * powP[exponent];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; ++A) {
            for (int B = 0; B < n; ++B) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    int row_idx = (i + A) % n;
                    if (row_idx < 0) row_idx += n;
                    int col_idx = (i + B) % n;
                    if (col_idx < 0) col_idx += n;
                    long long row_val = hashRow[row_idx][B];
                    long long col_val = hashCol[col_idx][A];
                    if (row_val != col_val) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans++;
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
