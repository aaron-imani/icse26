#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int N = get_int();
    int W = get_int();

    int *v = (int*)malloc((N + 1) * sizeof(int));
    int *w = (int*)malloc((N + 1) * sizeof(int));

    for (int i = 1; i <= N; i++) {
        v[i] = get_int();
        w[i] = get_int();
    }

    int *prev = (int*)malloc((W + 1) * sizeof(int));
    int *curr = (int*)malloc((W + 1) * sizeof(int));

    for (int i = 0; i <= W; i++) {
        prev[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < w[i]; j++) {
            curr[j] = prev[j];
        }
        for (int j = w[i]; j <= W; j++) {
            int take = prev[j - w[i]] + v[i];
            curr[j] = (take > prev[j]) ? take : prev[j];
        }
        for (int j = 0; j <= W; j++) {
            prev[j] = curr[j];
        }
    }

    printf("%d\n", prev[W]);

    free(v);
    free(w);
    free(prev);
    free(curr);

    return 0;
}
// End of Code
