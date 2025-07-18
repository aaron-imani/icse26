#include <stdio.h>

int ni() {
    int val;
    scanf("%d", &val);
    return val;
}

void solve() {
    int a = ni();
    int b = ni();
    printf("%d\n", (a - 2 * b > 0) ? a - 2 * b : 0);
}

int main() {
    solve();
    return 0;
} // End of Code
