#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    char *strs[100];
    int nums[100];
    int top = 0;

    strs[0] = strtok(input, " ");
    while (strs[top] != NULL) {
        switch (strs[top][0]) {
            case '+':
                top--;
                nums[top-1] = nums[top - 1] + nums[top];
                break;
            case '-':
                top--;
                nums[top-1] = nums[top - 1] - nums[top];
                break;
            case '*':
                top--;
                nums[top-1] = nums[top - 1] * nums[top];
                break;
            default:
                nums[top] = atoi(strs[top]);
                top++;
                break;
        }
        strs[++top] = strtok(NULL, " ");
    }

    printf("%d\n", nums[0]);

    return 0;
}
// End of Code
