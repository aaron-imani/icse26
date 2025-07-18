#include <stdio.h>

int lower_bound(long long *arr, int len, long long target) {
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

    long long s[a + 2];
    s[0] = -10000000000LL;
    for (int i = 0; i < a; i++) {
        scanf("%lld", &s[i + 1]);
    }
    s[a + 1] = 20000000000LL;

    long long t[b + 2];
    t[0] = -10000000000LL;
    for (int i = 0; i < b; i++) {
        scanf("%lld", &t[i + 1]);
    }
    t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);

        int pos_s = lower_bound(s, a + 2, x + 1);
        int idx_s = pos_s - 1;
        if (idx_s < 0) idx_s = 0;
        long long sl = x - s[idx_s];

        int pos_t = lower_bound(t, b + 2, x + 1);
        int idx_t = pos_t - 1;
        if (idx_t < 0) idx_t = 0;
        long long tl = x - t[idx_t];

        int pos_s2 = lower_bound(s, a + 2, x);
        long long sr = s[pos_s2] - x;

        int pos_t2 = lower_bound(t, b + 2, x);
        long long tr = t[pos_t2] - x;

        long long candidates[6];
        candidates[0] = (sl > tl) ? sl : tl;
        candidates[1] = (sr > tr) ? sr : tr;
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

    return 0;
}
// End of Code
