#include <stdio.h>

int solve(int d) {
    int ans = 0;
    int i;
    for (i = 1; i * d < 600; i++) {
        ans += (i * d) * (i * d) * d;
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
