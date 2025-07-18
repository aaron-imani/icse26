#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int nextInt(FILE *in) {
    int c, n, sign;
    while ((c = getc(in)) && isspace(c));
    sign = (c == '-') ? -1 : 1;
    if (c != '-' && c != '+') ungetc(c, in);
    if (c == '-' || c == '+') c = getc(in);
    for (n = 0; isdigit(c); c = getc(in)) n = n * 10 + c - '0';
    return sign * n;
}

void solve(FILE *in, FILE *out) {
    int ans = 0;
    int K = nextInt(in);
    int S = nextInt(in);
    int wk = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            wk = S - x - y;
            if (wk >= 0 && wk <= K) {
                ans++;
            }
        }
    }
    fprintf(out, "%d\n", ans);
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    solve(in, out);
    fclose(out);
    return 0;
}
// End of Code
