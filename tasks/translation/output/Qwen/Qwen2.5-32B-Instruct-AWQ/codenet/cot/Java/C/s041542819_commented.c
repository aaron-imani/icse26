#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long *s;
    long *t;
    int a;
    int b;
} DLazyFaith;

void solve(DLazyFaith *solver, int testNumber, long *in, long *out) {
    int a = in[0], b = in[1], q = in[2];
    solver->s = (long *)malloc((a + 2) * sizeof(long));
    solver->t = (long *)malloc((b + 2) * sizeof(long));
    solver->s[0] = solver->t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        solver->s[i + 1] = in[3 + i];
    }
    for (int i = 0; i < b; i++) {
        solver->t[i + 1] = in[3 + a + i];
    }
    solver->s[a + 1] = solver->t[b + 1] = 20000000000L;
    int index = 3 + a + b;
    for (int i = 0; i < q; i++) {
        long x = in[index++];
        long sl = x - solver->s[(x + 1 > solver->s[0] ? 0 : 1)];
        long tl = x - solver->t[(x + 1 > solver->t[0] ? 0 : 1)];
        long sr = solver->s[(x > solver->s[0] ? 1 : 0)] - x;
        long tr = solver->t[(x > solver->t[0] ? 1 : 0)] - x;
        out[i] = (sl > tl ? sl : tl) < (sr > tr ? sr : tr) ? (sl > tl ? sl : tl) : (sr > tr ? sr : tr);
        out[i] = out[i] < (2 * sl + tr) ? out[i] : (2 * sl + tr);
        out[i] = out[i] < (2 * tl + sr) ? out[i] : (2 * tl + sr);
        out[i] = out[i] < (sl + 2 * tr) ? out[i] : (sl + 2 * tr);
        out[i] = out[i] < (tl + 2 * sr) ? out[i] : (tl + 2 * sr);
    }
}

int main() {
    long *in = (long *)malloc(100000 * sizeof(long));
    long *out = (long *)malloc(100000 * sizeof(long));
    DLazyFaith solver;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &in[i]);
    }
    solve(&solver, 1, in, out);
    for (int i = 0; i < n; i++) {
        printf("%ld\n", out[i]);
    }
    free(in);
    free(out);
    free(solver.s);
    free(solver.t);
    return 0;
}
// End of Code
