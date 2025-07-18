#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long MOD;
    int MAXN;
    char *buf;
    int index;
    int total;
    FILE *in;
    FILE *out;
} Helper;

void Helper_init(Helper *h) {
    h->MOD = 1000000007L;
    h->MAXN = 1000006;
    h->buf = (char*)malloc(1 << 20);
    h->index = 0;
    h->total = 0;
    h->in = stdin;
    h->out = stdout;
}

int Helper_scan(Helper *h) {
    if (h->index >= h->total) {
        h->total = fread(h->buf, 1, 1 << 20, h->in);
        h->index = 0;
        if (h->total <= 0) return -1;
    }
    return (unsigned char)h->buf[h->index++];
}

int Helper_nextInt(Helper *h) {
    int c, val = 0;
    for (c = Helper_scan(h); c <= 32; c = Helper_scan(h));
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-');
        c = Helper_scan(h);
    }
    for (; c >= '0' && c <= '9'; c = Helper_scan(h)) {
        val = val * 10 + (c - '0');
    }
    return neg ? -val : val;
}

long long Helper_nextLong(Helper *h) {
    int c, val = 0;
    for (c = Helper_scan(h); c <= 32; c = Helper_scan(h));
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-');
        c = Helper_scan(h);
    }
    for (; c >= '0' && c <= '9'; c = Helper_scan(h)) {
        val = val * 10 + (c - '0');
    }
    return neg ? -val : val;
}

void solve(Helper *h) {
    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) {
        int N = Helper_nextInt(h);
        long long K = Helper_nextLong(h);
        int *A = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            A[i] = Helper_nextInt(h) - 1;
        }

        char *vis = calloc(N, sizeof(char));
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = 1;
            curr = A[curr];
        }

        int *straight = malloc(N * sizeof(int));
        int straight_size = 0;
        int st = 0;
        while (st != curr) {
            straight[straight_size++] = st;
            st = A[st];
        }

        int *cycle = malloc(N * sizeof(int));
        int cycle_size = 0;
        int cycle_start = curr;
        int next = A[curr];
        cycle[cycle_size++] = curr;
        while (next != cycle_start) {
            cycle[cycle_size++] = next;
            curr = next;
            next = A[curr];
        }

        if (K < straight_size) {
            int pos = straight[K];
            fprintf(h->out, "%d\n", pos + 1);
        } else {
            long long rem = K - straight_size;
            int idx = (int)(rem % cycle_size);
            int pos = cycle[idx];
            fprintf(h->out, "%d\n", pos + 1);
        }

        free(A);
        free(straight);
        free(cycle);
        free(vis);
        fflush(h->out);
    }
}

int main() {
    Helper h;
    Helper_init(&h);
    solve(&h);
    free(h.buf);
    return 0;
}
// End of Code
