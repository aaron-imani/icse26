#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006
#define MOD 1000000007

typedef struct {
    long MOD;
    int MAXN;
    FILE *in;
    FILE *out;
} Helper;

Helper *hp;

void initIO(Helper *helper, const char *inputFile, const char *outputFile) {
    helper->in = fopen(inputFile, "r");
    helper->out = fopen(outputFile, "w");
}

void println(Helper *helper, const char *str) {
    fprintf(helper->out, "%s\n", str);
}

void print(Helper *helper, const char *str) {
    fprintf(helper->out, "%s", str);
}

void flush(Helper *helper) {
    fflush(helper->out);
}

int nextInt(Helper *helper) {
    int val;
    fscanf(helper->in, "%d", &val);
    return val;
}

long nextLong(Helper *helper) {
    long val;
    fscanf(helper->in, "%ld", &val);
    return val;
}

int *getIntArray(Helper *helper, int size) {
    int *ar = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        ar[i] = nextInt(helper);
    }
    return ar;
}

void solve(int tc) {
    int N = nextInt(hp);
    long K = nextLong(hp);
    int *A = getIntArray(hp, N);

    int *straight = malloc(N * sizeof(int));
    int *cycle = malloc(N * sizeof(int));
    int vis[N];
    memset(vis, 0, N * sizeof(int));

    int curr = 0;
    int idx = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        straight[idx++] = curr;
        curr = A[curr] - 1;
    }

    int st = 0;
    while (st != curr) {
        straight[idx++] = st;
        st = A[st] - 1;
    }

    int cycleIdx = 0;
    cycle[cycleIdx++] = curr;
    curr = A[curr] - 1;
    while (curr != cycle[0]) {
        cycle[cycleIdx++] = curr;
        curr = A[curr] - 1;
    }

    if (K < idx) {
        println(hp, (char *) (straight[K] + 1));
    } else {
        K -= idx;
        println(hp, (char *) (cycle[K % cycleIdx] + 1));
    }

    free(straight);
    free(cycle);
    free(A);
}

int main() {
    hp = malloc(sizeof(Helper));
    hp->MOD = MOD;
    hp->MAXN = MAXN;
    initIO(hp, "input.txt", "output.txt");

    int tc = 1;
    for (int tce = 1; tce <= tc; ++tce) {
        solve(tce);
    }

    flush(hp);
    fclose(hp->in);
    fclose(hp->out);
    free(hp);

    return 0;
}

// End of Code
