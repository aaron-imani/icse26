#include <stdio.h>
#include <stdlib.h>

int lower_bound(long arr[], int n, long target) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    long *s = malloc((a + 2) * sizeof(long));
    long *t = malloc((b + 2) * sizeof(long));

    s[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        scanf("%ld", &s[i + 1]);
    }
    s[a + 1] = 20000000000L;

    t[0] = -10000000000L;
    for (int i = 0; i < b; i++) {
        scanf("%ld", &t[i + 1]);
    }
    t[b + 1] = 20000000000L;

    for (int i = 0; i < q; i++) {
        long x;
        scanf("%ld", &x);

        int s_idx = lower_bound(s, a + 2, x + 1);
        int prev_s = s_idx - 1;
        if (prev_s < 0) prev_s = 0;
        long sl = x - s[prev_s];

        int t_idx = lower_bound(t, b + 2, x + 1);
        int prev_t = t_idx - 1;
        if (prev_t < 0) prev_t = 0;
        long tl = x - t[prev_t];

        int s_next_idx = lower_bound(s, a + 2, x);
        long sr = s[s_next_idx] - x;

        int t_next_idx = lower_bound(t, b + 2, x);
        long tr = t[t_next_idx] - x;

        long candidates[6];
        candidates[0] = (sl > tl) ? sl : tl;
        candidates[1] = (sr > tr) ? sr : tr;
        candidates[2] = 2 * sl + tr;
        candidates[3] = 2 * tl + sr;
        candidates[4] = sl + 2 * tr;
        candidates[5] = tl + 2 * sr;

        long min_val = candidates[0];
        for (int j = 1; j < 6; j++) {
            if (candidates[j] < min_val) min_val = candidates[j];
        }

        printf("%ld\n", min_val);
    }

    free(s);
    free(t);
    return 0;
} // End of Code
