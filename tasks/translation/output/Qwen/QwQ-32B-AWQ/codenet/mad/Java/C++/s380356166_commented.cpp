#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyInput {
private:
    static int pos;
    static int readLen;
    static char buffer[8192];
    static char str[8000];
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];
    static bool initialized;

public:
    static void initStatic() {
        if (initialized) return;
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
        initialized = true;
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = fread(buffer, sizeof(char), 8192, stdin);
            if (readLen <= 0) {
                throw runtime_error("End of file");
            }
        }
        return buffer[pos++];
    }

    int nextInt() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        len = reads(len, isSpace);
        int i = 0;
        int ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) {
            ret = ret * 10 + (str[i] - '0');
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    long long nextLong() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        len = reads(len, isSpace);
        int i = 0;
        long long ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) {
            ret = ret * 10 + (str[i] - '0');
        }
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    string nextString() {
        string s = nextDChar();
        s.erase(s.find_last_not_of(" \n\r\t") + 1);
        s.erase(0, s.find_first_not_of(" \n\r\t"));
        return s;
    }

    string nextDChar() {
        int len = 0;
        len = reads(len, isSpace);
        string ret(str, len);
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

    int reads(int len, bool accept[]) {
        while (true) {
            int c = read();
            if (c < 0) {
                throw runtime_error("Unexpected EOF");
            }
            if (accept[c]) {
                break;
            }
            if (len >= 8000) {
                throw runtime_error("String too long");
            }
            str[len++] = (char)c;
        }
        return len;
    }
};

// Static member definitions
int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::buffer[8192];
char MyInput::str[8000];
bool MyInput::isDigit[256] = {false};
bool MyInput::isSpace[256] = {false};
bool MyInput::isLineSep[256] = {false};
bool MyInput::initialized = false;

class Solver {
public:
    void solve(int testNumber, MyInput& in, ostream& out) {
        int ans = 0;
        int K = in.nextInt();
        int S = in.nextInt();
        int wk;
        for (int x = 0; x <= K; ++x) {
            for (int y = 0; y <= K; ++y) {
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
    MyInput::initStatic();
    MyInput in;
    ostream& out = cout;

    Solver solver;
    solver.solve(1, in, out);

    return 0;
}
// End of Code
