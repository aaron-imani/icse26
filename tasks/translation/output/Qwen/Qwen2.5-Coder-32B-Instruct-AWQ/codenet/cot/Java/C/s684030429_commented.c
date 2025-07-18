#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int ni() {
    int a;
    scanf("%d", &a);
    return a;
}

void solve() {
    int a = ni();
    int b = ni();

    printf("%d\n", max(0, a - 2 * b));
}

int main() {
    solve();
    // End of Code
    return 0;
}
