#include <stdio.h>

long long nextLong() {
    long long val;
    scanf("%lld", &val);
    return val;
}

int main() {
    long long n = nextLong();
    long long a = nextLong();
    long long b = nextLong();

    long long sa = (a > b) ? (a - b) : (b - a);
    long long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long long AAA = ( (n - a) < (a - 1) ) ? (n - a) : (a - 1);
        long long BBB = ( (n - b) < (b - 1) ) ? (n - b) : (b - 1);
        ans = (AAA < BBB) ? AAA : BBB;

        sa -= 1;
        ans += 1;
        ans += sa / 2;
    }

    printf("%lld\n", ans);
    return 0;
}

// End of Code
