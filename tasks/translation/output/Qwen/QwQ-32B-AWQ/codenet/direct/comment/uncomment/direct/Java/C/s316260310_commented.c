#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006

int A[MAXN];
int straight[MAXN];
int cycle[MAXN];
int vis[MAXN];

int main() {
    int N;
    long long K;
    scanf("%d %lld", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    memset(vis, 0, sizeof(vis));
    int curr = 0;
    while (vis[curr] == 0) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }
    int st = 0;
    int idx = 0;
    while (st != curr) {
        straight[idx++] = st;
        st = A[st] - 1;
    }
    int straight_len = idx;
    int cycle_start = curr;
    int cidx = 0;
    cycle[cidx++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle_start) {
        cycle[cidx++] = curr;
        curr = A[curr] - 1;
    }
    int cycle_len = cidx;
    if (K < straight_len) {
        printf("%d\n", straight[K] + 1);
    } else {
        long long rem = K - straight_len;
        int pos = (int)(rem % cycle_len);
        printf("%d\n", cycle[pos] + 1);
    }
    return 0;
} // End of Code
