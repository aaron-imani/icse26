#include <stdio.h>
#include <stdbool.h>

int d;

bool read() {
    if (scanf("%d", &d) != 1) {
        if (feof(stdin)) return false; // Check for end of file
        else {
            printf("Invalid input\n");
            exit(1); // Exit on invalid input
        }
    }
    return true;
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

int main(void) {
    while (read()) {
        printf("%d\n", solve());
    }
    return 0;
}
// End of Code
