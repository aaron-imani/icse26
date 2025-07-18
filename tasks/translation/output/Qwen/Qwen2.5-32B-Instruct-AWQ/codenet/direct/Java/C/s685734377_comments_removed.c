#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char **a;
    long *powP;
    long *powQ;
    long **hashRow;
    long **hashCol;
} TaskB;

void solve(TaskB *solver, int testNumber) {
    int n;
    scanf("%d", &n);
    solver->a = (char **)malloc(n * sizeof(char *));
    solver->powP = (long *)malloc((n + 1) * sizeof(long));
    solver->powQ = (long *)malloc((n + 1) * sizeof(long));
    solver->hashRow = (long **)malloc(n * sizeof(long *));
    solver->hashCol = (long **)malloc(n * sizeof(long *));
    
    for (int i = 0; i < n; i++) {
        solver->a[i] = (char *)malloc(n * sizeof(char));
        solver->hashRow[i] = (long *)malloc(n * sizeof(long));
        solver->hashCol[i] = (long *)malloc(n * sizeof(long));
    }
    
    long P = 37, Q = 47;
    solver->powP[0] = solver->powQ[0] = 1;
    for (int i = 1; i <= n; i++) {
        solver->powP[i] = solver->powP[i - 1] * P;
        solver->powQ[i] = solver->powQ[i - 1] * Q;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%s", solver->a[i]);
    }
    
    for (int i = 0; i < n; i++) {
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
                if (solver->hashRow[(i + A) % n][B] != solver->hashCol[(i + B) % n][A]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    printf("%d\n", ans);
    
    for (int i = 0; i < n; i++) {
        free(solver->a[i]);
        free(solver->hashRow[i]);
        free(solver->hashCol[i]);
    }
    free(solver->a);
    free(solver->powP);
    free(solver->powQ);
    free(solver->hashRow);
    free(solver->hashCol);
}

int main() {
    TaskB solver;
    solve(&solver, 1);
    return 0;
}
// End of Code
