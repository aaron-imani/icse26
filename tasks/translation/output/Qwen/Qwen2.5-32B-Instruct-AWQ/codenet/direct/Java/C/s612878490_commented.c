#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char line[100];
    int N, M;
    int A;
    int shortage[100];
    int ans = 0;

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &A);
        shortage[i] = N > A ? N - A : 0;
    }

    qsort(shortage, M, sizeof(int), compare);

    for (int i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    printf("%d\n", ans);

    return 0;
} // End of Code
