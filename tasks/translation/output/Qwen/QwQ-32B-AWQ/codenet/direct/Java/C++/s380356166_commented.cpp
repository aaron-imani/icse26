#include <iostream>
#include <vector>
#include <array>
using namespace std;

class MyInput {
private:
    static const int BUFFER_SIZE = 1024 * 8;
    static const int STR_SIZE = 500 * 8 * 2;

    static char buffer[BUFFER_SIZE];
    static int pos;
    static int readLen;
    static char str[STR_SIZE];
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];

    istream& in;

public:
    MyInput(istream& is) : in(is) {}

    int read() {
        if (pos >= readLen) {
            pos = 0;
            in.read(buffer, BUFFER_SIZE);
            readLen = in.gcount();
            if (readLen <= 0) {
                throw runtime_error("End of file reached unexpectedly");
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

private:
    int reads(int len, bool accept[]) {
        while (true) {
            int c = read();
            if (accept[c]) {
                break;
            }
            if (len >= STR_SIZE) {
                throw runtime_error("Input too long");
            }
            str[len++] = static_cast<char>(c);
        }
        return len;
    }
};

char MyInput::buffer[MyInput::BUFFER_SIZE];
int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::str[MyInput::STR_SIZE];
bool MyInput::isDigit[256] = {false};
bool MyInput::isSpace[256] = {false};
bool MyInput::isLineSep[256] = {false};

void initializeStaticArrays() {
    for (int i = 0; i < 256; ++i) {
        MyInput::isDigit[i] = false;
        MyInput::isSpace[i] = false;
        MyInput::isLineSep[i] = false;
    }
    for (int i = 0; i < 10; ++i) {
        MyInput::isDigit['0' + i] = true;
    }
    MyInput::isDigit['-'] = true;
    MyInput::isSpace[' '] = true;
    MyInput::isSpace['\r'] = true;
    MyInput::isSpace['\n'] = true;
    MyInput::isSpace['\t'] = true;
    MyInput::isLineSep['\r'] = true;
    MyInput::isLineSep['\n'] = true;
}

int main() {
    initializeStaticArrays();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MyInput in(cin);
    int K = in.nextInt();
    int S = in.nextInt();

    int ans = 0;
    for (int x = 0; x <= K; ++x) {
        for (int y = 0; y <= K; ++y) {
            int wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
// End of Code
