#include <stdio.h>

int main() {
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 1;
    int a, b;
    sscanf(buffer, "%d %d", &a, &b);
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    return 0;
} // End of Code
