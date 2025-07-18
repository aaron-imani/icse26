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
            for (int j = 0; j < n; j++) {
                in >> a[i][j];
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
                    ok &= (hashRow[(i + A) % n][B] == hashCol[(i + B) % n][A]);
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
    vector<string> vec;
    int vec_idx;

    FastScanner(istream& in) : in(in), vec_idx(0) {}

    bool scan() {
        while (vec_idx >= vec.size()) {
            if (!getline(in, str)) {
                return false;
            }
            vec = move(split(str, ' '));
            vec_idx = 0;
        }
        return true;
    }

    string next() {
        if (!scan()) {
            throw runtime_error("No more input");
        }
        return vec[vec_idx++];
    }

    int nextInt() {
        return stoi(next());
    }

    vector<string> split(const string& str, char delim) {
        vector<string> result;
        stringstream ss(str);
        string item;
        while (getline(ss, item, delim)) {
            result.push_back(item);
        }
        return result;
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
