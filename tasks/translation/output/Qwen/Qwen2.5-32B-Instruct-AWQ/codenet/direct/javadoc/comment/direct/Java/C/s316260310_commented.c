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

void solve(Helper *helper) {
    int tc = 1; // Assuming single test case for simplicity
    for (int tce = 1; tce <= tc; ++tce) {
        int N = nextInt(helper);
        long K = nextLong(helper);
        int *A = getIntArray(helper, N);

        int *straight = NULL;
        int *cycle = NULL;
        int vis[MAXN] = {0};
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = 1;
            curr = A[curr] - 1;
        }

        int st = 0;
        int straightSize = 0;
        while (st != curr) {
            straight = realloc(straight, (straightSize + 1) * sizeof(int));
            straight[straightSize++] = st;
            st = A[st] - 1;
        }

        int cycleSize = 0;
        cycle = realloc(cycle, (cycleSize + 1) * sizeof(int));
        cycle[cycleSize++] = curr;
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle = realloc(cycle, (cycleSize + 1) * sizeof(int));
            cycle[cycleSize++] = curr;
            curr = A[curr] - 1;
        }

        if (K < straightSize) {
            println(helper, (char *) (straight[K] + 1));
        } else {
            K -= straightSize;
            println(helper, (char *) (cycle[K % cycleSize] + 1));
        }

        free(straight);
        free(cycle);
        free(A);
    }
}

int main() {
    hp = malloc(sizeof(Helper));
    hp->MOD = MOD;
    hp->MAXN = MAXN;
    initIO(hp, "input.txt", "output.txt");

    solve(hp);

    flush(hp);
    fclose(hp->in);
    fclose(hp->out);
    free(hp);

    return 0;
}

// End of Code
