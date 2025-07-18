#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class FastScanner {
private:
    istream& in;
    queue<string> tokens;
    void fillTokens() {
        if (!tokens.empty()) return;
        string line;
        getline(in, line);
        istringstream iss(line);
        string token;
        while (iss >> token) {
            tokens.push(token);
        }
    }
public:
    FastScanner(istream& in) : in(in) {}
    string next() {
        fillTokens();
        if (tokens.empty()) throw runtime_error("No token");
        string result = tokens.front();
        tokens.pop();
        return result;
    }
    int nextInt() { return stoi(next()); }
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = in.next();
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
                char c = a[i][j];
                for (int k = 0; k < n; ++k) {
                    int mod = (j - k + n) % n;
                    hashRow[i][k] += (long long)c * powP[mod];
                    mod = (i - k + n) % n;
                    hashCol[j][k] += (long long)c * powP[mod];
                }
            }
        }

        int ans = 0;
        for (int A = 0; A < n; ++A) {
            for (int B = 0; B < n; ++B) {
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    int row = (i + A) % n;
                    int col = (i + B) % n;
                    if (hashRow[row][B] != hashCol[col][A]) {
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
    FastScanner in(cin);
    TaskB solver;
    solver.solve(1, in, cout);
    return 0;
}
// End of Code
