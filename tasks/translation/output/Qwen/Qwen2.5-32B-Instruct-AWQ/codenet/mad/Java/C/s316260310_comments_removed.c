#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long MOD;
    int MAXN;
    int *sieve;
    long *factorial;
} Helper;

Helper *helper;

void initHelper() {
    helper = (Helper *)malloc(sizeof(Helper));
    helper->MOD = MOD;
    helper->MAXN = MAXN;
    helper->sieve = (int *)malloc(MAXN * sizeof(int));
    helper->factorial = (long *)malloc(MAXN * sizeof(long));
    memset(helper->sieve, 0, MAXN * sizeof(int));
    helper->factorial[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        helper->factorial[i] = helper->factorial[i - 1] * i % MOD;
    }
}

int nextInt() {
    int c, val = 0;
    for (c = getchar(); c <= 32; c = getchar()) ;
    int neg = c == '-';
    if (c == '-' || c == '+')
        c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar())
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

long nextLong() {
    int c;
    long val = 0;
    for (c = getchar(); c <= 32; c = getchar()) ;
    int neg = c == '-';
    if (c == '-' || c == '+')
        c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar())
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

void solve() {
    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) {
        int N = nextInt();
        long K = nextLong();
        int *A = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i) {
            A[i] = nextInt();
        }

        int *straight = (int *)malloc(N * sizeof(int));
        int *cycle = (int *)malloc(N * sizeof(int));
        int vis[N];
        memset(vis, 0, N * sizeof(int));
        int curr = 0;
        int straight_size = 0, cycle_size = 0;

        while (!vis[curr]) {
            vis[curr] = 1;
            straight[straight_size++] = curr;
            curr = A[curr] - 1;
        }

        int st = 0;
        while (st != curr) {
            straight[straight_size++] = st;
            st = A[st] - 1;
        }

        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle[cycle_size++] = curr;
            curr = A[curr] - 1;
        }

        if (K < straight_size) {
            printf("%d\n", straight[K] + 1);
        } else {
            K -= straight_size;
            printf("%d\n", cycle[K % cycle_size] + 1);
        }

        free(A);
        free(straight);
        free(cycle);
    }
}

int main() {
    initHelper();
    solve();
    free(helper->sieve);
    free(helper->factorial);
    free(helper);
    return 0;
}
// End of Code
