#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[1024];
    fgets(line, sizeof(line), stdin);

    int token_count = 0;
    char *p = line;
    while (*p != '\0') {
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0') break;
        token_count++;
        while (*p != ' ' && *p != '\t' && *p != '\0') p++;
    }

    char **tokens = (char**)malloc(token_count * sizeof(char*));
    if (!tokens) return 1;

    p = line;
    int i = 0;
    char *token = strtok(p, " ");
    while (token) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    int nums[token_count];
    int top = 0;
    for (i = 0; i < token_count; i++) {
        char op = tokens[i][0];
        if (op == '+' || op == '-' || op == '*') {
            top--;
            switch (op) {
                case '+':
                    nums[top-1] = nums[top-1] + nums[top];
                    break;
                case '-':
                    nums[top-1] = nums[top-1] - nums[top];
                    break;
                case '*':
                    nums[top-1] = nums[top-1] * nums[top];
                    break;
            }
        } else {
            nums[top] = atoi(tokens[i]);
            top++;
        }
    }

    free(tokens);
    printf("%d\n", nums[0]);
    return 0;
}
// End of Code
