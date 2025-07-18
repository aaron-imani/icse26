#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <utility>
using namespace std;

struct FastInput {
private:
    char buffer[1024 * 8];
    int pos = 0;
    int size = 0;
    istream& in;
    void readBuffer() {
        if (pos < size) return;
        pos = 0;
        size = in.readsome(buffer, sizeof(buffer));
        if (size == 0) throw runtime_error("EOF");
    }
    int read() {
        if (pos >= size) readBuffer();
        return buffer[pos++];
    }
public:
    FastInput(istream& is) : in(is) {}
    int nextInt() {
        int sign = 1;
        int val = 0;
        int c = read();
        while (isSpace(c)) c = read();
        if (c == '-') {
            sign = -1;
            c = read();
        }
        while (c >= '0' && c <= '9') {
            val = val * 10 + (c - '0');
            c = read();
        }
        return val * sign;
    }
    string nextString() {
        string s;
        int c = read();
        while (isSpace(c)) c = read();
        while (!isSpace(c) && c != EOF) {
            s.push_back(c);
            c = read();
        }
        return s;
    }
    bool isSpace(int c) const {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    }
};

class Solver {
    FastInput& in;
    ostream& out;
public:
    Solver(FastInput& in, ostream& out) : in(in), out(out) {}
    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H+2, vector<char>(W+2));
        for (int i = 1; i <= H; ++i) {
            string s = in.nextString();
            for (int j = 1; j <= W; ++j) {
                C[i][j] = s[j-1];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' && 
                    C[i-1][j] != '#' && 
                    C[i+1][j] != '#' &&
                    C[i][j-1] != '#' &&
                    C[i][j+1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    FastInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
