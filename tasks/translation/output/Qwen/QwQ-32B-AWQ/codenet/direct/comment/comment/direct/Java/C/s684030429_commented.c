#include <stdio.h>

int ni() {
    int x;
    scanf("%d", &x);
    return x;
}

void solve() {
    int a = ni();
    int b = ni();
    printf("%d\n", (a > 2*b) ? (a - 2*b) : 0);
}

int main() {
    solve();
    return 0;
}
// End of Code
