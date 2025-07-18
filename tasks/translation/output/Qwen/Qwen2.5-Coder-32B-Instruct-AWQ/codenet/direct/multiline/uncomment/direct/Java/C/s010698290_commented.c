#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    char buffer[1024];
    int pos;
    int len;
} FastReader;

void initFastReader(FastReader *fr) {
    fr->pos = 0;
    fr->len = 0;
}

char nextChar(FastReader *fr) {
    if (fr->pos >= fr->len) {
        fr->len = fread(fr->buffer, 1, sizeof(fr->buffer), stdin);
        fr->pos = 0;
        if (fr->len == 0) return EOF;
    }
    return fr->buffer[fr->pos++];
}

int nextInt(FastReader *fr) {
    int num = 0;
    char c;
    while ((c = nextChar(fr)) < '0' || c > '9');
    do {
        num = num * 10 + c - '0';
    } while ((c = nextChar(fr)) >= '0' && c <= '9');
    return num;
}

char nextString[FastReader][100];

char* next(FastReader *fr) {
    char *str = nextString[fr];
    int i = 0;
    char c;
    while ((c = nextChar(fr)) <= ' ');
    do {
        str[i++] = c;
    } while ((c = nextChar(fr)) > ' ');
    str[i] = '\0';
    return str;
}

int main() {
    FastReader fr;
    initFastReader(&fr);

    int n = nextInt(&fr);
    int m = nextInt(&fr);

    int penal[MAX_N + 1] = {0};
    bool solved[MAX_N + 1] = {false};

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
