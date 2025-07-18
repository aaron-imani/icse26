#include <stdio.h>
#include <stdbool.h>

int d;

bool read() {
    if(scanf("%d", &d) != 1) return false;
    return true;
}

int solve() {
    int ans = 0;
    for(int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    while(read()) {
        printf("%d\n", solve());
    }
    // End of Code
}
