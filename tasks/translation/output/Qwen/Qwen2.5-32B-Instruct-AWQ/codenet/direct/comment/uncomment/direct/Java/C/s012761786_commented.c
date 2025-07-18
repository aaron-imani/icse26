#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long nextLong() {
    long num;
    scanf("%ld", &num);
    return num;
}

int main() {
    long n = nextLong();
    long a = nextLong();
    long b = nextLong();

    long sa = labs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = fmin((n - a), (a - 1));
        long BBB = fmin((n - b), (b - 1));

        ans = fmin(AAA, BBB); // One side reaches the edge.

        // Reduce the difference by 1 to make it even
        sa -= 1;
        ans += 1;

        // Difference is now even
        ans += sa / 2;
    }

    printf("%ld\n", ans);

    return 0;
}

// End of Code
