#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("No\n");
        return 0;
    }
    int num;
    scanf("%d", &num);
    int sum = num;
    int max = num;
    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        sum += num;
        if (num > max) {
            max = num;
        }
    }
    if (sum > 2 * max) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// End of Code
