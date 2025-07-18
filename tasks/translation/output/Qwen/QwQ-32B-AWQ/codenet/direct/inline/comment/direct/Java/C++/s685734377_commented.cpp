#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class FastScanner {
    istream& in;
    string buffer;
    istringstream currentStream;
    queue<string> tokens;
public:
    FastScanner(istream& in) : in(in) {}
    string next() {
        while (tokens.empty()) {
            string line;
            if (!getline(in, line)) break;
            currentStream.str(line);
            currentStream.clear();
            string token;
            while (currentStream >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) throw runtime_error("No more tokens.");
        string res = tokens.front();
        tokens.pop();
        return res;
    }
    int nextInt() { return stoi(next()); }
};

struct TaskB {
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<string> a(n);
        for (int i = 0; i < n; ++i) a[i] = in.next();

        long long P = 37, Q = 47;
        vector<long long> powP(n + 1), powQ(n + 1);
        powP[0] = powQ[0] = 1;
        for (int i = 1; i <= n; ++i) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = a[i][j];
                for (int k = 0; k < n; ++k) {
                    long long val = static_cast<long long>(c);
                    hashRow[i][k] += val * powP[(j - k + n) % n];
                    hashCol[j][k] += val * powP[(i - k + n) % n];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; ++A) {
            for (int B = 0; B < n; ++B) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    int row_i = (i + A) % n;
                    int col_i = (i + B) % n;
                    if (hashRow[row_i][B] != hashCol[col_i][A]) {
                        ok = false;
                        break;
                    }
                }
                ans += ok ? 1 : 0;
            }
        }
        out << ans << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TaskB solver;
    FastScanner in(cin);
    solver.solve(1, in, cout);
    return 0;
}
// End of Code
