#include <stdio.h>

int d;

int read() {
    // Check if the input is a valid integer
    if (scanf("%d", &d) != 1) {
        return 0;
    }
    return 1;
}

int solve() {
    int ans = 0;
    for (int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    // Continuously read and process input until EOF or invalid input
    while (read()) {
        printf("%d\n", solve());
    }
    // End of Code
    return 0;
}
