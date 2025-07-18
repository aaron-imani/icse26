#include <stdio.h>

int main() {
    long long n, a, b, sa, ans, AAA, BBB;
    scanf("%lld%lld%lld", &n, &a, &b);
    sa = (a > b) ? (a - b) : (b - a);
    ans = 0;
    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        AAA = (n - a < a - 1) ? (n - a) : (a - 1);
        BBB = (n - b < b - 1) ? (n - b) : (b - 1);
        ans = (AAA < BBB) ? AAA : BBB;
        sa--;
        ans += 1;
        ans += sa / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
// End of Code
