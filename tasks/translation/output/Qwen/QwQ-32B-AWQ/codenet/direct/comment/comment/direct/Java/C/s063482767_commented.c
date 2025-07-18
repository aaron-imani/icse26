#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int max = 0;
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
        if (num > max) {
            max = num;
        }
    }
    printf("%s\n", sum > 2 * max ? "Yes" : "No");
    return 0;
}
// End of Code
i < n - 1; i++) {
        sum += arr[i];
    }
    
    printf(arr[n - 1] < sum ? "Yes\n" : "No\n");
    
    return 0;
}
// End of Code
