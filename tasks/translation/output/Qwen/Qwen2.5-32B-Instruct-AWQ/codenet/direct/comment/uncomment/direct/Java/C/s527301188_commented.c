#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);
    char *token = strtok(input, " ");
    int nums[MAX_SIZE];
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
    return 0;
} // End of Code
