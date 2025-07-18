#include <stdio.h>

int d;

int solve() {
    int ans = 0;
    for (int i = 1; i * d < 600; i++) {
        int x = i * d;
        ans += x * x * d;
    }
    return ans;
}

int main() {
    while (scanf("%d", &d) == 1) {
        printf("%d\n", solve());
    }
    return 0;
}
// End of Code
