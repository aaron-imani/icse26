#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long min(long a, long b, long c, long d, long e, long f) {
    return MIN(MIN(MIN(MIN(MIN(a, b), c), d), e), f);
}

int lowerBound(long *a, long t, int min, int max) {
    while (min < max) {
        int mid = (min + max) / 2;
        if (t <= a[mid]) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    return min;
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    long *s = malloc((a + 2) * sizeof(long));
    long *t = malloc((b + 2) * sizeof(long));

    s[0] = t[0] = -10000000000;
    for (int i = 0; i < a; i++) {
        scanf("%ld", &s[i + 1]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%ld", &t[i + 1]);
    }
    s[a + 1] = t[b + 1] = 20000000000;

    for (int i = 0; i < q; i++) {
        long x;
        scanf("%ld", &x);

        long sl = x - s[MAX(0, lowerBound(s, x + 1, 0, a + 2) - 1)];
        long tl = x - t[MAX(0, lowerBound(t, x + 1, 0, b + 2) - 1)];
        long sr = s[lowerBound(s, x, 0, a + 2)] - x;
        long tr = t[lowerBound(t, x, 0, b + 2)] - x;

        long result = min(
            MAX(sl, tl),
            MAX(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        );

        printf("%ld\n", result);
    }

    free(s);
    free(t);
    return 0;
}
// End of Code
