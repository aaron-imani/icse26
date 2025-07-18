#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 1;
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    return 0;
}
// End of Code
