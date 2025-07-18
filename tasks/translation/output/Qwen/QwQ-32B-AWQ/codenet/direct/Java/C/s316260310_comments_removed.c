#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    long long K;
    if (scanf("%d %lld", &N, &K) != 2) {
        return 1;
    }
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]) != 1) {
            return 1;
        }
    }

    int *straight = malloc(N * sizeof(int));
    int *cycle = malloc(N * sizeof(int));
    char *visited = calloc(N, sizeof(char));

    int curr = 0;
    while (!visited[curr]) {
        visited[curr] = 1;
        curr = A[curr] - 1;
    }

    // Build straight array
    int st = 0;
    int i = 0;
    while (st != curr) {
        straight[i++] = st;
        st = A[st] - 1;
    }
    int straight_len = i;

    // Build cycle array
    int cycle_start = curr;
    int j = 0;
    cycle[j++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle_start) {
        cycle[j++] = curr;
        curr = A[curr] - 1;
    }
    int cycle_len = j;

    if (K < straight_len) {
        printf("%d\n", straight[(int)K] + 1);
    } else {
        long long rem = K - straight_len;
        int idx = (int)(rem % cycle_len);
        printf("%d\n", cycle[idx] + 1);
    }

    free(A);
    free(straight);
    free(cycle);
    free(visited);
    return 0;
}
// End of Code
