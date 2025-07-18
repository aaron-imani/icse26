#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class FastScanner {
private:
    istream& in;
    queue<string> tokens;
    string currentLine;
public:
    FastScanner(istream& in) : in(in) {}
    string next() {
        if (tokens.empty()) {
            currentLine.clear();
            if (!getline(in, currentLine)) return "";
            stringstream ss(currentLine);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        if (!tokens.empty()) {
            string t = tokens.front();
            tokens.pop();
            return t;
        }
        return "";
    }
    int nextInt() { return stoi(next()); }
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            string s = in.next();
            for (int j = 0; j < n; ++j) {
                a[i][j] = s[j];
            }
        }

        long long P = 37, Q = 47;
        vector<long long> powP(n + 1);
        vector<long long> powQ(n + 1);
        powP[0] = 1;
        powQ[0] = 1;
        for (int i = 1; i <= n; ++i) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int exp = (j - k + n) % n;
                    hashRow[i][k] += a[i][j] * powP[exp];
                    exp = (i - k + n) % n;
                    hashCol[j][k] += a[i][j] * powP[exp];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; ++A) {
            for (int B = _B < n; ++B) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    int row_i = (i + A) % n;
                    int col_i = (i + B) % n;
                    if (hashRow[row_i][B] != hashCol[col_i][A]) {
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
