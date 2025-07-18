#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    char *copy1 = strdup(buffer);
    char *token = strtok(copy1, " ");
    int token_count = 0;
    while (token != NULL) {
        token_count++;
        token = strtok(NULL, " ");
    }
    free(copy1);

    char **tokens = malloc(token_count * sizeof(char *));
    if (tokens == NULL) return 1;

    char *copy2 = strdup(buffer);
    token = strtok(copy2, " ");
    int idx = 0;
    while (token != NULL) {
        tokens[idx] = token;
        idx++;
        token = strtok(NULL, " ");
    }

    int *nums = malloc(token_count * sizeof(int));
    if (nums == NULL) {
        free(tokens);
        free(copy2);
        return 1;
    }
    int top = 0;

    for (int i = 0; i < token_count; i++) {
        char *current_token = tokens[i];
        int len = strlen(current_token);
        char first_char = current_token[0];
        if (len == 1 && (first_char == '+' || first_char == '-' || first_char == '*')) {
            top--;
            int a = nums[top - 1];
            int b = nums[top];
            switch (first_char) {
                case '+':
                    nums[top - 1] = a + b;
                    break;
                case '-':
                    nums[top - 1] = a - b;
                    break;
                case '*':
                    nums[top - 1] = a * b;
                    break;
            }
        } else {
            nums[top] = atoi(current_token);
            top++;
        }
    }

    printf("%d\n", nums[0]);

    free(nums);
    free(tokens);
    free(copy2);
    return 0;
} // End of Code
