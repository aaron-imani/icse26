#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int shortage[M];

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

    return 0;
}
// End of Code
