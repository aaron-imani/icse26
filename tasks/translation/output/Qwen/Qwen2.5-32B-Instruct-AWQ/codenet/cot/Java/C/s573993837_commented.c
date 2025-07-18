#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int u, v, i;
} Pair;

void solve(FILE *in, FILE *out) {
    int t = 1;
    while (t--) {
        long n = atol(fgets(NULL, 0, in));
        long m = atol(fgets(NULL, 0, in));
        if (n == 0) {
            fprintf(out, "0\n");
            continue;
        }
        if (n == m) {
            fprintf(out, "0\n");
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            fprintf(out, "%ld\n", fmin(m - n, n));
            continue;
        }
        fprintf(out, "%ld\n", fmin(m - n, n));
    }
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    solve(in, out);
    return 0;
}
// End of Code
