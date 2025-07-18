#include <stdio.h>

int max = 0, cur = 0;

void solve() {
    int a = ni();
    int b = ni();

    printf("%d\n", (a - 2 * b > 0) ? a - 2 * b : 0);
}

int ni() {
    int a;
    if (scanf("%d", &a) != 1) {
        fprintf(stderr, "Error reading integer.\n");
        exit(EXIT_FAILURE);
    }
    return a;
}

int main() {
    solve();
    return 0;
}
// End of Code
