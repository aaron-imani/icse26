#include <stdio.h>

int main() {
    int count;
    if (scanf("%d", &count) != 1) {
        // Handle input error
        printf("Invalid input for count\n");
        return 1;
    }

    int givingNumbers[count];

    // Read Numbers
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &givingNumbers[i]) != 1) {
            // Handle input error
            printf("Invalid input for number at index %d\n", i);
            return 1;
        }
    }

    // Reversing Numbers
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", givingNumbers[i]);
        if (i > 0) {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
// End of Code
