#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    int a, b;
    sscanf(input, "%d %d", &a, &b);
    
    if (b % a == 0) {
        printf("%d\n", a + b);
    } else {
        printf("%d\n", b - a);
    }
    
    return 0;
}

// End of Code
