#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
            getline(in, line);
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push(token);
            }
        }
        string result = tokens.front();
        tokens.pop();
        return result;
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
        unsigned long long P = 37, Q = 47;
        vector<unsigned long long> powP(n + 1), powQ(n + 1);
        powP[0] = 1;
        powQ[0] = 1;
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

        vector<vector<unsigned long long>> hashRow(n, vector<unsigned long long>(n, 0));
        vector<vector<unsigned long long>> hashCol(n, vector<unsigned long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int exponent = (j - k + n) % n;
                    hashRow[i][k] += static_cast<unsigned long long>(a[i][j]) * powP[exponent];
                    exponent = (i - k + n) % n;
                    hashCol[j][k] += static_cast<unsigned long long>(a[i][j]) * powP[exponent];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; ++A) {
            for (int B = 0; B < n; ++B) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    int row_idx = (i + A) % n;
                    int col_idx = (i + B) % n;
                    if (hashRow[row_idx][B] != hashCol[col_idx][A]) {
                        ok = false;
                        break;
                    }
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
