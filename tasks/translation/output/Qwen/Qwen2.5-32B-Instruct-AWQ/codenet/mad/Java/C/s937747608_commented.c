#include <stdio.h>

int main() {
    int a, b, c, d;
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) {
        // Handle input error if necessary
        return 1;
    }
    int product_ab = a * b;
    int product_cd = c * d;
    if (product_ab >= product_cd) {
        printf("%d\n", product_ab);
    } else {
        printf("%d\n", product_cd);
    }
    // End of Code
}
