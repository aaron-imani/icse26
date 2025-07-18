#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024 * 8
#define MAX_STR 500 * 8 * 2

char buffer[MAX_INPUT];
char str[MAX_STR];
int pos = 0;
int readLen = 0;

int read() {
    if (pos >= readLen) {
        pos = 0;
        readLen = fread(buffer, 1, MAX_INPUT, stdin);
        if (readLen <= 0) {
            return -1;
        }
    }
    return buffer[pos++];
}

int nextInt() {
    int len = 0;
    str[len++] = read();
    len = reads(len, isSpace);
    int i = 0;
    int ret = 0;
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) ret = ret * 10 + str[i] - '0';
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

long nextLong() {
    int len = 0;
    str[len++] = read();
    len = reads(len, isSpace);
    int i = 0;
    long ret = 0;
    if (str[0] == '-') {
        i = 1;
    }
    for (; i < len; i++) ret = ret * 10 + str[i] - '0';
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

double nextDouble() {
    int len = 0;
    str[len++] = read();
    len = reads(len, isSpace);
    int i = 0;
    double ret = 0;
    if (str[0] == '-') {
        i = 1;
    }
    int cnt = 0;
    for (; i < len; i++) {
        if (str[i] == '.') {
            cnt = 10;
            continue;
        }
        if (cnt == 0) {
            ret = ret * 10 + str[i] - '0';
        } else {
            ret = ret + ((double)(str[i] - '0') / cnt);
            cnt *= 10;
        }
    }
    if (str[0] == '-') {
        ret = -ret;
    }
    return ret;
}

char nextChar() {
    while (true) {
        int c = read();
        if (!isSpace[c]) {
            return (char)c;
        }
    }
}

int reads(int len, int *accept) {
    while (true) {
        int c = read();
        if (accept[c]) {
            break;
        }
        if (str[len] == 0) {
            char *rep = realloc(str, len * 3 / 2);
            if (rep == NULL) {
                return -1;
            }
            str = rep;
        }
        str[len++] = (char)c;
    }
    return len;
}

void prn(char *s) {
    printf("%s\n", s);
}

void prn(int i) {
    printf("%d\n", i);
}

void prn(long i) {
    printf("%ld\n", i);
}

void prr(char *s) {
    printf("%s", s);
}

int ni() {
    return nextInt();
}

long nl() {
    return nextLong();
}

double nd() {
    return nextDouble();
}

char *ns() {
    int len = 0;
    str[len++] = nextChar();
    len = reads(len, isSpace);
    str[len] = 0;
    return strdup(str);
}

int *ndi(int n) {
    int *ans = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = ni();
    }
    return ans;
}

long *ndl(int n) {
    long *ans = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        ans[i] = nl();
    }
    return ans;
}

double *ndd(int n) {
    double *ans = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ans[i] = nd();
    }
    return ans;
}

char **nds(int n) {
    char **ans = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        ans[i] = ns();
    }
    return ans;
}

int **nddi(int n, int m) {
    int **ans = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        ans[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            ans[i][j] = ni();
        }
    }
    return ans;
}

long **nddl(int n, int m) {
    long **ans = malloc(n * sizeof(long *));
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
    char c[W];
    for (int i = 0; i < H; i++) {
        strcpy(c, ns());
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
            if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
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
