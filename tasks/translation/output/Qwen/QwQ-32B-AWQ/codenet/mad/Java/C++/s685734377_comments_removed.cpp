#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FastScanner {
public:
    FastScanner(istream& in) : is(in) {}

    int nextInt() {
        return stoi(next());
    }

    string next() {
        while (tokenIter == tokens.end()) {
            string line;
            if (!getline(is, line)) break;
            stringstream iss(line);
            tokens.clear();
            string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
            tokenIter = tokens.begin();
        }
        if (tokenIter != tokens.end()) {
            string res = *tokenIter;
            ++tokenIter;
            return res;
        }
        return "";
    }

private:
    istream& is;
    vector<string> tokens;
    vector<string>::iterator tokenIter;
};

class TaskB {
public:
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        const long long P = 37;
        const long long Q = 47;
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
                    hashRow[i][k] += static_cast<unsigned char>(a[i][j]) * powP[(j - k + n) % n];
                    hashCol[j][k] += static_cast<unsigned char>(a[i][j]) * powP[(i - k + n) % n];
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
