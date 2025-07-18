#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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

void solve(int testNumber, FILE *in, FILE *out) {
    int a, b, q;
    fscanf(in, "%d %d %d", &a, &b, &q);
    long *s = (long *)malloc((a + 2) * sizeof(long));
    long *t = (long *)malloc((b + 2) * sizeof(long));
    s[0] = t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        fscanf(in, "%ld", &s[i + 1]);
    }
    for (int i = 0; i < b; i++) {
        fscanf(in, "%ld", &t[i + 1]);
    }
    s[a + 1] = t[b + 1] = 20000000000L;
    for (int i = 0; i < q; i++) {
        long x;
        fscanf(in, "%ld", &x);
        long sl = x - s[MAX(0, lowerBound(s, x + 1, 0, a + 2) - 1)];
        long tl = x - t[MAX(0, lowerBound(t, x + 1, 0, b + 2) - 1)];
        long sr = s[lowerBound(s, x, 0, a + 2)] - x;
        long tr = t[lowerBound(t, x, 0, b + 2)] - x;
        long minVal = MIN(MAX(sl, tl), MAX(sr, tr));
        minVal = MIN(minVal, 2 * sl + tr);
        minVal = MIN(minVal, 2 * tl + sr);
        minVal = MIN(minVal, sl + 2 * tr);
        minVal = MIN(minVal, tl + 2 * sr);
        fprintf(out, "%ld\n", minVal);
    }
    free(s);
    free(t);
}

int main() {
    FILE *in = stdin;
    FILE *out = stdout;
    solve(1, in, out);
    return 0;
}
// End of Code
