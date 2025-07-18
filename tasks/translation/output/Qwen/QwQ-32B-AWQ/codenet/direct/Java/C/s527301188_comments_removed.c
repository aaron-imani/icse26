#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    token = strtok(buffer, " ");
    char **tokens = malloc(count * sizeof(char*));
    for (int i = 0; i < count; i++) {
        tokens[i] = token;
        token = strtok(NULL, " ");
    }
    int *nums = malloc(count * sizeof(int));
    int top = 0;
    for (int i = 0; i < count; i++) {
        char *op = tokens[i];
        if (strlen(op) == 1) {
            switch (op[0]) {
                case '+':
                    top--;
                    nums[top-1] += nums[top];
                    break;
                case '-':
                    top--;
                    nums[top-1] -= nums[top];
                    break;
                case '*':
                    top--;
                    nums[top-1] *= nums[top];
                    break;
            }
        } else {
            nums[top] = atoi(op);
            top++;
        }
    }
    printf("%d\n", nums[0]);
    free(tokens);
    free(nums);
    return 0;
} // End of Code
