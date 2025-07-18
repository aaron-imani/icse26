#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        char *token = strtok(input, " ");
        int a = atoi(token);
        token = strtok(NULL, " ");
        int b = atoi(token);
        if (b % a == 0) {
            printf("%d\n", a + b);
        } else {
            printf("%d\n", b - a);
        }
    } else {
        perror("Error reading input");
    }
    return 0;
}
// End of Code
