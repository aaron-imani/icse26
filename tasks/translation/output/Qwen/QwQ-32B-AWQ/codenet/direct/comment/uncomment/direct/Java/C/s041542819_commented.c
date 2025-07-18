#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lower_bound(long long arr[], int n, long long t) {
    int low = 0, high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < t) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    long long *s = malloc((a + 2) * sizeof(long long));
    long long *t = malloc((b + 2) * sizeof(long long));

    s[0] = -10000000000LL;
    s[a + 1] = 20000000000LL;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }

    t[0] = -10000000000LL;
    t[b + 1] = 20000000000LL;
    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }

    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);

        int s_lb = lower_bound(s, a + 2, x + 1);
        int s_prev_idx = s_lb - 1;
        s_prev_idx = s_prev_idx < 0 ? 0 : s_prev_idx;
        long long sl = x - s[s_prev_idx];

        int t_lb = lower_bound(t, b + 2, x + 1);
        int t_prev_idx = t_lb - 1;
        t_prev_idx = t_prev_idx < 0 ? 0 : t_prev_idx;
        long long tl = x - t[t_prev_idx];

        int s_next = lower_bound(s, a + 2, x);
        long long sr = s[s_next] - x;

        int t_next = lower_bound(t, b + 2, x);
        long long tr = t[t_next] - x;

        long long candidates[6];
        candidates[0] = MAX(sl, tl);
        candidates[1] = MAX(sr, tr);
        candidates[2] = 2 * sl + tr;
        candidates[3] = 2 * tl + sr;
        candidates[4] = sl + 2 * tr;
        candidates[5] = tl + 2 * sr;

        long long min_val = candidates[0];
        for (int j = 1; j < 6; j++) {
            if (candidates[j] < min_val) {
                min_val = candidates[j];
            }
        }

        printf("%lld\n", min_val);
    }

    free(s);
    free(t);
    return 0;
}
// End of Code
