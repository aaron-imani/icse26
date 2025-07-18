#include <stdio.h>
#include <stdlib.h>

int main() {
    long n, a, b, sa, ans;
    scanf("%ld", &n);
    scanf("%ld", &a);
    scanf("%ld", &b);

    sa = labs(a - b);

    ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = (n - a) < (a - 1) ? (n - a) : (a - 1);
        long BBB = (n - b) < (b - 1) ? (n - b) : (b - 1);
        ans = (AAA < BBB) ? AAA : BBB;

        sa -= 1;
        ans += 1;
        ans += sa / 2;
    }

    printf("%ld\n", ans);

    return 0;
}
// End of Code
