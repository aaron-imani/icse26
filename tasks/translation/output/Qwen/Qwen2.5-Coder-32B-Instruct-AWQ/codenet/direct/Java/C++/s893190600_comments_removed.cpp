#include <bits/stdc++.h>
using namespace std;

class MyInput {
private:
    ifstream in;
    string buffer;
    size_t pos;
    size_t readLen;

public:
    MyInput(istream &is) : in(is), pos(0), readLen(0) {}

    int read() {
        if (pos >= readLen) {
            pos = 0;
            if (!getline(in, buffer)) {
                throw runtime_error("End of file");
            }
            readLen = buffer.size();
        }
        return pos < readLen ? buffer[pos++] : -1;
    }

    int nextInt() {
        int c = read();
        while (isspace(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        return sgn * res;
    }

    long long nextLong() {
        int c = read();
        while (isspace(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long long res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        return sgn * res;
    }

    double nextDouble() {
        int c = read();
        while (isspace(c)) c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (isdigit(c)) {
            res = res * 10 + c - '0';
            c = read();
        }
        if (c == '.') {
            double f = 1;
            c = read();
            while (isdigit(c)) {
                f *= 0.1;
                res += f * (c - '0');
                c = read();
            }
        }
        return sgn * res;
    }

    string nextString() {
        int c = read();
        while (isspace(c)) c = read();
        string res;
        while (!isspace(c) && c != -1) {
            res += c;
            c = read();
        }
        return res;
    }
};

class Solver {
private:
    MyInput &in;
    ostream &out;

public:
    Solver(MyInput &in, ostream &out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2, '.'));
        for (int i = 0; i < H; i++) {
            string s = in.nextString();
            for (int j = 0; j < W; j++) {
                C[i + 1][j + 1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
