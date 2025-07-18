#include <stdio.h>
#include <stdlib.h>

int main() {
    long long n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    long long sa = llabs(a - b);
    long long ans = 0;
    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long long AAA = ((n - a) < (a - 1)) ? (n - a) : (a - 1);
        long long BBB = ((n - b) < (b - 1)) ? (n - b) : (b - 1);
        ans = (AAA < BBB) ? AAA : BBB;
        sa -= 1;
        ans += 1;
        ans += sa / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
// End of Code
