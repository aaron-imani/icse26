#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 1000006

int main() {
    int N;
    scanf("%d", &N);
    long long K;
    scanf("%lld", &K);
    int A[MAXN];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bool vis[MAXN];
    memset(vis, 0, sizeof(vis));
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = true;
        curr = A[curr] - 1;
    }

    int straight[MAXN];
    int straight_len = 0;
    int st = 0;
    while (st != curr) {
        straight[straight_len++] = st;
        st = A[st] - 1;
    }

    int cycle[MAXN];
    int cycle_len = 0;
    int c = curr;
    do {
        cycle[cycle_len++] = c;
        c = A[c] - 1;
    } while (c != curr);

    if (K < straight_len) {
        printf("%d\n", straight[K] + 1);
    } else {
        long long rem = K - straight_len;
        int pos = (int)(rem % cycle_len);
        printf("%d\n", cycle[pos] + 1);
    }

    return 0;
}
// End of Code
