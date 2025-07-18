#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    int count = 0;
    char *save_ptr;
    char *token = strtok_r(buffer, " ", &save_ptr);
    while (token != NULL) {
        count++;
        token = strtok_r(NULL, " ", &save_ptr);
    }

    int *nums = malloc(count * sizeof(int));
    if (!nums) {
        return 1;
    }

    int top = 0;
    char *save_ptr2 = NULL;
    token = strtok_r(buffer, " ", &save_ptr2);
    for (int i = 0; i < count; i++) {
        char *current_token = token;
        switch (current_token[0]) {
            case '+':
                top--;
                nums[top - 1] = nums[top - 1] + nums[top];
                break;
            case '-':
                top--;
                nums[top - 1] = nums[top - 1] - nums[top];
                break;
            case '*':
                top--;
                nums[top - 1] = nums[top - 1] * nums[top];
                break;
            default:
                nums[top] = atoi(current_token);
                top++;
                break;
        }
        token = strtok_r(NULL, " ", &save_ptr2);
    }

    printf("%d\n", nums[0]);
    free(nums);
    return 0;
} // End of Code
