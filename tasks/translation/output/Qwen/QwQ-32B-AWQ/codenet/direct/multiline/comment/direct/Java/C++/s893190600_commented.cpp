#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyInput {
private:
    istream& input;
    vector<char> buffer;
    vector<char> str;
    vector<bool> isDigit;
    vector<bool> isSpace;
    vector<bool> isLineSep;
    int pos;
    int readLen;

public:
    MyInput(istream& is) : input(is), buffer(1024 * 8), str(500 * 8 * 2), isDigit(256, false), isSpace(256, false), isLineSep(256, false), pos(0), readLen(0) {
        for (int i = 0; i < 10; ++i) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;

        isSpace[' '] = true;
        isSpace['\r'] = true;
        isSpace['\n'] = true;
        isSpace['\t'] = true;

        isLineSep['\r'] = true;
        isLineSep['\n'] = true;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = input.read(buffer.data(), static_cast<streamsize>(buffer.size())).gcount();
            if (readLen <= 0) {
                throw runtime_error("EOF encountered.");
            }
        }
        return buffer[pos++];
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return static_cast<char>(c);
            }
        }
    }

    int reads(int len, const vector<bool>& accept) {
        while (true) {
            int c = read();
            if (accept[c]) {
                break;
            }
            if (len >= static_cast<int>(str.size())) {
                str.resize(len * 3 / 2);
            }
            str[len++] = static_cast<char>(c);
        }
        return len;
    }

    int nextInt() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        int ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; ++i) {
            ret = ret * 10 + (str[i] - '0');
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    string nextString() {
        int len = 0;
        len = reads(len, isSpace);
        return string(str.data(), len);
    }
};

class Solver {
private:
    MyInput& in;
    ostream& out;

public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
        for (int i = 0; i < H; ++i) {
            string s = in.nextString();
            for (int j = 0; j < W; ++j) {
                C[i + 1][j + 1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W; ++j) {
                if (C[i][j] == '#' &&
                    C[i - 1][j] != '#' &&
                    C[i + 1][j] != '#' &&
                    C[i][j - 1] != '#' &&
                    C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
