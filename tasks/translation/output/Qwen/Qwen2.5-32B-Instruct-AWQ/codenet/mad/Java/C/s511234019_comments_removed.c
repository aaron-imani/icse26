#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        // Handle input error if necessary
        return 1;
    }
    if (a % 2 == 0 || b % 2 == 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}
// End of Code
