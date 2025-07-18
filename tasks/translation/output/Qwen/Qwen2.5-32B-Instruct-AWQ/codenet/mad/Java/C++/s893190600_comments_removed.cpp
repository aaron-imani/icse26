#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// MyInput class definition

class MyInput {
private:
    istream& in;
    static int pos;
    static int readLen;
    static char buffer[8192];
    static char str[8192];
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];

public:
    MyInput(istream& is) : in(is) {
        pos = 0;
        readLen = 0;
        for (int i = 0; i < 10; i++) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;
        isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
        isLineSep['\r'] = isLineSep['\n'] = true;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = in.readsome(buffer, sizeof(buffer));
            if (readLen <= 0) {
                throw runtime_error("End of file");
            }
        }
        return buffer[pos++];
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
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    long long nextLong() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        long long ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    double nextDouble() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        double ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        int cnt = 0;
        for (; i < len; i++) {
            if (str[i] == '.') {
                cnt = 10;
                continue;
            }
            if (cnt == 0) {
                ret = ret * 10 + str[i] - '0';
            } else {
                ret = ret + ((double)(str[i] - '0') / cnt);
                cnt *= 10;
            }
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    string nextString() {
        string ret = string(nextDChar()).trim();
        return ret;
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return (char)c;
            }
        }
    }

    int reads(int len, bool* accept) {
        try {
            while (true) {
                int c = read();
                if (accept[c]) {
                    break;
                }
                if (str.length() == len) {
                    char* rep = new char[str.length() * 3 / 2];
                    memcpy(rep, str, str.length());
                    str = rep;
                }
                str[len++] = (char)c;
            }
        } catch (runtime_error& e) {
        }
        return len;
    }

    char* nextDChar() {
        int len = 0;
        len = reads(len, isSpace);
        char* ret = new char[len + 1];
        for (int i = 0; i < len; i++) ret[i] = str[i];
        ret[len] = 0x00;
        return ret;
    }
};

int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::buffer[8192];
char MyInput::str[8192];
bool MyInput::isDigit[256];
bool MyInput::isSpace[256];
bool MyInput::isLineSep[256];

// Solver class definition

class Solver {
private:
    MyInput& in;
    ostream& out;

public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        char C[H + 2][W + 2];
        char c[W];
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
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
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
    ostream& out = cout;
    Solver solver(in, out);
    solver.solve();
    return 0;
}
// End of Code
