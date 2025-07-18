#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

static int read() {
    static char buffer[8192];
    static int pos = 0, read_len = 0;
    if (pos >= read_len) {
        pos = 0;
        read_len = fread(buffer, 1, sizeof(buffer), stdin);
        if (read_len <= 0) {
            exit(EXIT_FAILURE);
        }
    }
    return buffer[pos++];
}

static int next_int() {
    int len = 0;
    char str[4096];
    str[len++] = read();
    while (!isspace(read())) {
        str[len++] = read();
    }
    str[len] = '\0';
    return atoi(str);
}

static long next_long() {
    int len = 0;
    char str[4096];
    str[len++] = read();
    while (!isspace(read())) {
        str[len++] = read();
    }
    str[len] = '\0';
    return atol(str);
}

static char* next_string() {
    int len = 0;
    char str[4096];
    str[len++] = read();
    while (!isspace(read())) {
        str[len++] = read();
    }
    str[len] = '\0';
    return strdup(str);
}

static char next_char() {
    while (1) {
        int c = read();
        if (!isspace(c)) {
            return (char)c;
        }
    }
}

void solve(int test_number, FILE* input, FILE* output) {
    int ans = 0;
    int K = next_int();
    int S = next_int();
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    fprintf(output, "%d\n", ans);
}

int main() {
    FILE* input = stdin;
    FILE* output = stdout;
    solve(1, input, output);
    fclose(output);
    return 0;
}

// End of Code
