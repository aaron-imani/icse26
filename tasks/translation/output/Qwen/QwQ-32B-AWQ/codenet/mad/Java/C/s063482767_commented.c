#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("No\n");
        return 0;
    }
    int sum = 0;
    int max;
    scanf("%d", &max);
    sum = max;
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);
        sum += num;
        if (num > max) {
            max = num;
        }
    }
    if (max < (sum - max)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// End of Code
