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
        long long remainder = n % m;
        long long min_val = remainder < (m - remainder) ? remainder : (m - remainder);
        printf("%lld\n", min_val);
    } else {
        long long diff = m - n;
        long long min_val = (diff < n) ? diff : n;
        printf("%lld\n", min_val);
    }
    return 0;
} // End of Code
