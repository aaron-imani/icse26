#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b); // Removed space for robustness
    if (a % 2 == 0 || b % 2 == 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}
// End of Code
