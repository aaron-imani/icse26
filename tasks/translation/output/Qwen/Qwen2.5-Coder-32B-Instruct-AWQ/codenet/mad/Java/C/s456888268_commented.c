#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MOD 1000000007
#define MAX 1024

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int inf = 1073741823;
long long linf = 6372812765430547558LL;
double dinf = 1.7976931348623157E308;
double eps = 1e-10;
double pi = 3.14159265358979323846;

char inbuf[MAX];
int lenbuf = 0, ptrbuf = 0;

void solve() {
    char tmp[MAX];
    scanf("%s", tmp);
    int n = strlen(tmp);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    printf("%d\n", n - 2 * ans);
}

int readByte() {
    if (lenbuf == -1) return -1;
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        lenbuf = fread(inbuf, 1, MAX, stdin);
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
    char* sb = (char*) malloc(MAX * sizeof(char));
    int p = 0;
    while (!(isSpaceChar(b))) {
        sb[p++] = (char) b;
        b = readByte();
    }
    sb[p] = '\0';
    return sb;
}

int ni() {
    int num = 0, b;
    int minus = 0;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = 1;
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

int main() {
    solve();
    return 0;
}
// End of Code
