#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class FastScanner {
private:
    istream& in;
    string buffer;
    vector<string> tokens;
    size_t ptr = 0;

public:
    FastScanner(istream& in) : in(in), ptr(0) {}

    string next() {
        if (ptr >= tokens.size()) {
            tokens.clear();
            getline(in, buffer);
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            ptr = 0;
        }
        return tokens[ptr++];
    }

    int nextInt() {
        return stoi(next());
    }
};

struct TaskB {
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        const long long P = 37, Q = 47;
        vector<long long> powP(n + 1), powQ(n + 1);
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

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    long long val = static_cast<long long>(a[i][j]);
                    int exp = (j - k + n) % n;
                    hashRow[i][k] += val * powP[exp];
                    exp = (i - k + n) % n;
                    hashCol[j][k] += val * powP[exp];
                }
            }
        }

        int ans = 
        0;
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
