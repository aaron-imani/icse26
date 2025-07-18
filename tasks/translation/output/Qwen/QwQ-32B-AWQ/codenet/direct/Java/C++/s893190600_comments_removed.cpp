#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct MyInput {
    static const int BUFFER_SIZE = 1024 * 8;
    static const int STR_SIZE = 500 * 8 * 2;
    static int pos;
    static int readLen;
    static char buffer[BUFFER_SIZE];
    static char str[STR_SIZE];
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];

    static int read() {
        if (pos >= readLen) {
            pos = 0;
            readLen = fread(buffer, 1, BUFFER_SIZE, stdin);
            if (readLen <= 0) {
                throw runtime_error("EOF");
            }
        }
        return buffer[pos++];
    }

    static char nextChar() {
        int c;
        do {
            c = read();
        } while (isSpace[c]);
        return (char)c;
    }

    static int nextInt() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = read();
            if (isSpace[c]) break;
            if (len >= STR_SIZE - 1) {
                throw runtime_error("String too long");
            }
            str[len++] = (char)c;
        }
        str[len] = '\0';
        int sign = 1;
        int i = 0;
        if (str[0] == '-') {
            sign = -1;
            i = 1;
        }
        int ret = 0;
        for (; i < len; i++) {
            ret = ret * 10 + (str[i] - '0');
        }
        return ret * sign;
    }

    static string nextString() {
        int len = 0;
        char c = nextChar();
        str[len++] = c;
        while (true) {
            c = read();
            if (isSpace[c]) break;
            if (len >= STR_SIZE - 1) {
                throw runtime_error("String too long");
            }
            str[len++] = (char)c;
        }
        str[len] = '\0';
        return string(str, len);
    }
};

// Static member definitions
int MyInput::pos = 0;
int MyInput::readLen = 0;
char MyInput::buffer[MyInput::BUFFER_SIZE];
char MyInput::str[MyInput::STR_SIZE];
bool MyInput::isDigit[256];
bool MyInput::isSpace[256];
bool MyInput::isLineSep[256];

void initMyInput() {
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
    initMyInput();

    int H = MyInput::nextInt();
    int W = MyInput::nextInt();

    vector<vector<char>> C(H + 2, vector<char>(W + 2, ' '));

    for (int i = 0; i < H; ++i) {
        string s = MyInput::nextString();
        for (int j = 0; j < W; ++j) {
            C[i + 1][j + 1] = s[j];
        }
    }

    if (H == 1 && W == 1) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (C[i][j] == '#') {
                bool hasAdjacent = false;
                if (C[i - 1][j] == '#') hasAdjacent = true;
                if (C[i + 1][j] == '#') hasAdjacent = true;
                if (C[i][j - 1] == '#') hasAdjacent = true;
                if (C[i][j + 1] == '#') hasAdjacent = true;
                if (!hasAdjacent) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}

// End of Code
