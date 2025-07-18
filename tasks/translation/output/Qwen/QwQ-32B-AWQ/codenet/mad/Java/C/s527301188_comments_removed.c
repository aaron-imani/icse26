#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    char *copy = strdup(buffer);
    char *token = strtok(copy, " ");
    int token_count = 0;
    while (token != NULL) {
        token_count++;
        token = strtok(NULL, " ");
    }
    free(copy);

    char **tokens = malloc(token_count * sizeof(char *));
    copy = strdup(buffer);
    token = strtok(copy, " ");
    for (int i = 0; i < token_count; i++) {
        tokens[i] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(copy);

    int *nums = malloc(token_count * sizeof(int));
    int top = 0;

    for (int i = 0; i < token_count; i++) {
        char c = tokens[i][0];
        switch (c) {
            case '+':
                top--;
                nums[top - 1] += nums[top];
                break;
            case '-':
                top--;
                nums[top - 1] -= nums[top];
                break;
            case '*':
                top--;
                nums[top - 1] *= nums[top];
                break;
            default:
                nums[top] = atoi(tokens[i]);
                top++;
                break;
        }
    }

    printf("%d\n", nums[0]);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(nums);

    return 0;
} // End of Code
