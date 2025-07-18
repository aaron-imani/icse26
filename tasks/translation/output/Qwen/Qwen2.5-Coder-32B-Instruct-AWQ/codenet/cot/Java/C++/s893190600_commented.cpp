#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>

using namespace std;

class MyInput {
private:
    istream& in;
    string buffer;
    size_t pos;

public:
    MyInput(istream& is) : in(is), pos(0) {}

    int read() {
        if (pos >= buffer.size()) {
            getline(in, buffer);
            pos = 0;
        }
        return pos < buffer.size() ? buffer[pos++] : -1;
    }

    int nextInt() {
        int ret = 0;
        bool negative = false;
        int c = read();
        while (c != -1 && !isdigit(c)) c = read();
        if (c == '-') negative = true, c = read();
        while (isdigit(c)) ret = ret * 10 + c - '0', c = read();
        return negative ? -ret : ret;
    }

    long long nextLong() {
        long long ret = 0;
        bool negative = false;
        int c = read();
        while (c != -1 && !isdigit(c)) c = read();
        if (c == '-') negative = true, c = read();
        while (isdigit(c)) ret = ret * 10 + c - '0', c = read();
        return negative ? -ret : ret;
    }

    double nextDouble() {
        double ret = 0;
        bool negative = false;
        int c = read();
        while (c != -1 && !isdigit(c) && c != '.') c = read();
        if (c == '-') negative = true, c = read();
        while (isdigit(c)) ret = ret * 10 + c - '0', c = read();
        if (c == '.') {
            double fraction = 0.1;
            c = read();
            while (isdigit(c)) ret += fraction * (c - '0'), fraction *= 0.1, c = read();
        }
        return negative ? -ret : ret;
    }

    string nextString() {
        string ret;
        int c = read();
        while (c != -1 && isspace(c)) c = read();
        while (c != -1 && !isspace(c)) ret += (char)c, c = read();
        return ret;
    }
};

class PP {
public:
    int key, val;
    PP(int k, int v) : key(k), val(v) {}
};

class Solver {
private:
    MyInput& in;
    ostream& out;

public:
    Solver(MyInput& i, ostream& o) : in(i), out(o) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
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
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                    && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
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
