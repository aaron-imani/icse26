#include <stdio.h>

void solve() {
    int t = 1;
    while (t-- > 0) {
        long long n, m;
        if (scanf("%lld %lld", &n, &m) != 2) {
            return;
        }
        if (n == 0) {
            printf("0\n");
            continue;
        }
        if (n == m) {
            printf("0\n");
            continue;
        }
        if (n > m) {
            n %= m;
        }
        long long min_val = (m - n < n) ? (m - n) : n;
        printf("%lld\n", min_val);
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
