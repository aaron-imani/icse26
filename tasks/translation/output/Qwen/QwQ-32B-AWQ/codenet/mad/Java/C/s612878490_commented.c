#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int main() {
    char buffer[100];
    int N, M;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d", &N, &M);
    int shortage[M];
    for (int i = 0; i < M; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        int A;
        sscanf(buffer, "%d", &A);
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
