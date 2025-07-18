#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long long MOD;
    int MAXN;
    FILE *in;
    FILE *out;
    char buf[1 << 20];
    int index;
    int total;
} Helper;

void initIO(Helper *hp, FILE *in, FILE *out) {
    hp->in = in;
    hp->out = out;
    hp->index = 0;
    hp->total = 0;
}

int scan(Helper *hp) {
    if (hp->index >= hp->total) {
        hp->index = 0;
        hp->total = fread(hp->buf, 1, sizeof(hp->buf), hp->in);
        if (hp->total <= 0) return -1;
    }
    return hp->buf[hp->index++];
}

char next(Helper *hp) {
    int c;
    for (c = scan(hp); c <= 32; c = scan(hp));
    char *sb = (char *)malloc(100);
    int i = 0;
    for (; c > 32; c = scan(hp)) sb[i++] = c;
    sb[i] = '\0';
    return sb[0];
}

int nextInt(Helper *hp) {
    int c, val = 0;
    for (c = scan(hp); c <= 32; c = scan(hp));
    bool neg = c == '-';
    if (c == '-' || c == '+') c = scan(hp);
    for (; c >= '0' && c <= '9'; c = scan(hp))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

long long nextLong(Helper *hp) {
    int c;
    long long val = 0;
    for (c = scan(hp); c <= 32; c = scan(hp));
    bool neg = c == '-';
    if (c == '-' || c == '+') c = scan(hp);
    for (; c >= '0' && c <= '9'; c = scan(hp))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

void print(Helper *hp, const char *a) {
    fprintf(hp->out, "%s", a);
}

void printsp(Helper *hp, const char *a) {
    print(hp, a);
    print(hp, " ");
}

void println(Helper *hp) {
    fprintf(hp->out, "\n");
}

void printlnObj(Helper *hp, const char *a) {
    print(hp, a);
    println(hp);
}

void flush(Helper *hp) {
    fflush(hp->out);
}

void solve(Helper *hp) {
    int tc = 1; // Assuming no test cases for simplicity
    for (int tce = 1; tce <= tc; ++tce) {
        int N = nextInt(hp);
        long long K = nextLong(hp);
        int *A = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; ++i) A[i] = nextInt(hp);

        bool *vis = (bool *)calloc(N, sizeof(bool));
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        int st = 0;
        int *straight = (int *)malloc(N * sizeof(int));
        int straightSize = 0;
        while (st != curr) {
            straight[straightSize++] = st;
            st = A[st] - 1;
        }

        int *cycle = (int *)malloc(N * sizeof(int));
        int cycleSize = 0;
        cycle[cycleSize++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle[cycleSize++] = curr;
            curr = A[curr] - 1;
        }

        if (K < straightSize) {
            printlnObj(hp, (char *)malloc(20));
            sprintf((char *)malloc(20), "%d", straight[K] + 1);
        } else {
            K -= straightSize;
            printlnObj(hp, (char *)malloc(20));
            sprintf((char *)malloc(20), "%d", cycle[K % cycleSize] + 1);
        }

        free(A);
        free(vis);
        free(straight);
        free(cycle);
    }
}

int main() {
    Helper hp;
    initIO(&hp, stdin, stdout);
    solve(&hp);
    flush(&hp);
    return 0;
}
// End of Code
