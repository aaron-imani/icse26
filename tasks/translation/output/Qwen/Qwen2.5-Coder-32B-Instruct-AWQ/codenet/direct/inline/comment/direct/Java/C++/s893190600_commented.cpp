#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

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
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        int result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    long long nextLong() {
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        long long result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        return negative ? -result : result;
    }

    double nextDouble() {
        int c = skipSpaces();
        bool negative = c == '-';
        if (negative) c = read();
        double result = 0;
        while (isdigit(c)) {
            result = result * 10 + (c - '0');
            c = read();
        }
        if (c == '.') {
            c = read();
            double fraction = 0.1;
            while (isdigit(c)) {
                result += fraction * (c - '0');
                fraction *= 0.1;
                c = read();
            }
        }
        return negative ? -result : result;
    }

    string nextString() {
        int c = skipSpaces();
        string result;
        while (c != -1 && !isspace(c)) {
            result += (char)c;
            c = read();
        }
        return result;
    }

private:
    int skipSpaces() {
        int c;
        do {
            c = read();
        } while (c != -1 && isspace(c));
        return c;
    }
};

struct PP {
    int key, val;
    PP(int k, int v) : key(k), val(v) {}
};

struct PPP {
    int key, val1, val2;
    PPP(int k, int v1, int v2) : key(k), val1(v1), val2(v2) {}
};

struct PPL {
    long long key, val;
    PPL(long long k, long long v) : key(k), val(v) {}
};

struct PPDL {
    long long key;
    vector<long long> val;
    PPDL(long long k, vector<long long> v) : key(k), val(v) {}
};

class Solver {
public:
    MyInput& in;
    ostream& out;

    Solver(MyInput& i, ostream& o) : in(i), out(o) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
        for (int i = 0; i < H; i++) {
            string line = in.nextString();
            for (int j = 0; j < W; j++) {
                C[i + 1][j + 1] = line[j];
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

int main(){
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
