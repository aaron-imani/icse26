#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    char *token = strtok(buffer, " ");
    int nums[100];
    int top = 0;
    while (token != NULL) {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*')) {
            top--;
            switch (token[0]) {
                case '+':
                    nums[top - 1] += nums[top];
                    break;
                case '-':
                    nums[top - 1] -= nums[top];
                    break;
                case '*':
                    nums[top - 1] *= nums[top];
                    break;
            }
        } else {
            nums[top] = atoi(token);
            top++;
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n", nums[0]);
    return 0; // End of Code
}
