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
            fprintf(stderr, "End of file reached.\n");
            exit(EXIT_FAILURE);
        }
    }
    return input->buffer[input->pos++];
}

int nextInt(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (!isdigit(c) && c != '-') {
        c = read(input);
    }
    str[len++] = c;
    while (isdigit(c = read(input))) {
        str[len++] = c;
    }
    str[len] = '\0';
    return atoi(str);
}

long nextLong(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (!isdigit(c) && c != '-') {
        c = read(input);
    }
    str[len++] = c;
    while (isdigit(c = read(input))) {
        str[len++] = c;
    }
    str[len] = '\0';
    return atol(str);
}

double nextDouble(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (!isdigit(c) && c != '-' && c != '.') {
        c = read(input);
    }
    str[len++] = c;
    while (isdigit(c = read(input)) || c == '.') {
        str[len++] = c;
    }
    str[len] = '\0';
    return atof(str);
}

char* nextString(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (isspace(c)) {
        c = read(input);
    }
    str[len++] = c;
    while (!isspace(c = read(input))) {
        str[len++] = c;
    }
    str[len] = '\0';
    return strdup(str);
}

void solve(MyInput* input, FILE* output) {
    int H = nextInt(input);
    int W = nextInt(input);
    char C[H + 2][W + 2];
    char c[W + 2];
    for (int i = 0; i < H; i++) {
        strcpy(c, nextString(input));
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = c[j];
        }
    }
    if (H == 1 && W == 1) {
        fprintf(output, "No\n");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                fprintf(output, "No\n");
                return;
            }
        }
    }
    fprintf(output, "Yes\n");
}

int main() {
    MyInput* input = createMyInput(stdin);
    FILE* output = stdout;
    solve(input, output);
    free(input);
    fclose(output);
    return 0;
}
// End of Code
