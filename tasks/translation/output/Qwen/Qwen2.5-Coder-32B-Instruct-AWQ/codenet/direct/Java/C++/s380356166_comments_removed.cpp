#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

class MyInput {
private:
    string buffer;
    size_t pos;
    istream& in;

    void ensureBuffer() {
        if (pos >= buffer.size()) {
            getline(in, buffer);
            pos = 0;
        }
    }

public:
    MyInput(istream& is) : in(is), pos(0) {}

    int nextInt() {
        ensureBuffer();
        int ret = 0;
        bool negative = false;
        while (pos < buffer.size() && !isdigit(buffer[pos]) && buffer[pos] != '-') {
            pos++;
        }
        if (buffer[pos] == '-') {
            negative = true;
            pos++;
        }
        while (pos < buffer.size() && isdigit(buffer[pos])) {
            ret = ret * 10 + (buffer[pos] - '0');
            pos++;
        }
        return negative ? -ret : ret;
    }

    long long nextLong() {
        ensureBuffer();
        long long ret = 0;
        bool negative = false;
        while (pos < buffer.size() && !isdigit(buffer[pos]) && buffer[pos] != '-') {
            pos++;
        }
        if (buffer[pos] == '-') {
            negative = true;
            pos++;
        }
        while (pos < buffer.size() && isdigit(buffer[pos])) {
            ret = ret * 10 + (buffer[pos] - '0');
            pos++;
        }
        return negative ? -ret : ret;
    }

    string nextString() {
        ensureBuffer();
        string ret;
        while (pos < buffer.size() && isspace(buffer[pos])) {
            pos++;
        }
        while (pos < buffer.size() && !isspace(buffer[pos])) {
            ret += buffer[pos];
            pos++;
        }
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
    Solver solver;
    solver.solve(1, in, cout);
    return 0;
}
// End of Code
