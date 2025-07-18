#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long long MOD;
    int MAXN;
} Helper;

Helper hp;

void initIO(FILE *in, FILE *out) {
    hp.MOD = MOD;
    hp.MAXN = MAXN;
}

int scan(FILE *in) {
    int c;
    while ((c = fgetc(in)) <= 32 && c != EOF);
    return c;
}

int nextInt(FILE *in) {
    int c, val = 0;
    bool neg = false;
    while ((c = scan(in)) <= 32 && c != EOF);
    if (c == '-' || c == '+') {
        neg = (c == '-');
        c = scan(in);
    }
    while (c >= '0' && c <= '9') {
        val = (val << 3) + (val << 1) + (c & 15);
        c = scan(in);
    }
    return neg ? -val : val;
}

long long nextLong(FILE *in) {
    int c;
    long long val = 0;
    bool neg = false;
    while ((c = scan(in)) <= 32 && c != EOF);
    if (c == '-' || c == '+') {
        neg = (c == '-');
        c = scan(in);
    }
    while (c >= '0' && c <= '9') {
        val = (val << 3) + (val << 1) + (c & 15);
        c = scan(in);
    }
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

void printlnObj(FILE *out, long long a) {
    fprintf(out, "%lld\n", a);
}

void flush(FILE *out) {
    fflush(out);
}

void solve(FILE *in, FILE *out) {
    int tc = 1; // Assuming no test cases for simplicity, as in the Java code
    for (int tce = 1; tce <= tc; ++tce) {
        int N = nextInt(in);
        long long K = nextLong(in);
        int A[MAXN];
        for (int i = 0; i < N; ++i) {
            A[i] = nextInt(in) - 1;
        }

        bool vis[MAXN] = {false};
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr];
        }

        int straight[MAXN], cycle[MAXN];
        int straightSize = 0, cycleSize = 0;

        int st = 0;
        while (st != curr) {
            straight[straightSize++] = st;
            st = A[st];
        }

        cycle[cycleSize++] = curr;
        curr = A[curr];
        while (curr != cycle[0]) {
            cycle[cycleSize++] = curr;
            curr = A[curr];
        }

        if (K < straightSize) {
            printlnObj(out, (long long)(straight[K] + 1));
        } else {
            K -= straightSize;
            printlnObj(out, (long long)(cycle[K % cycleSize] + 1));
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
