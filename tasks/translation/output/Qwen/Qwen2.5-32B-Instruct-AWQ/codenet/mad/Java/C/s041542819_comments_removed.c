#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

long min(long *v, int n) {
    long min_val = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < min_val) {
            min_val = v[i];
        }
    }
    return min_val;
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

int lowerBound(long *a, long t, int size) {
    return lowerBound(a, t, 0, size);
}

void solve(int testNumber, FILE *in, FILE *out) {
    int a, b, q;
    fscanf(in, "%d %d %d", &a, &b, &q);
    long *s = malloc((a + 2) * sizeof(long));
    long *t = malloc((b + 2) * sizeof(long));
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
        long sl = x - s[MAX(0, lowerBound(s, x + 1, a + 2) - 1)];
        long tl = x - t[MAX(0, lowerBound(t, x + 1, b + 2) - 1)];
        long sr = s[lowerBound(s, x, a + 2)] - x;
        long tr = t[lowerBound(t, x, b + 2)] - x;
        long values[6] = {
            MAX(sl, tl),
            MAX(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        };
        fprintf(out, "%ld\n", min(values, 6));
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
