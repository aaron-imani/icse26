#include <stdio.h>
#include <stdbool.h>

int pos = 0;
int readLen = 0;
char buffer[1024 * 8];
char str[500 * 8 * 2];
bool isDigit[256];
bool isSpace[256];
bool isLineSep[256];

void init_input() {
    for (int i = 0; i < 256; i++) {
        isDigit[i] = false;
        isSpace[i] = false;
        isLineSep[i] = false;
    }
    for (int i = 0; i < 10; i++) {
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

int read() {
    if (pos >= readLen) {
        pos = 0;
        readLen = fread(buffer, 1, sizeof(buffer), stdin);
        if (readLen <= 0) return -1;
    }
    return buffer[pos++];
}

int nextChar() {
    while (true) {
        int c = read();
        if (c == -1) return -1;
        if (!isSpace[c]) return c;
    }
}

int nextInt() {
    int len = 0;
    int c = nextChar();
    if (c == -1) return 0;
    str[len++] = (char)c;
    while (true) {
        c = read();
        if (c == -1 || isSpace[c]) break;
        if (len < sizeof(str)/sizeof(str[0])) str[len++] = (char)c;
    }
    int i = 0, ret = 0;
    if (str[0] == '-') i = 1;
    for (; i < len; i++) {
        if (!isDigit[(unsigned char)str[i]]) break;
        ret = ret * 10 + (str[i] - '0');
    }
    if (str[0] == '-') ret = -ret;
    return ret;
}

int main() {
    init_input();
    int K = nextInt(), S = nextInt();
    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - x - y;
            if (z >= 0 && z <= K) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// End of Code
