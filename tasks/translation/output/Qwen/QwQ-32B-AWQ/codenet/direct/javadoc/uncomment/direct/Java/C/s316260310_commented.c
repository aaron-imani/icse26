#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE (1 << 20)
static char buf[BUFSIZE];
static int index = 0;
static int total = 0;

int scan() {
    if (index >= total) {
        index = 0;
        total = fread(buf, 1, BUFSIZE, stdin);
        if (total <= 0) return -1;
    }
    return buf[index++];
}

int nextInt() {
    int c;
    for (c = scan(); c <= ' ' && c != -1; c = scan());
    if (c == -1) return 0;
    int neg = c == '-';
    if (neg) c = scan();
    int val = 0;
    for (; c >= '0' && c <= '9'; c = scan())
        val = val * 10 + (c - '0');
    return neg ? -val : val;
}

long long nextLong() {
    int c;
    for (c = scan(); c <= ' ' && c != -1; c = scan());
    if (c == -1) return 0;
    int neg = c == '-';
    if (neg) c = scan();
    long long val = 0;
    for (; c >= '0' && c <= '9'; c = scan())
        val = val * 10 + (c - '0');
    return neg ? -val : val;
}

void solve(int N, long long K, int *A) {
    int *vis = calloc(N, sizeof(int));
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr];
    }
    int *straight = malloc(N * sizeof(int));
    int straight_len = 0;
    int st = 0;
    while (st != curr) {
        straight[straight_len++] = st;
        st = A[st];
    }
    int *cycle = malloc(N * sizeof(int));
    int cycle_len = 0;
    int current = curr;
    cycle[cycle_len++] = current;
    current = A[current];
    while (current != cycle[0]) {
        cycle[cycle_len++] = current;
        current = A[current];
    }
    if (K < straight_len) {
        printf("%d\n", straight[(int)K] + 1);
    } else {
        long long rem = (K - straight_len) % cycle_len;
        printf("%d\n", cycle[(int)rem] + 1);
    }
    free(straight);
    free(cycle);
    free(vis);
}

int main() {
    int N = nextInt();
    long long K = nextLong();
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        A[i] = nextInt() - 1;
    }
    solve(N, K, A);
    free(A);
    return 0;
}
// End of Code
