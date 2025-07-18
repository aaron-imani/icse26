#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char line[100];
    int N, M;

    if (fgets(line, sizeof(line), stdin) != NULL) {
        sscanf(line, "%d %d", &N, &M);
    }

    int* shortage = (int*)malloc(M * sizeof(int));

    for (int i = 0; i < M; i++) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            int A;
            sscanf(line, "%d", &A);
            shortage[i] = (N > A) ? N - A : 0;
        }
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
