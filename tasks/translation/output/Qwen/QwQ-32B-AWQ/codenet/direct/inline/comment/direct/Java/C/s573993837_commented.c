#include <stdio.h>

int main() {
    long long n, m;
    int t = 1;
    while (t-- > 0) {
        scanf("%lld %lld", &n, &m);
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
            long long min_val = (m - n) < n ? (m - n) : n;
            printf("%lld\n", min_val);
            continue;
        }
        long long min_val = (m - n) < n ? (m - n) : n;
        printf("%lld\n", min_val);
    }
    return 0;
} // End of Code
