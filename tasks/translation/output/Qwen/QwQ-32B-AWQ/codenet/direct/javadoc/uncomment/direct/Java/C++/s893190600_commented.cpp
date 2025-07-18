#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct PP {
    int key, val;
    PP(int k, int v) : key(k), val(v) {}
};

struct PPL {
    long key, val;
    PPL(long k, long v) : key(k), val(v) {}
};

struct PPKEY {
    int key, val;
    PPKEY(int k, int v) : key(k), val(v) {}
    bool operator==(const PPKEY& other) const {
        return key == other.key && val == other.val;
    }
};

namespace std {
    template<>
    struct hash<PPKEY> {
        size_t operator()(const PPKEY& p) const {
            return hash<int>()(p.key) ^ hash<int>()(p.val);
        }
    };
}

class MyInput {
private:
    istream& in_;
    static char buffer[1024 * 8];
    static char str[500 * 8 * 2];
    static int pos;
    static int readLen;
    static bool isDigit[256];
    static bool isSpace[256];
    static bool isLineSep[256];

public:
    MyInput(istream& is) : in_(is) {}
    int read();
    int nextInt();
    long long nextLong();
    double nextDouble();
    string nextString();

    static void initStaticData() {
        for (int i = 0; i < 256; ++i) {
            isDigit[i] = false;
            isSpace[i] = false;
            isLineSep[i] = false;
        }
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
};

char MyInput::buffer[1024 * 8];
char MyInput::str[500 * 8 * 2];
int MyInput::pos = 0;
int MyInput::readLen = 0;
bool MyInput::isDigit[256];
bool MyInput::isSpace[256];
bool MyInput::isLineSep[256];

int MyInput::read() {
    if (pos >= readLen) {
        pos = 0;
        readLen = in_.read(buffer, sizeof(buffer));
        if (readLen <= 0) {
            throw runtime_error("End of file");
        }
    }
    return buffer[pos++];
}

int MyInput::nextInt() {
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

long long MyInput::nextLong() {
    int len = 0;
    str[len++] = nextChar();
    len = reads(len, isSpace);
    int i = 0;
    long long ret = 0;
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

double MyInput::nextDouble() {
    int len = 0;
    str[len++] = nextChar();
    len = reads(len, isSpace);
    int i = 0;
    double ret = 0.0;
    int cnt = 0;
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; ++i) {
        if (str[i] == '.') {
            cnt = 10;
            continue;
        }
        if (cnt == 0) {
            ret = ret * 10 + (str[i] - '0');
        } else {
            ret += static_cast<double>(str[i] - '0') / cnt;
            cnt *= 10;
        }
    }
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

char MyInput::nextChar() {
    int c;
    while (true) {
        c = read();
        if (c == -1) throw runtime_error("End of file");
        if (!isSpace[c]) {
            return static_cast<char>(c);
        }
    }
}

int MyInput::reads(int len, const bool accept[]) {
    try {
        while (true) {
            int c = read();
            if (c == -1) throw runtime_error("End of file");
            if (accept[c]) {
                break;
            }
            if (len >= sizeof(str)) {
                throw runtime_error("Input too long");
            }
            str[len++] = static_cast<char>(c);
        }
    } catch (const exception&) {
    }
    return len;
}

string MyInput::nextString() {
    int len = 0;
    str[len++] = nextChar();
    len = reads(len, isLineSep);
    return string(str, len);
}

class Solver {
private:
    MyInput& in;
    ostream& out;
public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}
    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H+2, vector<char>(W+2, '.'));
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
    MyInput::initStaticData();
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}

// End of Code
