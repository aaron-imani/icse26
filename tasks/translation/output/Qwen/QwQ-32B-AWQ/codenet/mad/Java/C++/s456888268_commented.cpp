#include <iostream>
#include <string>
using namespace std;

const long long mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = INT_MAX / 2;
const long long linf = LLONG_MAX / 3;
const double dinf = DBL_MAX / 3;
const double eps = 1e-10;
const double pi = acos(-1.0);

const int BUFFER_SIZE = 1024;
static char inbuf[BUFFER_SIZE];
static int lenbuf = 0, ptrbuf = 0;

int readByte() {
    if (lenbuf == -1) return -1;
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        lenbuf = fread(inbuf, sizeof(char), BUFFER_SIZE, stdin);
        if (lenbuf <= 0) return -1;
    }
    return inbuf[ptrbuf++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b));
    return b;
}

string ns() {
    int b = skip();
    string s;
    while (!isSpaceChar(b)) {
        s += (char)b;
        b = readByte();
    }
    return s;
}

int ni() {
    int num = 0, b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

long long nl() {
    long long num = 0;
    int b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

void solve() {
    string s = ns();
    int n = s.length();
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    solve();
    return 0;
} // End of Code
