#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    char *token;
    char *saveptr;
    int n = 0;

    // Count the number of tokens
    token = strtok_r(buffer, " ", &saveptr);
    while (token != NULL) {
        n++;
        token = strtok_r(NULL, " ", &saveptr);
    }

    // Allocate array for tokens
    char **tokens = (char **)malloc(n * sizeof(char *));
    if (!tokens) {
        return 1;
    }

    // Reset the strtok state to re-split the buffer
    token = strtok_r(buffer, " ", &saveptr);
    int i = 0;
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok_r(NULL, " ", &saveptr);
    }

    int nums[n];
    int top = 0;

    for (i = 0; i < n; i++) {
        char *str = tokens[i];
        if (str[0] == '+' || str[0] == '-' || str[0] == '*') {
            top--;
            int a = nums[top - 1];
            int b = nums[top];
            int result;
            switch (str[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
            }
            nums[top - 1] = result;
        } else {
            nums[top] = atoi(str);
            top++;
        }
    }

    free(tokens);
    printf("%d\n", nums[0]);
    return 0;
}
// End of Code
