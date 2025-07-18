#include <bits/stdc++.h>
using namespace std;

class TaskB {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int n;
        in >> n;
        vector<vector<char>> a(n, vector<char>(n));
        long long P = 37, Q = 47;
        vector<long long> powP(n + 1, 1), powQ(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            powP[i] = powP[i - 1] * P;
            powQ[i] = powQ[i - 1] * Q;
        }
        for (int i = 0; i < n; i++) {
            string s;
            in >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j];
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
                    if (hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]) {
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

class FastScanner {
public:
    istream& in;
    string str;
    size_t pos;

    FastScanner(istream& in) : in(in), pos(0) {}

    string next() {
        while (pos >= str.size()) {
            getline(in, str);
            pos = 0;
        }
        while (pos < str.size() && isspace(str[pos])) pos++;
        size_t start = pos;
        while (pos < str.size() && !isspace(str[pos])) pos++;
        return str.substr(start, pos - start);
    }

    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastScanner in(cin);
    ofstream out("output.txt");
    TaskB solver;
    solver.solve(1, in, cout);
    return 0;
}
// End of Code
