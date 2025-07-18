#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006

int main() {
    int N, K;
    int A[MAXN];
    char visited[MAXN];
    int curr, st, first;
    int *straight = NULL, *cycle = NULL;
    int straight_size = 0, cycle_size = 0;

    if (scanf("%d %ld", &N, &K) != 2) return 1;
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);

    memset(visited, 0, sizeof(visited));

    curr = 0;
    while (!visited[curr]) {
        visited[curr] = 1;
        curr = A[curr] - 1;
    }

    st = 0;
    straight_size = 0;
    straight = NULL;
    while (st != curr) {
        if (straight_size == 0) {
            straight = malloc(sizeof(int));
        } else {
            straight = realloc(straight, (straight_size + 1) * sizeof(int));
        }
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    first = curr;
    cycle_size = 0;
    cycle = NULL;
    if (cycle_size == 0) {
        cycle = malloc(sizeof(int));
    }
    cycle[cycle_size++] = first;
    curr = A[first] - 1;
    while (curr != first) {
        cycle = realloc(cycle, (cycle_size + 1) * sizeof(int));
        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
    }

    int ans;
    if (K < straight_size) {
        ans = straight[K] + 1;
    } else {
        K -= straight_size;
        ans = cycle[(K % cycle_size)] + 1;
    }

    printf("%d\n", ans);
    free(straight);
    free(cycle);
    return 0;
}
// End of Code
