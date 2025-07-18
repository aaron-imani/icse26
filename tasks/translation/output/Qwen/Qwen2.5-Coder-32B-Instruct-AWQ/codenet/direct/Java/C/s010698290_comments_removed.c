#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    char buffer[1024];
    int buffer_pos;
    int buffer_len;
} FastReader;

void init_fast_reader(FastReader *fr) {
    fr->buffer_pos = 0;
    fr->buffer_len = 0;
}

char next_char(FastReader *fr) {
    if (fr->buffer_pos >= fr->buffer_len) {
        fr->buffer_len = fread(fr->buffer, 1, sizeof(fr->buffer), stdin);
        fr->buffer_pos = 0;
        if (fr->buffer_len == 0) return EOF;
    }
    return fr->buffer[fr->buffer_pos++];
}

int next_int(FastReader *fr) {
    int num = 0;
    char c;
    while ((c = next_char(fr)) < '0' || c > '9');
    do {
        num = num * 10 + c - '0';
    } while ((c = next_char(fr)) >= '0' && c <= '9');
    return num;
}

char next_string(FastReader *fr, char *str) {
    char c;
    while ((c = next_char(fr)) == ' ' || c == '\n');
    int i = 0;
    do {
        str[i++] = c;
    } while ((c = next_char(fr)) != ' ' && c != '\n' && c != EOF);
    str[i] = '\0';
    return c;
}

int main() {
    FastReader fr;
    init_fast_reader(&fr);

    int n = next_int(&fr);
    int m = next_int(&fr);

    int penal[MAX + 1];
    bool solved[MAX + 1];
    for (int i = 0; i <= n; i++) {
        penal[i] = 0;
        solved[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int num = next_int(&fr);
        char str[10];
        next_string(&fr, str);
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
