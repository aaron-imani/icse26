#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NUMBERS 100

int main() {
    char input[MAX_INPUT_LENGTH];
    fgets(input, sizeof(input), stdin);
    
    char *token = strtok(input, " ");
    int nums[MAX_NUMBERS];
    int top = 0;
    
    while (token != NULL) {
        if (token[0] == '+' || token[0] == '-' || token[0] == '*') {
            top--;
            switch (token[0]) {
                case '+':
                    nums[top-1] += nums[top];
                    break;
                case '-':
                    nums[top-1] -= nums[top];
                    break;
                case '*':
                    nums[top-1] *= nums[top];
                    break;
            }
        } else {
            nums[top] = atoi(token);
            top++;
        }
        token = strtok(NULL, " ");
    }
    
    printf("%d\n", nums[0]);
    
    return 0;
}
// End of Code
