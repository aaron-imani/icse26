#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long long MOD;
    int MAXN;
} Helper;

Helper hp = {MOD, MAXN};

void initIO(FILE *in, FILE *out) {
    // No specific initialization needed for file pointers in C
}

int nextInt(FILE *in) {
    int c, val = 0;
    bool neg = false;
    do {
        c = fgetc(in);
    } while (c <= 32);
    if (c == '-') {
        neg = true;
        c = fgetc(in);
    }
    for (; c >= '0' && c <= '9'; c = fgetc(in))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

long long nextLong(FILE *in) {
    int c;
    long long val = 0;
    bool neg = false;
    do {
        c = fgetc(in);
    } while (c <= 32);
    if (c == '-') {
        neg = true;
        c = fgetc(in);
    }
    for (; c >= '0' && c <= '9'; c = fgetc(in))
        val = (val << 3) + (val << 1) + (c & 15);
    return neg ? -val : val;
}

void print(FILE *out, const char *a) {
    fprintf(out, "%s", a);
}

void printsp(FILE *out, const char *a) {
    print(out, a);
    print(out, " ");
}

void println(FILE *out) {
    fprintf(out, "\n");
}

void printlnObj(FILE *out, const char *a) {
    print(out, a);
    println(out);
}

void flush(FILE *out) {
    fflush(out);
}

void solve(FILE *in, FILE *out) {
    int tc = 1; // Assuming no test cases for simplicity
    for (int tce = 1; tce <= tc; ++tce) {
        int N = nextInt(in);
        long long K = nextLong(in);
        int A[N];
        for (int i = 0; i < N; ++i) {
            A[i] = nextInt(in);
        }

        bool vis[N];
        for (int i = 0; i < N; ++i) {
            vis[i] = false;
        }

        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        int st = 0;
        int straight[MAXN], straightSize = 0;
        while (st != curr) {
            straight[straightSize++] = st;
            st = A[st] - 1;
        }

        int cycle[MAXN], cycleSize = 0;
        cycle[cycleSize++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle[cycleSize++] = curr;
            curr = A[curr] - 1;
        }

        if (K < straightSize) {
            fprintf(out, "%d\n", straight[K] + 1);
        } else {
            K -= straightSize;
            fprintf(out, "%d\n", cycle[K % cycleSize] + 1);
        }
    }
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    initIO(in, out);
    solve(in, out);
    flush(out);
    return 0;
}
// End of Code
