#include <stdio.h>

int d;

int read() {
    int val;
    if (scanf("%d", &val) != 1) return 0;
    d = val;
    return 1;
}

int solve() {
    int ans = 0, i;
    for (i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    while (read()) {
        printf("%d\n", solve());
    }
    return 0;
}
// End of Code
