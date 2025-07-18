#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

typedef struct {
    FILE *file;
    char buffer[1024];
    char *bufpos;
    char *bufend;
} FastReader;

void initFastReader(FastReader *fr) {
    fr->file = stdin;
    fr->bufpos = fr->buffer;
    fr->bufend = fr->buffer;
}

char getNextChar(FastReader *fr) {
    if (fr->bufpos == fr->bufend) {
        fr->bufpos = fr->buffer;
        fr->bufend = fr->buffer + fread(fr->buffer, 1, sizeof(fr->buffer), fr->file);
        if (fr->bufpos == fr->bufend) {
            return EOF;
        }
    }
    return *(fr->bufpos++);
}

int nextInt(FastReader *fr) {
    int num = 0;
    char c;
    while ((c = getNextChar(fr)) < '0' || c > '9');
    do {
        num = num * 10 + c - '0';
    } while ((c = getNextChar(fr)) >= '0' && c <= '9');
    return num;
}

char nextString[FastReader][100];

char* next(FastReader *fr) {
    char *str = nextString[fr];
    int i = 0;
    char c;
    while ((c = getNextChar(fr)) <= ' ');
    do {
        str[i++] = c;
    } while ((c = getNextChar(fr)) > ' ');
    str[i] = '\0';
    return str;
}

int main() {
    FastReader fr;
    initFastReader(&fr);

    int n = nextInt(&fr);
    int m = nextInt(&fr);

    int penal[MAX_N + 1];
    int solved[MAX_N + 1];
    memset(penal, 0, sizeof(penal));
    memset(solved, 0, sizeof(solved));

    for (int i = 0; i < m; i++) {
        int num = nextInt(&fr);
        char *str = next(&fr);
        if (str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (solved[num] == 0) {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0;
    int num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (solved[i] == 1) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    return 0;
}
// End of Code
