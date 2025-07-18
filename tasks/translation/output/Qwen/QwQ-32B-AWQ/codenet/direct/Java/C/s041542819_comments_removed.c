#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long *arr, int len, long long target) {
    int min = 0, max = len;
    while (min < max) {
        int mid = (min + max) / 2;
        if (arr[mid] >= target) {
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

    long long *s = malloc((a + 2) * sizeof(long long));
    s[0] = -10000000000LL;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }
    s[a + 1] = 20000000000LL;

    long long *t = malloc((b + 2) * sizeof(long long));
    t[0] = -10000000000LL;
    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }
    t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);

        int pos_s_plus = lower_bound(s, a + 2, x + 1);
        int prev_s = pos_s_plus - 1;
        if (prev_s < 0) prev_s = 0;
        long long sl = x - s[prev_s];

        int pos_t_plus = lower_bound(t, b + 2, x + 1);
        int prev_t = pos_t_plus - 1;
        if (prev_t < 0) prev_t = 0;
        long long tl = x - t[prev_t];

        int pos_s_x = lower_bound(s, a + 2, x);
        long long sr = s[pos_s_x] - x;

        int pos_t_x = lower_bound(t, b + 2, x);
        long long tr = t[pos_t_x] - x;

        long long terms[6];
        terms[0] = (sl > tl) ? sl : tl;
        terms[1] = (sr > tr) ? sr : tr;
        terms[2] = 2 * sl + tr;
        terms[3] = 2 * tl + sr;
        terms[4] = sl + 2 * tr;
        terms[5] = tl + 2 * sr;

        long long min_val = terms[0];
        for (int j = 1; j < 6; j++) {
            if (terms[j] < min_val) min_val = terms[j];
        }

        printf("%lld\n", min_val);
    }

    free(s);
    free(t);
    return 0;
}
// End of Code
