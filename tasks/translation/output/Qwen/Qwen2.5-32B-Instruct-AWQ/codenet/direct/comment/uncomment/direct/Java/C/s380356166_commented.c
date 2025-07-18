#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int nextInt(FILE* in) {
    int c, n, sign;
    while ((c = getc(in)) && isspace(c));
    sign = (c == '-') ? -1 : 1;
    if (c != EOF) n = (c == '-') ? getc(in) : c;
    else return 0;
    while (isdigit(n)) {
        n = n * 10 + (getc(in) - '0');
    }
    return n * sign;
}

void solve(int K, int S, FILE* out) {
    int ans = 0;
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
    FILE* in = stdin;
    FILE* out = stdout;
    int K = nextInt(in);
    int S = nextInt(in);
    solve(K, S, out);
    fclose(out);
    return 0;
}

// End of Code
