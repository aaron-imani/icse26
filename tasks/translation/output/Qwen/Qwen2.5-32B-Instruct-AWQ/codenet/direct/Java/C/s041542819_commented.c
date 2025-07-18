#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void solve(int a, int b, int q, long long *s, long long *t, long long *x) {
    long long min_value = LLONG_MAX;
    for (int i = 0; i < q; i++) {
        long long sl = x[i] - s[MAX(0, lower_bound(s, x[i] + 1, a + 2) - 1)];
        long long tl = x[i] - t[MAX(0, lower_bound(t, x[i] + 1, b + 2) - 1)];
        long long sr = s[lower_bound(s, x[i], a + 2)] - x[i];
        long long tr = t[lower_bound(t, x[i], b + 2)] - x[i];
        min_value = MIN(min_value, MAX(sl, tl));
        min_value = MIN(min_value, MAX(sr, tr));
        min_value = MIN(min_value, 2 * sl + tr);
        min_value = MIN(min_value, 2 * tl + sr);
        min_value = MIN(min_value, sl + 2 * tr);
        min_value = MIN(min_value, tl + 2 * sr);
        printf("%lld\n", min_value);
        min_value = LLONG_MAX;
    }
}

int lower_bound(long long *arr, long long target, int n) {
    int min = 0, max = n;
    while (min < max) {
        int mid = (min + max) / 2;
        if (target <= arr[mid]) {
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
    long long *s = (long long *)malloc((a + 2) * sizeof(long long));
    long long *t = (long long *)malloc((b + 2) * sizeof(long long));
    long long *x = (long long *)malloc(q * sizeof(long long));

    s[0] = t[0] = -10000000000LL;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }
    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }
    s[a + 1] = t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; i++) {
        scanf("%lld", &x[i]);
    }

    solve(a, b, q, s, t, x);

    free(s);
    free(t);
    free(x);

    return 0;
}
// End of Code
