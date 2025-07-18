#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 * 8

typedef struct {
    int key;
    int val;
} PP;

typedef struct {
    int key;
    int val1;
    int val2;
} PPP;

typedef struct {
    long key;
    long val;
} PPL;

typedef struct {
    long key;
    long* val;
} PPDL;

typedef struct {
    int* data;
    int size;
} Array;

void prn(int i) {
    printf("%d\n", i);
}

void prn(char* s) {
    printf("%s\n", s);
}

void prr(char* s) {
    printf("%s", s);
}

int ni() {
    int num;
    scanf("%d", &num);
    return num;
}

long nl() {
    long num;
    scanf("%ld", &num);
    return num;
}

double nd() {
    double num;
    scanf("%lf", &num);
    return num;
}

char* ns() {
    char* str = malloc(MAX_SIZE * sizeof(char));
    scanf("%s", str);
    return str;
}

int* ndi(int n) {
    int* ans = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = ni();
    }
    return ans;
}

long* ndl(int n) {
    long* ans = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        ans[i] = nl();
    }
    return ans;
}

double* ndd(int n) {
    double* ans = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ans[i] = nd();
    }
    return ans;
}

char** nds(int n) {
    char** ans = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        ans[i] = ns();
    }
    return ans;
}

int** nddi(int n, int m) {
    int** ans = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        ans[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            ans[i][j] = ni();
        }
    }
    return ans;
}

long** nddl(int n, int m) {
    long** ans = malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        ans[i] = malloc(m * sizeof(long));
        for (int j = 0; j < m; j++) {
            ans[i][j] = nl();
        }
    }
    return ans;
}

void solve() {
    int H = ni();
    int W = ni();
    char C[H + 2][W + 2];
    char* c;
    for (int i = 0; i < H; i++) {
        c = ns();
        for (int j = 0; j < W; j++) {
            C[i + 1][j + 1] = c[j];
        }
    }
    if (H == 1 && W == 1) {
        prn("No");
        return;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' &&
                C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                prn("No");
                return;
            }
        }
    }
    prn("Yes");
}

int main() {
    solve();
    return 0;
}
// End of Code
