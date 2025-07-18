#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007
#define INF INT_MAX / 2
#define LINF LONG_MAX / 3
#define DINF 1e10
#define EPS 1e-10
#define PI 3.14159265358979323846

char inbuf[1024];
int lenbuf = 0, ptrbuf = 0;

int readByte() {
    if (lenbuf == -1) return -1;
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        lenbuf = fread(inbuf, 1, sizeof(inbuf), stdin);
        if (lenbuf <= 0) return -1;
    }
    return inbuf[ptrbuf++];
}

int isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b));
    return b;
}

char* ns() {
    int b = skip();
    static char buf[1024];
    int p = 0;
    while (!(isSpaceChar(b))) {
        buf[p++] = (char) b;
        b = readByte();
    }
    buf[p] = '\0';
    return buf;
}

void solve() {
    char* tmp = ns();
    int n = strlen(tmp);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(tmp[i] == 'S') {
            cnt++;
        } else {
            if(cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", n - 2 * ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
