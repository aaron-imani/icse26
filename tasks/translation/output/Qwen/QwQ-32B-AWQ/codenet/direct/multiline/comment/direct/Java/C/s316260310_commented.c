#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000006

char buf[1 << 20];
int index = 0, total = 0;

int scan() {
    if (index >= total) {
        index = 0;
        total = fread(buf, 1, sizeof(buf), stdin);
        if (total <= 0) return -1;
    }
    return buf[index++];
}

int nextInt() {
    int c;
    while ((c = scan()) <= 32);
    int neg = 0;
    if (c == '-') {
        neg = 1;
        c = scan();
    }
    int val = 0;
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = scan();
    }
    return neg ? -val : val;
}

long long nextLong() {
    int c;
    while ((c = scan()) <= 32);
    int neg = 0;
    if (c == '-') {
        neg = 1;
        c = scan();
    }
    long long val = 0;
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = scan();
    }
    return neg ? -val : val;
}

int main() {
    int N = nextInt();
    long long K = nextLong();
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }

    char *vis = calloc(N, 1);
    int curr = 0;
    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }

    int st = 0;
    int straight_size = 0;
    int *straight = malloc(N * sizeof(int));
    while (st != curr) {
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    int cycle_size = 0;
    int *cycle = malloc(N * sizeof(int));
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
        int idx = (int)(K % cycle_size);
        printf("%d\n", cycle[idx] + 1);
    }

    free(A);
    free(straight);
    free(cycle);
    free(vis);
    return 0;
}
// End of Code
