#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastScanner {
    istream& in;
    string buffer;
    vector<string> tokens;
    size_t tokenIndex;

public:
    FastScanner(istream& in) : in(in), tokenIndex(0) {}

    string next() {
        if (tokenIndex >= tokens.size()) {
            tokenIndex = 0;
            getline(in, buffer);
            tokens.clear();
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        return tokens[tokenIndex++];
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
        vector<long long> powP(n + 1, 1), powQ(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }
        for (int i = 0; i < n; i++) {
            string line = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = line[j];
            }
        }

        vector<vector<long long>> hashRow(n, vector<long long>(n, 0));
        vector<vector<long long>> hashCol(n, vector<long long>(n, 0));
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
    ostream& out = cout;
    TaskB solver;
    solver.solve(1, in, out);
    return 0;
}
// End of Code
