#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct FastScanner {
    FastScanner(istream& in) : inStream(in), pos(0) {}

    string next() {
        while (true) {
            if (pos == line.length()) {
                if (!getline(inStream, line)) return "";
                pos = 0;
            }
            while (pos < line.length() && isspace(line[pos])) ++pos;
            if (pos >= line.length()) continue;
            size_t start = pos;
            while (pos < line.length() && !isspace(line[pos])) ++pos;
            return line.substr(start, pos - start);
        }
    }

    int nextInt() {
        string s = next();
        return stoi(s);
    }

private:
    istream& inStream;
    string line;
    size_t pos;
};

struct TaskB {
    void solve(int testNumber, FastScanner& in, ostream& out) {
        int n = in.nextInt();
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            string s = in.next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];
            }
        }

        long long P = 37, Q = 47;
        vector<long long> powP(n + 1), powQ(n + 1);
        powP[0] = powQ[0] = 1;
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
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
    TaskB().solve(1, in, cout);
    return 0;
}
// End of Code
