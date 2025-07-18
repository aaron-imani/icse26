#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;
    scanf("%d", &count);
    int *givingNumbers = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        scanf("%d", &givingNumbers[i]);
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", givingNumbers[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
    free(givingNumbers);
    return 0;
}
// End of Code
