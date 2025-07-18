#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 8

typedef struct {
    char buffer[MAX_SIZE];
    int pos;
    int readLen;
} MyInput;

MyInput* createMyInput() {
    MyInput* input = (MyInput*)malloc(sizeof(MyInput));
    input->pos = 0;
    input->readLen = 0;
    return input;
}

int read(MyInput* input) {
    if (input->pos >= input->readLen) {
        input->pos = 0;
        input->readLen = fread(input->buffer, 1, MAX_SIZE, stdin);
        if (input->readLen <= 0) {
            return -1;
        }
    }
    return input->buffer[input->pos++];
}

int nextInt(MyInput* input) {
    int len = 0;
    int c = read(input);
    input->buffer[len++] = c;
    while (c != EOF && !isspace(c)) {
        c = read(input);
        input->buffer[len++] = c;
    }
    input->buffer[len] = '\0';
    return atoi(input->buffer);
}

long nextLong(MyInput* input) {
    int len = 0;
    int c = read(input);
    input->buffer[len++] = c;
    while (c != EOF && !isspace(c)) {
        c = read(input);
        input->buffer[len++] = c;
    }
    input->buffer[len] = '\0';
    return atol(input->buffer);
}

double nextDouble(MyInput* input) {
    int len = 0;
    int c = read(input);
    input->buffer[len++] = c;
    while (c != EOF && !isspace(c)) {
        c = read(input);
        input->buffer[len++] = c;
    }
    input->buffer[len] = '\0';
    return atof(input->buffer);
}

char* nextString(MyInput* input) {
    int len = 0;
    int c = read(input);
    input->buffer[len++] = c;
    while (c != EOF && !isspace(c)) {
        c = read(input);
        input->buffer[len++] = c;
    }
    input->buffer[len] = '\0';
    return strdup(input->buffer);
}

void prn(int i) {
    printf("%d\n", i);
}

void prn(long i) {
    printf("%ld\n", i);
}

void prn(double d) {
    printf("%f\n", d);
}

void prn(char* s) {
    printf("%s\n", s);
}

void prr(char* s) {
    printf("%s", s);
}

void solve(MyInput* input) {
    int H = nextInt(input);
    int W = nextInt(input);
    char C[H+2][W+2];
    char c[W+2];
    for (int i = 0; i < H; i++) {
        strcpy(c, nextString(input));
        for (int j = 0; j < W; j++) {
            C[i+1][j+1] = c[j];
        }
    }
    if (H == 1 && W == 1) {
        prn("No");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' 
                && C[i][j-1] != '#' && C[i][j+1] != '#') {
                prn("No");
                return;
            }
        }
    }
    prn("Yes");
}

int main() {
    MyInput* input = createMyInput();
    solve(input);
    free(input);
    return 0;
}
// End of Code
