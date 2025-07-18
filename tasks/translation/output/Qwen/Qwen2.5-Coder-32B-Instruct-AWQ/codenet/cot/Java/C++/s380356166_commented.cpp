#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

class Pair {
public:
    int key;
    int value;

    Pair(int k, int v) : key(k), value(v) {}

    string getString() {
        return "[" + to_string(key) + "] [" + to_string(value) + "]";
    }
};

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
        while (isspace(c)) c = read();
        if (c == '-') negative = true, c = read();
        while (isdigit(c)) ret = ret * 10 + (c - '0'), c = read();
        return negative ? -ret : ret;
    }

    string nextString() {
        string ret;
        int c = read();
        while (isspace(c)) c = read();
        while (!isspace(c) && c != -1) ret += (char)c, c = read();
        return ret;
    }
};

class Solver {
public:
    void solve(int testNumber, MyInput& in, ostream& out) {
        int ans = 0;
        int K = in.nextInt();
        int S = in.nextInt();
        int wk = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                wk = S - x - y;
                if (wk >= 0 && wk <= K) {
                    ans++;
                }
            }
        }
        out << ans << endl;
    }
};

int main() {
    MyInput in(cin);
    ostream& out = cout;

    Solver solver;
    solver.solve(1, in, out);

    return 0;
}
// End of Code
