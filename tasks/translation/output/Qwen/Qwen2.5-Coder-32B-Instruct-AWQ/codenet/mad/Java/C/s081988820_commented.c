#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    FILE *in;
    char buffer[BUFFER_SIZE];
    int index;
    int length;
} Scanner;

bool isPrintableChar(char c) {
    return '!' <= c && c <= '~';
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

bool hasNextByte(Scanner *sc) {
    if (sc->index < sc->length) {
        return true;
    } else {
        sc->length = fread(sc->buffer, 1, BUFFER_SIZE, sc->in);
        sc->index = 0;
        return sc->length > 0;
    }
}

bool hasNext(Scanner *sc) {
    while (hasNextByte(sc) && !isPrintableChar(sc->buffer[sc->index])) {
        sc->index++;
    }
    return hasNextByte(sc);
}

int readByte(Scanner *sc) {
    return hasNextByte(sc) ? sc->buffer[sc->index++] : -1;
}

char *next(Scanner *sc) {
    if (!hasNext(sc)) {
        fprintf(stderr, "no input\n");
        exit(1);
    }
    char *sb = (char *)malloc(BUFFER_SIZE);
    if (sb == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }
    int b = readByte(sc);
    int i = 0;
    while (isPrintableChar(b) && i < BUFFER_SIZE - 1) {
        sb[i++] = b;
        b = readByte(sc);
    }
    sb[i] = '\0';
    return sb;
}

long nextLong(Scanner *sc) {
    if (!hasNext(sc)) {
        fprintf(stderr, "no input\n");
        exit(1);
    }
    long value = 0L;
    bool minus = false;
    int b = readByte(sc);
    if (b == '-') {
        minus = true;
        b = readByte(sc);
    }
    while (isPrintableChar(b)) {
        if (isDigit(b)) {
            value = value * 10 + (b - '0');
        }
        b = readByte(sc);
    }
    return minus ? -value : value;
}

int nextInt(Scanner *sc) {
    return (int)nextLong(sc);
}

void solve() {
    Scanner sc;
    sc.in = stdin;
    sc.index = 0;
    sc.length = 0;

    int H = nextInt(&sc);
    int W = nextInt(&sc);
    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            c[i][j] = nextInt(&sc);
        }
    }
    int min[10];
    for (int i = 0; i < 10; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (min[i] > c[i][j] + min[j]) {
                    min[i] = c[i][j] + min[j];
                }
            }
        }
    }
    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A = nextInt(&sc);
            if (A >= 0) {
                ans += min[A];
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}
// End of Code
