#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1024 * 8
#define MAX_STR 500 * 8 * 2

char buffer[MAX];
char str[MAX_STR];
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
        readLen = fread(buffer, sizeof(char), MAX, stdin);
        if (readLen <= 0) {
            exit(0);
        }
    }
    return buffer[pos++];
}

int nextInt() {
    int len = 0;
    str[len++] = read();
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

long nextLong() {
    int len = 0;
    str[len++] = read();
    len = reads(len, isSpace);
    int i = 0;
    long ret = 0L;
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) ret = ret * 10 + str[i] - '0';
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

double nextDouble() {
    int len = 0;
    str[len++] = read();
    len = reads(len, isSpace);
    int i = 0;
    double ret = 0;
    if (str[0] == '-') {
        i = 1;
    }
    int cnt = 0;
    for (; i < len; i++) {
        if (str[i] == '.') {
            cnt = 10;
            continue;
        }
        if (cnt == 0) {
            ret = ret * 10 + str[i] - '0';
        } else {
            ret = ret + ((double)(str[i] - '0') / cnt);
            cnt *= 10;
        }
    }
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

char* nextString() {
    char* ret = (char*)malloc(MAX_STR * sizeof(char));
    strcpy(ret, nextDChar());
    ret[strcspn(ret, "\n")] = 0;
    return ret;
}

char* nextDChar() {
    int len = 0;
    len = reads(len, isSpace);
    char* ret = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) ret[i] = str[i];
    ret[len] = 0x00;
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

int reads(int len, bool* accept) {
    while (true) {
        int c = read();
        if (accept[c]) {
            break;
        }
        if (len == MAX_STR) {
            char* rep = (char*)malloc(MAX_STR * 3 / 2 * sizeof(char));
            memcpy(rep, str, len * sizeof(char));
            free(str);
            str = rep;
        }
        str[len++] = (char)c;
    }
    return len;
}

void prn(char* s) {
    printf("%s\n", s);
}

void prn_int(int i) {
    printf("%d\n", i);
}

void prn_long(long i) {
    printf("%ld\n", i);
}

void prr(char* s) {
    printf("%s", s);
}

int main() {
    init();
    int H = nextInt();
    int W = nextInt();
    char C[H + 2][W + 2];
    memset(C, '.', sizeof(C));
    for (int i = 0; i < H; i++) {
        char* line = nextString();
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = line[j];
        }
        free(line);
    }
    if (H == 1 && W == 1) {
        prn("No");
        return 0;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                prn("No");
                return 0;
            }
        }
    }
    prn("Yes");
    return 0;
}
// End of Code
