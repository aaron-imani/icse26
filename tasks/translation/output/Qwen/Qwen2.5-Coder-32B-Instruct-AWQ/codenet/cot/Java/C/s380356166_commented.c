#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    FILE *in;
    int pos;
    int readLen;
    char buffer[8192];
    char str[4096];
    int isDigit[256];
    int isSpace[256];
    int isLineSep[256];
} MyInput;

void initMyInput(MyInput *input, FILE *is) {
    input->in = is;
    input->pos = 0;
    input->readLen = 0;
    for (int i = 0; i < 10; i++) {
        input->isDigit['0' + i] = 1;
    }
    input->isDigit['-'] = 1;
    input->isSpace[' '] = input->isSpace['\r'] = input->isSpace['\n'] = input->isSpace['\t'] = 1;
    input->isLineSep['\r'] = input->isLineSep['\n'] = 1;
}

int read(MyInput *input) {
    if (input->pos >= input->readLen) {
        input->pos = 0;
        input->readLen = fread(input->buffer, 1, sizeof(input->buffer), input->in);
        if (input->readLen <= 0) {
            exit(EXIT_FAILURE);
        }
    }
    return input->buffer[input->pos++];
}

int nextInt(MyInput *input) {
    int len = 0;
    input->str[len++] = read(input);
    while (input->isSpace[input->str[len - 1]]) {
        input->str[len - 1] = read(input);
    }
    while (!input->isSpace[input->str[len]]) {
        input->str[len++] = read(input);
    }
    int i = 0;
    int ret = 0;
    if (input->str[0] == '-') {
        i = 1;
    }
    for (; i < len - 1; i++) ret = ret * 10 + input->str[i] - '0';
    if (input->str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

void solve(int testNumber, MyInput *in, FILE *out) {
    int ans = 0;
    int K = nextInt(in);
    int S = nextInt(in);
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    fprintf(out, "%d\n", ans);
}

int main() {
    MyInput in;
    initMyInput(&in, stdin);
    FILE *out = stdout;

    solve(1, &in, out);

    fclose(out);
    return 0;
}
// End of Code
