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
            fprintf(stderr, "End of file reached unexpectedly.\n");
            exit(EXIT_FAILURE);
        }
    }
    return input->buffer[input->pos++];
}

int nextInt(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (c == ' ' || c == '\r' || c == '\n' || c == '\t') {
        c = read(input);
    }
    str[len++] = c;
    while (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
        c = read(input);
        str[len++] = c;
    }
    str[len] = '\0';
    return atoi(str);
}

long nextLong(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (c == ' ' || c == '\r' || c == '\n' || c == '\t') {
        c = read(input);
    }
    str[len++] = c;
    while (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
        c = read(input);
        str[len++] = c;
    }
    str[len] = '\0';
    return atol(str);
}

double nextDouble(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (c == ' ' || c == '\r' || c == '\n' || c == '\t') {
        c = read(input);
    }
    str[len++] = c;
    while (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
        c = read(input);
        str[len++] = c;
    }
    str[len] = '\0';
    return atof(str);
}

char* nextString(MyInput* input) {
    int len = 0;
    int c = read(input);
    while (c == ' ' || c == '\r' || c == '\n' || c == '\t') {
        c = read(input);
    }
    str[len++] = c;
    while (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
        c = read(input);
        str[len++] = c;
    }
    str[len] = '\0';
    return strdup(str);
}

void prn(int i) {
    printf("%d\n", i);
}

void prn(long i) {
    printf("%ld\n", i);
}

void prn(double d) {
    printf("%lf\n", d);
}

void prn(char* s) {
    printf("%s\n", s);
}

void prr(char* s) {
    printf("%s", s);
}

int main() {
    FILE* inputStream = stdin;
    FILE* outputStream = stdout;
    MyInput* in = createMyInput(inputStream);
    int H = nextInt(in);
    int W = nextInt(in);
    char C[H+2][W+2];
    char c[W+2];
    for (int i = 0; i < H; i++) {
        strcpy(c, nextString(in));
        for (int j = 0; j < W; j++) {
            C[i+1][j+1] = c[j];
        }
    }
    if (H == 1 && W == 1) {
        prn("No");
        return 0;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' 
                && C[i][j-1] != '#' && C[i][j+1] != '#') {
                prn("No");
                return 0;
            }
        }
    }
    prn("Yes");
    return 0;
}

// End of Code
