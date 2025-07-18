#include <stdio.h>

int main() {
    int count;
    scanf("%d", &count);
    int givingNumbers[count];
    for (int i = 0; i < count; i++) {
        scanf("%d", &givingNumbers[i]);
    }
    for (int i = count - 1; 0 <= i; i--) {
        printf("%d", givingNumbers[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
// End of Code
