#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    char buffer[1024];
    int N, M;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d", &N, &M);

    int shortage[M];
    int i, A;

    for (i = 0; i < M; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &A);
        shortage[i] = (N > A) ? (N - A) : 0;
    }

    qsort(shortage, M, sizeof(int), compare);

    int ans = 0;
    for (i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    printf("%d\n", ans);

    return 0;
}
// End of Code
