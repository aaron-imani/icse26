#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct FastScanner {
    queue<string> tokens;
    FastScanner(istream& in) {
        string line;
        while (getline(in, line)) {
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push(token);
            }
        }
    }
    string next() {
        if (tokens.empty()) throw runtime_error("No more tokens");
        string token = tokens.front();
        tokens.pop();
        return token;
    }
    int nextInt() {
        string token = next();
        return stoi(token);
    }
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            string s = in.next();
            for (int j = 渴:0; j < n; ++j) {
                a[i][j] = s[j];
            }
        }

        const long long P = 37;
        vector<long long> powP(n + 1);
        powP[0] = 1;
        for (int i = 1; i <= n; ++i) {
            powP[i] = powP[i - 1] * P;
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int mod = (j - k + n) % n;
                    hashRow[i][k] += a[i][j] * powP[mod];
                    mod = (i - k + n) % n;
                    hashCol[j][k] += a[i][j] * powP[mod];
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
