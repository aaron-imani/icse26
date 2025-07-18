#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    int nums[100];
    int top = 0;

    while (token != NULL) {
        switch (token[0]) {
            case '+':
                top--;
                nums[top-1] = nums[top - 1] + nums[top];
                break;
            case '-':
                top--;
                nums[top-1] = nums[top - 1] - nums[top];
                break;
            case '*':
                top--;
                nums[top-1] = nums[top - 1] * nums[top];
                break;
            default:
                nums[top] = atoi(token);
                top++;
                break;
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", nums[0]); // End of Code
