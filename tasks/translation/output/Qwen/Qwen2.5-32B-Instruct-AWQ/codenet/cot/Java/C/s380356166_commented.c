#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int K;
    int S;
} Solver;

void solve(Solver *solver, FILE *in, FILE *out) {
    int ans = 0;
    fscanf(in, "%d", &solver->K);
    fscanf(in, "%d", &solver->S);
    int wk = 0;
    for (int x = 0; x <= solver->K; x++) {
        for (int y = 0; y <= solver->K; y++) {
            wk = solver->S - x - y;
            if (wk >= 0 && wk <= solver->K) {
                ans++;
            }
        }
    }
    fprintf(out, "%d\n", ans);
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    Solver solver;
    solve(&solver, in, out);
    return 0;
}
// End of Code
