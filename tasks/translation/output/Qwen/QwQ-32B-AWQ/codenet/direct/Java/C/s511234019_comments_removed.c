#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % 2 == 0 || b % 2 == 0) {
        printf("No");
    } else {
        printf("Yes");
    }
    return 0;
}
// End of Code
