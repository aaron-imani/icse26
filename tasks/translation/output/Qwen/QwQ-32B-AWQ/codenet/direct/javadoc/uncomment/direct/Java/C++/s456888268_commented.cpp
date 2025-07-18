#include <iostream>
#include <string>
using namespace std;

char inbuf[1024];
int lenbuf = 0, ptrbuf = 0;

int readByte() {
    if (lenbuf == -1) return -1;
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        lenbuf = fread(inbuf, 1, 1024, stdin);
        if (lenbuf <= 0) return -1;
    }
    return inbuf[ptrbuf++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while( (b = readByte()) != -1 && isSpaceChar(b) );
    return b;
}

string ns() {
    int b = skip();
    string s;
    while( b != -1 && !isSpaceChar(b) ) {
        s += (char)b;
        b = readByte();
    }
    return s;
}

void solve() {
    string tmp = ns();
    int n = tmp.size();
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; ++i) {
        char c = tmp[i];
        if(c == 'S') {
            cnt++;
        } else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
