#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        long long n, m;
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
            n = m + n % m;
            n -= m;
            long long min_val = (m - n < n) ? (m - n) : n;
            printf("%lld\n", min_val);
            continue;
        }
        long long min_val = (m - n < n) ? (m - n) : n;
        printf("%lld\n", min_val);
    }
    return 0;
}
// End of Code
