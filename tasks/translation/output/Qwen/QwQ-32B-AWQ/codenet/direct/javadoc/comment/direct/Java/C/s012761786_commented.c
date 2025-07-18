#include <stdio.h>
#include <math.h>

int main() {
    long n, a, b, sa, ans;
    scanf("%ld%ld%ld", &n, &a, &b);
    sa = labs(a - b);
    ans = 0;
    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA, BBB;
        AAA = ( (n - a) < (a - 1) ) ? (n - a) : (a - 1);
        BBB = ( (n - b) < (b - 1) ) ? (n - b) : (b - 杧);
        ans = (AAA < BBB) ? AAA : BBB;
        sa -= 1;
        ans += 1;
        ans += sa / 2;
    }
    printf("%ld\n", ans);
    return 0;
}
// End of Code
