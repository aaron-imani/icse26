#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char *copy_count = strdup(buffer);
    int token_count = 0;
    char *token_ptr = strtok(copy_count, " ");
    while (token_ptr != NULL) {
        token_count++;
        token_ptr = strtok(NULL, " ");
    }
    free(copy_count);

    char **tokens = malloc(token_count * sizeof(char*));
    char *copy_split = strdup(buffer);
    token_ptr = strtok(copy_split, " ");
    for (int i = 0; i < token_count; i++) {
        tokens[i] = strdup(token_ptr);
        token_ptr = strtok(NULL, " ");
    }
    free(copy_split);

    int nums[token_count];
    int top = 0;
    for (int i = 0; i < token_count; i++) {
        char *token = tokens[i];
        switch (token[0]) {
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
            default:
                nums[top] = atoi(token);
                top++;
                break;
        }
    }

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);

    printf("%d\n", nums[0]);
    return 0;
}
// End of Code
