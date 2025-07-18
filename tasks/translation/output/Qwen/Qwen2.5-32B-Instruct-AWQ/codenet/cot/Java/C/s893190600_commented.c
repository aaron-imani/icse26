#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char C[MAX_SIZE][MAX_SIZE];

void prn(const char *s) {
    printf("%s\n", s);
}

void prn(int i) {
    printf("%d\n", i);
}

int ni() {
    int i;
    scanf("%d", &i);
    return i;
}

void solve() {
    int H = ni();
    int W = ni();
    char c[MAX_SIZE];
    for (int i = 0; i < H; i++) {
        scanf("%s", c);
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
