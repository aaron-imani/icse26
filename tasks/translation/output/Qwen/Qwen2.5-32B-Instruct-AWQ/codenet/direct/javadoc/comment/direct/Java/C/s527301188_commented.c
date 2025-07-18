#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    int nums[100];
    int top = 0;

    while (token != NULL) {
        if (token[0] == '+') {
            top--;
            nums[top-1] = nums[top - 1] + nums[top];
        } else if (token[0] == '-') {
            top--;
            nums[top-1] = nums[top - 1] - nums[top];
        } else if (token[0] == '*') {
            top--;
            nums[top-1] = nums[top - 1] * nums[top];
        } else {
            nums[top] = atoi(token);
            top++;
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", nums[0]);
    // End of Code
}
