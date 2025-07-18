#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    char *copy = strdup(buffer);
    char *saveptr;
    char *token = strtok_r(copy, " ", &saveptr);
    int num_tokens = 0;
    while (token) {
        num_tokens++;
        token = strtok_r(NULL, " ", &saveptr);
    }
    free(copy);

    int *stack = malloc(num_tokens * sizeof(int));
    if (!stack) return 1;
    int top = 0;

    copy = strdup(buffer);
    token = strtok_r(copy, " ", &saveptr);
    while (token) {
        if (token[0] == '+' || token[0] == '-' || token[0] == '*') {
            top--;
            switch (token[0]) {
                case '+':
                    stack[top - 1] += stack[top];
                    break;
                case '-':
                    stack[top - 1] -= stack[top];
                    break;
                case '*':
                    stack[top - 1] *= stack[top];
                    break;
            }
        } else {
            stack[top] = atoi(token);
            top++;
        }
        token = strtok_r(NULL, " ", &saveptr);
    }

    printf("%d\n", stack[0]);
    free(stack);
    free(copy);
    return 0;
} // End of Code
