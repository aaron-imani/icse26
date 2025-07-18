#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyInput {
private:
    static constexpr int BUFFER_SIZE = 1024 * 8;
    char buffer[BUFFER_SIZE];
    int pos = 0;
    int readLen = 0;

    int readImpl(char* dest, int size) {
        return fread(dest, 1, size, stdin);
    }

public:
    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = readImpl(buffer, BUFFER_SIZE);
            if (readLen <= 0) throw runtime_error("EOF");
        }
        return buffer[pos++];
    }

    int nextInt() {
        int c = read();
        while (isSpace(c)) c = read();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = read();
        }
        int res = 0;
        do {
            res = res * 10 + (c - '0');
            c = read();
        } while (isDigit(c));
        return res * sign;
    }

    string nextString() {
        int c = read();
        while (isSpace(c)) c = read();
        string s;
        do {
            s.push_back(c);
            c = read();
        } while (!isSpace(c) && c != EOF);
        return s;
    }

private:
    bool isDigit(int c) const {
        return (c >= '0' && c <= '9') || c == '-';
    }

    bool isSpace(int c) const {
        return c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }
};

class Solver {
    MyInput& in;
    ostream& out;
public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}
    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));
        for (int i = 0; i < H; ++i) {
            string s = in.nextString();
            for (int j = 0; j < W; ++j) {
                C[i+1][j+1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        bool valid = true;
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#') {
                    bool hasAdjacent = false;
                    if (C[i-1][j] == '#') hasAdjacent = true;
                    if (C[i+1][j] == '#') hasAdjacent = true;
                    if (C[i][j-1] == '#') hasAdjacent = true;
                    if (C[i][j+1] == '#') hasAdjacent = true;
                    if (!hasAdjacent) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }
        out << (valid ? "Yes" : "No") << endl;
    }
};

int main() {
    MyInput in;
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}
// End of Code
