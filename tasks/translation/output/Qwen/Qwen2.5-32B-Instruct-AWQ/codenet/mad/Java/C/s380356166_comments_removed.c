#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 8192
#define STR_SIZE 8000

char buffer[BUFFER_SIZE];
char str[STR_SIZE];
bool isDigit[256];
bool isSpace[256];
bool isLineSep[256];
int pos = 0;
int readLen = 0;

void init() {
    for (int i = 0; i < 10; i++) {
        isDigit['0' + i] = true;
    }
    isDigit['-'] = true;
    isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
    isLineSep['\r'] = isLineSep['\n'] = true;
}

int read() {
    if (pos >= readLen) {
        pos = 0;
        readLen = fread(buffer, sizeof(char), BUFFER_SIZE, stdin);
        if (readLen <= 0) {
            return -1;
        }
    }
    return buffer[pos++];
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
    for (; i < len; i++) ret = ret * 10 + str[i] - '0';
    if (str[0] == '-') {
        ret = -ret;
    }
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
        if (c == -1) {
            return len;
        }
        if (accept[c]) {
            break;
        }
        if (len >= STR_SIZE) {
            char *rep = realloc(str, len * 3 / 2);
            if (rep) {
                str = rep;
            }
        }
        str[len++] = (char)c;
    }
    return len;
}

void solve(int K, int S) {
    int ans = 0;
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    init();
    int K = nextInt();
    int S = nextInt();
    solve(K, S);
    return 0;
}
// End of Code
