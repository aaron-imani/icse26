#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000006
#define MOD 1000000007

#define BUFSIZE (1 << 20)
static char buf[BUFSIZE];
static int index = 0, total = 0;

static int scan() {
    if (index >= total) {
        index = 0;
        total = fread(buf, 1, BUFSIZE, stdin);
        if (total <= 0) return -1;
    }
    return (unsigned char)buf[index++];
}

int nextInt() {
    int c, val = 0;
    while ((c = scan()) <= 32);
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-') ? 1 : 0;
        c = scan();
    }
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = scan();
    }
    return neg ? -val : val;
}

long long nextLong() {
    int c;
    long long val = 0;
    while ((c = scan()) <= 32);
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-') ? 1 : 0;
        c = scan();
    }
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = scan();
    }
    return neg ? -val : val;
}

void solve() {
    int N = nextInt();
    long long K = nextLong();

    int *A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        A[i] = nextInt();
    }

    char *vis = (char*)calloc(N, sizeof(char));

    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }

    int *straight = (int*)malloc(N * sizeof(int));
    int straight_size = 0;

    int *cycle = (int*)malloc(N * sizeof(int));
    int cycle_size = 0;

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
        long long rem = K - straight_size;
        int pos = (int)(rem % cycle_size);
        printf("%d\n", cycle[pos] + 1);
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
