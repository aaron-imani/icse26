#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    char buffer[1024];
    int bufpos;
    int buflen;
} FastReader;

void initFastReader(FastReader *fr) {
    fr->bufpos = 0;
    fr->buflen = 0;
}

int readChar(FastReader *fr) {
    if (fr->bufpos >= fr->buflen) {
        fr->buflen = fread(fr->buffer, 1, sizeof(fr->buffer), stdin);
        fr->bufpos = 0;
        if (fr->buflen <= 0) return EOF;
    }
    return fr->buffer[fr->bufpos++];
}

int nextInt(FastReader *fr) {
    int c, val = 0, neg = 0;
    while ((c = readChar(fr)) != '-' && (c < '0' || c > '9')) if (c == EOF) return 0;
    if (c == '-') neg = 1, c = readChar(fr);
    do {
        val = (val << 3) + (val << 1) + (c - '0');
    } while ((c = readChar(fr)) >= '0' && c <= '9');
    return neg ? -val : val;
}

char nextString[FastReader][1024];

char* next(FastReader *fr) {
    int c, pos = 0;
    while ((c = readChar(fr)) <= ' ') if (c == EOF) return NULL;
    do {
        nextString[fr][pos++] = c;
    } while ((c = readChar(fr)) > ' ');
    nextString[fr][pos] = '\0';
    return nextString[fr];
}

int main() {
    FastReader fr;
    initFastReader(&fr);

    int n = nextInt(&fr);
    int m = nextInt(&fr);

    int penal[MAX_N + 1];
    bool solved[MAX_N + 1];
    memset(penal, 0, sizeof(penal));
    memset(solved, false, sizeof(solved));

    for (int i = 0; i < m; i++) {
        int num = nextInt(&fr);
        char *str = next(&fr);
        if (str[0] == 'A') {
            solved[num] = true;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0;
    int num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    return 0;
}
// End of Code
