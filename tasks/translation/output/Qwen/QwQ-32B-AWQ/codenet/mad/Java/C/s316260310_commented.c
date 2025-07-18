#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE (1 << 20)
#define MAXN 1000006
#define MOD 1000000007

static char buf[BUFSIZE];
static int pos = 0;
static int len = 0;

void init_io() {
    pos = 0;
    len = fread(buf, 1, BUFSIZE, stdin);
}

int read_char() {
    if (pos >= len) {
        len = fread(buf, 1, BUFSIZE, stdin);
        pos = 0;
        if (len == 0) return -1;
    }
    return buf[pos++];
}

int read_int() {
    int c = read_char();
    while (isspace(c)) c = read_char();
    if (c == -1) return 0;
    int neg = 0;
    if (c == '-') {
        neg = 1;
        c = read_char();
    }
    int val = 0;
    while (isdigit(c)) {
        val = val * 10 + (c - '0');
        c = read_char();
    }
    return neg ? -val : val;
}

long long read_long() {
    int c = read_char();
    while (isspace(c)) c = read_char();
    if (c == -1) return 0;
    int neg = 0; // Fixed typo here from "太少" to 0
    if (c == '-') {
        neg = 1;
        c = read_char();
    }
    long long val = 0;
    while (isdigit(c)) {
        val = val * 10 + (c - '0');
        c = read_char();
    }
    return neg ? -val : val;
}

int main() {
    init_io();

    int N = read_int();
    long long K = read_long();

    int* A = (int*)malloc(N * sizeof(int));
    if (!A) return 1; // Added error check
    for (int i = 0; i < N; i++) {
        A[i] = read_int();
    }

    int* visited = (int*)calloc(N, sizeof(int));
    if (!visited) return 1; // Added error check

    int curr = 0;
    while (!visited[curr]) {
        visited[curr] = 1;
        curr = A[curr] - 1;
    }

    // Build straight path
    int st = 0;
    int straight_size = 0;
    int* straight = (int*)malloc(N * sizeof(int));
    if (!straight) return 1; // Added error check
    while (st != curr) {
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    // Build cycle
    int cycle_size = 0;
    int* cycle = (int*)malloc(N * sizeof(int));
    if (!cycle) return 1; // Added error check
    int first = curr;
    cycle[cycle_size++] = first;
    curr = A[first] - 1;
    while (curr != first) {
        cycle[cycle_size++] = curr;
        curr = A[curr] - 1;
    }

    if (K < straight_size) {
        printf("%d\n", straight[(int)K] + 1); // Cast K to int for indexing
    } else {
        K -= straight_size;
        int idx = (int)(K % cycle_size);
        printf("%d\n", cycle[idx] + 1);
    }

    free(A);
    free(visited);
    free(straight);
    free(cycle);

    return 0;
}
// End of Code
