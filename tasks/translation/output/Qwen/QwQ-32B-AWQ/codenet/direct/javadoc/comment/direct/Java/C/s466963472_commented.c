#include <stdio.h>

int solve(int d) {
    int ans = 0;
    for (int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    int d;
    while (scanf("%d", &d) == 1) {
        printf("%d\n", solve(d));
    }
    return 0;
}
// End of Code
