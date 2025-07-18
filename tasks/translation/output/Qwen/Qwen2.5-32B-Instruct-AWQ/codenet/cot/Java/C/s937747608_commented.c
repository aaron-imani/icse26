#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a*b >= c*d) {
        printf("%d", a*b);
    } else if(a*b <= c*d) {
        printf("%d", c*d);
    }
    return 0; // End of Code
}
