#include <stdio.h>
#include <stdlib.h>

int lower_bound(long long *arr, int n, long long target) {
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
    
    long long *s = malloc((a + 2) * sizeof(long long));
    long long *t = malloc((b + 2) * sizeof(long long));
    
    s[0] = -10000000000LL;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }
    s[a + 1] = 20000000000LL;
    
    t[0] = -10000000000LL;
    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }
    t[b + 1] = 20000000000LL;
    
    for (int i = 0; i < q; i++) {
        long long x;
        scanf("%lld", &x);
        
        int idx_s_prev = lower_bound(s, a + 2, x + 1) - 1;
        if (idx_s_prev < 0) idx_s_prev = 0;
        long long sl = x - s[idx_s_prev];
        
        int idx_t_prev = lower_bound(t, b + 2, x + 1) - 1;
        if (idx_t_prev < 0) idx_t_prev = 0;
        long long tl = x - t[idx_t_prev];
        
        int idx_s_next = lower_bound(s, a + 2, x);
        long long sr = s[idx_s_next] - x;
        
        int idx_t_next = lower_bound(t, b + 2, x);
        long long tr = t[idx_t_next] - x;
        
        long long candidates[6];
        candidates[0] = (sl > tl) ? sl : tl;
        candidates[1] = (sr > tr) ? sr : tr;
        candidates[2] = 2 * sl + tr;
        candidates[3] = 2 * tl + sr;
        candidates[4] = sl + 2 * tr;
        candidates[5] = tl + 2 * sr;
        
        long long min_val = candidates[0];
        for (int j = 1; j < 6; j++) {
            if (candidates[j] < min_val) min_val = candidates[j];
        }
        printf("%lld\n", min_val);
    }
    
    free(s);
    free(t);
    return 0;
}
// End of Code
