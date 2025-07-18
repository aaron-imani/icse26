#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    int buffer[BUFFER_SIZE];
    int index;
    int length;
} Scanner;

int isPrintableChar(int c) {
    return '!' <= c && c <= '~';
}

int isDigit(int c) {
    return '0' <= c && c <= '9';
}

int hasNextByte(Scanner *sc) {
    if (sc->index < sc->length) {
        return 1;
    } else {
        sc->length = fread(sc->buffer, sizeof(int), BUFFER_SIZE, stdin);
        sc->index = 0;
        return sc->length > 0;
    }
}

int hasNext(Scanner *sc) {
    while (hasNextByte(sc) && !isPrintableChar(sc->buffer[sc->index])) {
        sc->index++;
    }
    return hasNextByte(sc);
}

int readByte(Scanner *sc) {
    return hasNextByte(sc) ? sc->buffer[sc->index++] : -1;
}

char* next(Scanner *sc) {
    if (!hasNext(sc)) {
        fprintf(stderr, "no input\n");
        exit(1);
    }
    static char sb[BUFFER_SIZE];
    int b = readByte(sc);
    int i = 0;
    while (isPrintableChar(b)) {
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
    int minus = 0;
    int b = readByte(sc);
    if (b == '-') {
        minus = 1;
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
                if (c[i][j] + min[j] < min[i]) {
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
