#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **a;
    long *powP;
    long *powQ;
    long **hashRow;
    long **hashCol;
} TaskB;

void solve(TaskB *solver, int n, char *input[], FILE *out) {
    solver->powP = (long *)malloc((n + 1) * sizeof(long));
    solver->powQ = (long *)malloc((n + 1) * sizeof(long));
    solver->powP[0] = solver->powQ[0] = 1;
    long P = 37, Q = 47;
    for (int i = 1; i <= n; i++) {
        solver->powP[i] = solver->powP[i - 1] * P;
        solver->powQ[i] = solver->powQ[i - 1] * Q;
    }
    solver->a = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        solver->a[i] = input[i];
    }

    solver->hashRow = (long **)malloc(n * sizeof(long *));
    solver->hashCol = (long **)malloc(n * sizeof(long *));
    for (int i = 0; i < n; i++) {
        solver->hashRow[i] = (long *)malloc(n * sizeof(long));
        solver->hashCol[i] = (long *)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                solver->hashRow[i][k] += solver->a[i][j] * solver->powP[(j - k + n) % n];
                solver->hashCol[j][k] += solver->a[i][j] * solver->powP[(i - k + n) % n];
            }
        }
    }

    int ans = 0;
    for (int A = 0; A < n; A++) {
        for (int B = 0; B < n; B++) {
            int ok = 1;
            for (int i = 0; i < n; i++) {
                ok &= solver->hashRow[(i + A) % n][B] == solver->hashCol[(i + B) % n][A];
            }
            ans += ok ? 1 : 0;
        }
    }
    fprintf(out, "%d\n", ans);
}

char *next(FILE *in) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    if ((read = getline(&line, &len, in)) == -1) {
        return NULL;
    }
    char *token = strtok(line, " ");
    return token;
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    int n = atoi(next(in));
    char **input = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        input[i] = next(in);
    }
    TaskB solver;
    solve(&solver, n, input, out);
    return 0;
}
// End of Code
