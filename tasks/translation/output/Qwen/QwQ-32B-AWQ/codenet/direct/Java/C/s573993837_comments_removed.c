#include <stdio.h>

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    if (n == m) {
        printf("0\n");
        return 0;
    }
    if (n > m) {
        n %= m;
        long long res = (m - n < n) ? (m - n) : n;
        printf("%lld\n", res);
    } else {
        long long res = (m - n < n) ? (m - n) : n;
        printf("%lld\n", res);
    }
    return 0;
}
// End of Code
