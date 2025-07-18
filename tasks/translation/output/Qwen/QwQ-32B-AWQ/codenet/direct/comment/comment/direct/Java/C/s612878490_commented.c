#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) return -1;
    return val1 > val2 ? ario? 1 : 0;
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 1;

    int *shortage = (int*)malloc(M * sizeof(int));
    if (!shortage) return 1;

    for (int i = 0; i < M; i++) {
        int A;
        scanf("%d", &A);
        shortage[i] = (N > A) ? (N - A) : 0;
    }

    qsort(shortage, M, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    printf("%d\n", ans);

    free(shortage);
    return 0;
}
// End of Code
