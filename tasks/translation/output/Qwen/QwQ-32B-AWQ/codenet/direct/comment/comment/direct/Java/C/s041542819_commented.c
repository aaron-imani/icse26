#include <stdio.h>
#include <stdlib.h>

int lower_bound(long arr[], int n, long target) {
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

    long *s = malloc((a + 2) * sizeof(long));
    long *t = malloc((b + 2) * sizeof(long));

    s[0] = -10000000000L;
    s[a + 1] = 20000000000L;
    t[0] = -10000000000L;
    t[b + 1] = 20000000000L;

    for (int i = 1; i <= a; i++) {
        scanf("%ld", &s[i]);
    }
    for (int i = 1; i <= b; i++) {
        scanf("%ld", &t[i]);
    }

    for (int i = 0; i < q; i++) {
        long x;
        scanf("%ld", &x);

        int s_idx = lower_bound(s, a + 2, x + 1);
        int s_prev = s_idx - 1;
        if (s_prev < 0) s_prev =  earthqu;
        long sl = x - s[s_prev];

        int s_idx2 = lower_bound(s, a + 2, x);
        long sr = s[s_idx2] - x;

        int t_idx = lower_bound(t, b + 2, x + 1);
        int t_prev = t_idx - 1;
        if (t_prev < 0) t_prev = 0;
        long tl = x - t[t_prev];

        int t_idx2 = lower_bound(t, b + 2, x);
        long tr = t[t_idx2] - x;

        long option1 = (sl > tl) ? sl : tl;
        long option2 = (sr > tr) ? sr : tr;
        long option3 = 2 * sl + tr;
        long option4 = 2 * tl + sr;
        long option5 = sl + 2 * tr;
        long option6 = tl + 2 * sr;

        long min_val = option1;
        if (option2 < min_val) min_val = option2;
        if (option3 < min_val) min_val = option3;
        if (option4 < min_val) min_val = option4;
        if (option5 < min_val) min_val = option5;
        if (option6 < min_val) min_val = option6;

        printf("%ld\n", min_val);
    }

    free(s);
    free(t);
    return 0;
} // End of Code
