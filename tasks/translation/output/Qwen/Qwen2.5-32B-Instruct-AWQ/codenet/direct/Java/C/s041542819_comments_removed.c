#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

void solve(int testNumber, long *s, long *t, int a, int b, int q) {
    for (int i = 0; i < q; i++) {
        long x;
        scanf("%ld", &x);
        long sl = x - s[MAX(0, lowerBound(s, x + 1, 0) - 1)];
        long tl = x - t[MAX(0, lowerBound(t, x + 1, 0) - 1)];
        long sr = s[lowerBound(s, x, 0)] - x;
        long tr = t[lowerBound(t, x, 0)] - x;
        long minVal = LONG_MAX;
        minVal = MIN(minVal, MAX(sl, tl));
        minVal = MIN(minVal, MAX(sr, tr));
        minVal = MIN(minVal, 2 * sl + tr);
        minVal = MIN(minVal, 2 * tl + sr);
        minVal = MIN(minVal, sl + 2 * tr);
        minVal = MIN(minVal, tl + 2 * sr);
        printf("%ld\n", minVal);
    }
}

int lowerBound(long *a, long t, int min) {
    int max = sizeof(a) / sizeof(a[0]);
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
    long *s = (long *)malloc((a + 2) * sizeof(long));
    long *t = (long *)malloc((b + 2) * sizeof(long));
    s[0] = t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        scanf("%ld", &s[i + 1]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%ld", &t[i + 1]);
    }
    s[a + 1] = t[b + 1] = 20000000000L;
    solve(1, s, t, a, b, q);
    free(s);
    free(t);
    return 0;
}
// End of Code
