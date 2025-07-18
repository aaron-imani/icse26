#include <stdio.h>

int d;

int read() {
    if (scanf("%d", &d) != 1) {
        // Clear the input buffer if scanf fails
        while (getchar() != '\n');
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
    while (1) {
        if (!read()) {
            printf("Invalid input or end of file.\n");
            break;
        }
        printf("%d\n", solve());
    }
    // End of Code
}
