#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a % 2 == 0 || b % 2 == 0)
        printf("No\n");
    else
        printf("Yes\n");
} // End of Code
