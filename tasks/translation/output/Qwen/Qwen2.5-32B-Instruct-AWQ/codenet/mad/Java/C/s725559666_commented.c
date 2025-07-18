#include <stdio.h>

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Input error\n");
        return 1;
    }
    if (a < b && b < c && a < c) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// End of Code
