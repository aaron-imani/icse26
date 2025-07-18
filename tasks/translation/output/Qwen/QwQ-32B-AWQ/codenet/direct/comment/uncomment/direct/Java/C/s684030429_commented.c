#include <stdio.h>

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = (a - 2 * b > 0) ? a - 2 * b : 0;
    printf("%d\n", result);
}

int main() {
    solve();
    return 0;
} // End of Code
