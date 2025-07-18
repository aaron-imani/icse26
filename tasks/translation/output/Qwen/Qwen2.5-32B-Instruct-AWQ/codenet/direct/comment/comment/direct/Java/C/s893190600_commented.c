#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 8

typedef struct {
    int key;
    int val;
} PP;

typedef struct {
    int key;
    int val1;
    int val2;
} PPP;

typedef struct {
    long key;
    long val;
} PPL;

typedef struct {
    long key;
    long val[2];
} PPDL;

typedef struct {
    char buffer[MAX_SIZE];
    int pos;
    int readLen;
} MyInput;

MyInput* createMyInput(FILE* stream) {
    MyInput* input = (MyInput*)malloc(sizeof(MyInput));
    input->pos = 0;
    input->readLen = fread(input->buffer, sizeof(char), MAX_SIZE, stream);
    return input;
}

int read(MyInput* input) {
    if (input->pos >= input->readLen) {
        input->pos = 0;
        input->readLen = fread(input->buffer, sizeof(char), MAX_SIZE, stdin);
        if (input->readLen <= 0) {
            exit(EXIT_FAILURE);
        }
    }
    return input->buffer[input->pos++];
}

int nextInt(MyInput* input) {
    int len = 0;
    char c = read(input);
    input->buffer[len++] = c;
    while (len < input->readLen && !isspace(input->buffer[len])) {
        input->buffer[len++] = read(input);
    }
    int i = 0;
    int ret = 0;
    if (input->buffer[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) ret = ret * 10 + input->buffer[i] - '0';
    if (input->buffer[0] == '-') {
        ret = -ret;
    }
    return ret;
}

long nextLong(MyInput* input) {
    int len = 0;
    char c = read(input);
    input->buffer[len++] = c;
    while (len < input->readLen && !isspace(input->buffer[len])) {
        input->buffer[len++] = read(input);
    }
    int i = 0;
    long ret = 0;
    if (input->buffer[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) ret = ret * 10 + input->buffer[i] - '0';
    if (input->buffer[0] == '-') {
        ret = -ret;
    }
    return ret;
}

double nextDouble(MyInput* input) {
    int len = 0;
    char c = read(input);
    input->buffer[len++] = c;
    while (len < input->readLen && !isspace(input->buffer[len])) {
        input->buffer[len++] = read(input);
    }
    int i = 0;
    double ret = 0;
    if (input->buffer[0] == '-') {
        i = 1;
    }
    int cnt = 0;
    for (; i < len; i++) {
        if (input->buffer[i] == '.') {
            cnt = 10;
            continue;
        }
        if (cnt == 0) {
            ret = ret * 10 + input->buffer[i] - '0';
        } else {
            ret = ret + ((double)(input->buffer[i] - '0') / cnt);
            cnt *= 10;
        }
    }
    if (input->buffer[0] == '-') {
        ret = -ret;
    }
    return ret;
}

char* nextString(MyInput* input) {
    int len = 0;
    char c = read(input);
    input->buffer[len++] = c;
    while (len < input->readLen && !isspace(input->buffer[len])) {
        input->buffer[len++] = read(input);
    }
    char* ret = (char*)malloc(len + 1);
    strncpy(ret, input->buffer, len);
    ret[len] = '\0';
    return ret;
}

void printString(const char* s) {
    printf("%s\n", s);
}

void printInt(int i) {
    printf("%d\n", i);
}

void printLong(long l) {
    printf("%ld\n", l);
}

void solve(MyInput* input, FILE* output) {
    int H = nextInt(input);
    int W = nextInt(input);
    char C[H + 2][W + 2];
    char c[W + 1];
    for (int i = 0; i < H; i++) {
        strcpy(c, nextString(input));
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = c[j];
        }
    }
    if (H == 1 && W == 1) {
        printString("No");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                printString("No");
                return;
            }
        }
    }
    printString("Yes");
}

int main() {
    MyInput* input = createMyInput(stdin);
    FILE* output = stdout;
    solve(input, output);
    free(input);
    return 0;
}
// End of Code
