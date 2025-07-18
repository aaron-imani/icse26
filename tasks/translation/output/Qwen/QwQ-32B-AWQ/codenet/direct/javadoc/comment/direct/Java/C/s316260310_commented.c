#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE (1 << 20)
static char buf[BUFSIZE];
static int index = 0;
static int total = 0;

void initIO() {
    index = 0;
    total = 0;
}

int scan() {
    if (index >= total) {
        index = 0;
        total = fread(buf, sizeof(char), BUFSIZE, stdin);
        if (total <= 0) return -1;
    }
    return buf[index++];
}

int nextInt() {
    int c;
    while ((c = scan()) <= 32) ; // Skip whitespace
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-');
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
    long long val = 0;
    while ((c = scan()) <= 32) ; // Skip whitespace
    int neg = 0;
    if (c == '-' || c == '+') {
        neg = (c == '-');
        c = scan();
    }
    while (c >= '0' && c <= '9') {
        val = val * 10 + (c - '0');
        c = scan();
    }
    return neg ? -val : val;
}

void printInt(int a) {
    if (a < 0) {
        putchar('-');
        a = -a;
    }
    if (a == 0) {
        putchar('0');
        return;
    }
    char buffer[20];
    int pos = 0;
    while (a > 0) {
        buffer[pos++] = (a % 10) + '0';
        a /= 10;
    }
    for (int i = pos-1; i >=0; --i) putchar(buffer[i]);
}

void printLong(long long a) {
    if (a < 0) {
        putchar('-');
        a = -a;
    }
    if (a == 0) {
        putchar('0');
        return;
    }
    char buffer[25];
    int pos =0;
    while (a >0) {
        buffer[pos++] = (a%10)+'0';
        a /=10;
    }
    for (int i=pos-1; i>=0; --i) putchar(buffer[i]);
}

void printspInt(int a) {
    printInt(a);
    putchar(' ');
}

void printlnInt(int a) {
    printInt(a);
    putchar('\n');
}

void flush() {
    fflush(stdout);
}

void solve() {
    int N = nextInt();
    long long K = nextLong();
    int *A = malloc(N * sizeof(int));
    if (!A) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }

    int curr = 0;
    char *vis = malloc(N * sizeof(char));
    if (!vis) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    memset(vis, 0, N * sizeof(char));

    while (!vis[curr]) {
        vis[curr] = 1;
        curr = A[curr] - 1;
    }

    int straight_size = 0;
    int *straight = malloc(N * sizeof(int));
    if (!straight) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int st = 0;
    while (st != curr) {
        straight[straight_size++] = st;
        st = A[st] - 1;
    }

    int cycle_size = 0;
    int *cycle = malloc(N * sizeof(int));
    if (!cycle) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    int current = curr;
    cycle[cycle_size++] = current;
    current = A[current] - 1;
    while (current != cycle[0]) {
        cycle[cycle_size++] = current;
        current = A[current] - 1;
    }

    if (K < straight_size) {
        printlnInt(straight[(int)K] + 1);
    } else {
        long long remaining = K - straight_size;
        int idx = (int)(remaining % cycle_size);
        printlnInt(cycle[idx] + 1);
    }

    free(A);
    free(vis);
    free(straight);
    free(cycle);
}

int main() {
    initIO();
    solve();
    return 0;
}
// End of Code
