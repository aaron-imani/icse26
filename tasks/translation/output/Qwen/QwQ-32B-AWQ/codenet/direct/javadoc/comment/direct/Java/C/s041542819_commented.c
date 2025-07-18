#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long arr[], int len, long long target) {
    int low = 0, high = len;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) {
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
    s[0] = -10000000000LL;
    for (int i = 0; i < a; i++) {
        scanf("%lld", &s[i + 1]);
    }
    s[a + 1] = 20000000000LL;
    long long *t = malloc((b + 2) * sizeof(long long));
    t[0] = -10000000000LL;
    for (int i = 0; i < b; i++) {
        scanf("%lld", &t[i + 1]);
    }
    t[b + 1] = 20000000000LL;
    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);
        int pos_s_plus = lower_bound(s, a + 2, x + 1);
        int s_prev_idx = pos_s_plus - 1;
        if (s_prev_idx < 0) s_prev_idx = 0;
        long long s_prev = s[s_prev_idx];
        long long sl = x - s_prev;
        int pos_t_plus = lower_bound(t, b + 2, x + 1);
        int t_prev_idx = pos_t_plus - 1;
        if (t_prev_idx < 0) t_prev_idx = 0;
        long long t_prev = t[t_prev_idx];
        long long tl = x - t_prev;
        int pos_s_x = lower_bound(s, a + 2, x);
        long long sr = s[pos_s_x] - x;
        int pos_t_x = lower_bound(t, b + 2, x);
        long long tr = t[pos_t_x] - x;
        long long term1 = (sl > tl) ? sl : tl;
        long long term2 = (sr > tr) ? sr : tr;
        long long term3 = 2 * sl + tr;
        long long term4 = 2 * tl + sr;
        long long term5 = sl + 2 * tr;
        long long term6 = tl + 2 * sr;
        long long min_val = term1;
        if (term2 < min_val) min_val = term2;
        if (term3 < min_val) min_val = term3;
        if (term4 < min_val) min_val = term4;
        if (term5 < min_val) min_val = term5;
        if (term6 < min_val) min_val = term6;
        printf("%lld\n", min_val);
    }
    free(s);
    free(t);
    return 0;
}
// End of Code
