#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000006

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    long long K;
    if (scanf("%lld", &K) != 1) {
        return 1;
    }

    int *A = (int*)malloc(N * sizeof(int));
    if (!A) {
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]) != 1) {
            free(A);
            return 1;
        }
    }

    int visited[MAXN];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    int curr = 0;
    while (!visited[curr]) {
        visited[curr] = 1;
        curr = A[curr] - 1;
    }

    int straight[MAXN], cycle[MAXN];
    int straight_len = 0, cycle_len = 0;

    int st = 0, i = 0;
    while (st != curr) {
        straight[i] = st;
        i++;
        st = A[st] - 1;
    }
    straight_len = i;

    int start = curr;
    cycle[0] = start;
    int next_pos = A[start] - 1;
    int j = 1;
    while (next_pos != start) {
        cycle[j] = next_pos;
        j++;
        next_pos = A[next_pos] - 1;
    }
    cycle_len = j;

    if (K < (long long)straight_len) {
        printf("%d\n", straight[K] + 1);
    } else {
        long long rem = K - straight_len;
        int idx = (int)(rem % cycle_len);
        printf("%d\n", cycle[idx] + 1);
    }

    free(A);
    return 0;
}
// End of Code
- 1;
    while (curr != cycle[0]) {
        cycle[cycle_len++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straight_len) {
        printf("%d\n", straight[(int)K] + 1);
    } else {
        K -= straight_len;
        int idx = (int)(K % cycle_len);
        printf("%d\n", cycle[idx] + 1);
    }

    free(A);
    free(vis);
    free(straight);
    free(cycle);
}

int main() {
    solve();
    return 0;
}
// End of Code
