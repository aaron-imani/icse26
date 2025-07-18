#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max = 0, cur = 0;

void solve() {
    int a = ni();
    int b = ni();
    printf("%d\n", (a - 2 * b > 0) ? a - 2 * b : 0);
}

int ni() {
    int a;
    scanf("%d", &a);
    return a;
}

int main() {
    solve();
    return 0;
}
// End of Code
