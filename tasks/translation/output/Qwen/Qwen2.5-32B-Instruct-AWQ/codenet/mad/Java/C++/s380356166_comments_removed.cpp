#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class MyInput {
private:
    istream& in;
    static int pos;
    static int readLen;
    static char buffer[1024 * 8];
    static char str[500 * 8 * 2];
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];

public:
    MyInput(istream& is) : in(is) {
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

    string nextString() {
        string ret(nextDChar(), nextDChar() + reads(0, isSpace));
        return ret;
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) {
                return static_cast<char>(c);
            }
        }
    }

    char* nextDChar() {
        int len = reads(0, isSpace);
        char* ret = new char[len + 1];
        for (int i = 0; i < len; i++) ret[i] = str[i];
        ret[len] = 0x00;
        return ret;
    }

private:
    int reads(int len, bool accept[]) {
        try {
            while (true) {
                int c = read();
                if (accept[c]) {
                    break;
                }
                if (str[len] == 0) {
                    char* rep = new char[len * 3 / 2];
                    copy(str, str + len, rep);
                    str = rep;
                }
                str[len++] = static_cast<char>(c);
            }
        } catch (runtime_error& e) {
        }
        return len;
    }
};

int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::buffer[1024 * 8];
char MyInput::str[500 * 8 * 2];
bool MyInput::isDigit[256];
bool MyInput::isSpace[256];
bool MyInput::isLineSep[256];

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
