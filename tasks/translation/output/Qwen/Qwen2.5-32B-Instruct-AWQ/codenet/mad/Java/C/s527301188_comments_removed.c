#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
    char *token = strtok(input, " ");
    int nums[1000];
    int top = 0;

    while (token != NULL) {
        if (token[0] == '+') {
            if (top < 2) {
                fprintf(stderr, "Error: Not enough operands for operation.\n");
                return 1;
            }
            top--;
            nums[top-1] = nums[top - 1] + nums[top];
        } else if (token[0] == '-') {
            if (top < 2) {
                fprintf(stderr, "Error: Not enough operands for operation.\n");
                return 1;
            }
            top--;
            nums[top-1] = nums[top - 1] - nums[top];
        } else if (token[0] == '*') {
            if (top < 2) {
                fprintf(stderr, "Error: Not enough operands for operation.\n");
                return 1;
            }
            top--;
            nums[top-1] = nums[top - 1] * nums[top];
        } else {
            nums[top] = atoi(token);
            top++;
        }
        token = strtok(NULL, " ");
    }
    if (top != 1) {
        fprintf(stderr, "Error: Invalid input or operations.\n");
        return 1;
    }
    printf("%d\n", nums[0]);
    // End of Code
}
