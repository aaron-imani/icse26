#include <stdio.h>

void solve() {
    int t = 1;
    while (t--) {
        long n, m;
        scanf("%ld %ld", &n, &m);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        if (n == m) {
            printf("0\n");
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            printf("%ld\n", (m - n < n) ? m - n : n);
            continue;
        }
        printf("%ld\n", (m - n < n) ? m - n : n);
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
