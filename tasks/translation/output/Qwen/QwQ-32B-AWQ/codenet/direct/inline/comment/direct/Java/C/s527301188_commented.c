#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    char *tokens[256];
    int token_count = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL && token_count < 256) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    int nums[token_count];
    int top = 0;

    for (int i = 0; i < token_count; i++) {
        char c = tokens[i][0];
        switch(c) {
            case '+':
                top--;
                nums[top-1] = nums[top-1] + nums[top];
                break;
            case '-':
                top--;
                nums[top-1] = nums[top-1] - nums[top];
                break;
            case '*':
                top--;
                nums[top-1] = nums[top-1] * nums[top];
                break;
            default:
                nums[top] = atoi(tokens[i]);
                top++;
                break;
        }
    }

    printf("%d\n", nums[0]);
    return 0; /* End of Code */
}
