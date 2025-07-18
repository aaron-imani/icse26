#include <stdio.h>

int main() {
    char buffer[1024];
    int a, b;
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d", &a, &b);
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    return 0;
}
// End of Code
