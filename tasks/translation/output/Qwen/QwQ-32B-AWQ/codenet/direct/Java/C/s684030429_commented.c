#include <stdio.h>

int max = 0, cur = 0;

int ni() {
    int val;
    scanf("%d", &val);
    return val;
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
