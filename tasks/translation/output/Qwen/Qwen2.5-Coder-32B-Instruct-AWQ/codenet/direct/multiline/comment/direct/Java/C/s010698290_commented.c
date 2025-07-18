#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000

typedef struct {
    char buffer[1024];
    int buffer_pos;
    int buffer_len;
} FastReader;

void init_fast_reader(FastReader *fr) {
    fr->buffer_pos = 0;
    fr->buffer_len = 0;
}

int read_char(FastReader *fr) {
    if (fr->buffer_pos >= fr->buffer_len) {
        fr->buffer_len = fread(fr->buffer, 1, sizeof(fr->buffer), stdin);
        fr->buffer_pos = 0;
        if (fr->buffer_len == 0) return EOF;
    }
    return fr->buffer[fr->buffer_pos++];
}

int next_int(FastReader *fr) {
    int c, val = 0, neg = 0;
    while ((c = read_char(fr)) != '-' && (c < '0' || c > '9')) if (c == EOF) return 0;
    if (c == '-') neg = 1, c = read_char(fr);
    do {
        val = (val << 3) + (val << 1) + (c - '0');
    } while ((c = read_char(fr)) >= '0' && c <= '9');
    return neg ? -val : val;
}

char next_string[FastReader][1024];

char* next(FastReader *fr) {
    int c, pos = 0;
    while ((c = read_char(fr)) <= ' ') if (c == EOF) return NULL;
    do {
        next_string[fr][pos++] = c;
    } while ((c = read_char(fr)) > ' ');
    next_string[fr][pos] = '\0';
    return next_string[fr];
}

int main() {
    FastReader fr;
    init_fast_reader(&fr);

    int n = next_int(&fr);
    int m = next_int(&fr);

    int penal[MAX_N + 1];
    bool solved[MAX_N + 1];
    memset(penal, 0, sizeof(penal));
    memset(solved, false, sizeof(solved));

    for (int i = 0; i < m; i++) {
        int num = next_int(&fr);
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
