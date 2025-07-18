#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *token;
    int nums[100];
    int top = 0;

    fgets(input, 100, stdin);
    token = strtok(input, " ");
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
    return 0;
} // End of Code
