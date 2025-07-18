#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100005

int lowerBound(long long *a, int n, long long t) {
    int min = 0, max = n;
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

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long min_of_array(long long *arr, int size) {
    long long min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);
    long long s[MAX_N], t[MAX_N];
    s[0] = t[0] = -10000000000LL;
    for (int i = 0; i < a; i++) {
        scanf("%lld", &s[i + 1]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%lld", &t[i + 1]);
    }
    s[a + 1] = t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);
        long long sl = x - s[max(0, lowerBound(s, a + 2, x + 1) - 1)];
        long long tl = x - t[max(0, lowerBound(t, b + 2, x + 1) - 1)];
        long long sr = s[lowerBound(s, a + 2, x)] - x;
        long long tr = t[lowerBound(t, b + 2, x)] - x;
        long long values[6] = {
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        };
        printf("%lld\n", min_of_array(values, 6));
    }

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}
// End of Code
