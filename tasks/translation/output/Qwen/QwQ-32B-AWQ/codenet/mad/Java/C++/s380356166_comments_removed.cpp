#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
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

public:
    MyInput() {
        static bool initialized = false;
        if (!initialized) {
            initialize();
            initialized = true;
        }
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = fread(buffer, 1, sizeof(buffer), stdin);
            if (readLen <= 0) throw runtime_error("EOF");
        }
        return buffer[pos++];
    }

    int nextInt() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0, ret = 0;
        if (str[0] == '-') i = 1;
        for (; i < len; i++) ret = ret * 10 + (str[i] - '0');
        if (str[0] == '-') ret = -ret;
        return ret;
    }

    char nextChar() {
        while (true) {
            int c = read();
            if (!isSpace[c]) return c;
        }
    }

    int reads(int len, const bool accept[]) {
        while (true) {
            int c = read();
            if (accept[c]) break;
            if (len >= sizeof(str)) break; // handle overflow
            str[len++] = c;
        }
        return len;
    }

private:
    static void initialize() {
        fill(isDigit, isDigit+256, false);
        fill(isSpace, isSpace+256, false);
        fill(isLineSep, isLineSep+256, false);
        for (int i = 0; i < 10; i++) isDigit['0' + i] = true;
        isDigit['-'] = true;
        isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
        isLineSep['\r'] = isLineSep['\n'] = true;
    }
};

int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::buffer[8192];
char MyInput::str[8000];
bool MyInput::isDigit[256];
bool MyInput::isSpace[256];
bool MyInput::isLineSep[256];

class Solver {
public:
    void solve(int testNumber, MyInput& in, ostream& out) {
        int K = in.nextInt(), S = in.nextInt();
        int ans = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - x - y;
                if (z >= 0 && z <= K) ans++;
            }
        }
        out << ans << '\n';
    }
};

int main() {
    MyInput in;
    Solver().solve(1, in, cout);
    return 0;
}
// End of Code
