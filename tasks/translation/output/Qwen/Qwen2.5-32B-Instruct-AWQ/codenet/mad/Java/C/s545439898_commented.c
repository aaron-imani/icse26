#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    int givingNumbers[count];

    // Read Numbers
    for(int i = 0; i < count; i++) {
        scanf("%d", &givingNumbers[i]);
    }

    // Reversing Numbers
    for(int i = count - 1; i >= 0; i--) { // Changed the condition to i >= 0 for clarity
        printf("%d", givingNumbers[i]);
        if(i > 0) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
// End of Code
