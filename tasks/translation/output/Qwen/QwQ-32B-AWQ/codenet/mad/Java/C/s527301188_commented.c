#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    int count = 0;
    char *copy = strdup(buffer);
    char *token = strtok(copy, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(copy);

    char **tokens = malloc(count * sizeof(char *));
    copy = strdup(buffer);
    token = strtok(copy, " ");
    int i;
    for (i = 0; token != NULL; i++) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        token = strtok(NULL, " ");
    }
    free(copy);

    int stackSize = count;
    int *nums = malloc(stackSize * sizeof(int));
    int top = 0;

    for (i = 0; i < count; i++) {
        char *str = tokens[i];
        char op = str[0];
        if (op == '+' || op == '-' || op == '*') {
            top--;
            if (op == '+') {
                nums[top - 1] += nums[top];
            } else if (op == '-') {
                nums[top - 1] -= nums[top];
            } else {
                nums[top - 1] *= nums[top];
            }
        } else {
            nums[top] = atoi(str);
            top++;
        }
        free(tokens[i]);
    }

    printf("%d\n", nums[0]);

    free(tokens);
    free(nums);

    return 0;
} // End of Code
