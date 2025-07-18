#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef long long ll;

ll s[MAXN], t[MAXN];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll abs(ll x) {
    return x > 0 ? x : -x;
}

ll lower_bound(ll *a, ll n, ll t) {
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

void solve(int a, int b, int q) {
    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);
        ll idx_s = lower_bound(s, a + 2, x);
        ll idx_t = lower_bound(t, b + 2, x);
        ll sl = abs(x - s[idx_s - 1]);
        ll sr = abs(s[idx_s] - x);
        ll tl = abs(x - t[idx_t - 1]);
        ll tr = abs(t[idx_t] - x);
        ll ans = min(min(max(sl, tl), max(sr, tr)),
                     min(2 * sl + tr, 2 * tl + sr));
        ans = min(ans, min(sl + 2 * tr, tl + 2 * sr));
        printf("%lld\n", ans);
    }
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    s[0] = t[0] = -10000000000LL;
    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }
    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }
    s[a + 1] = t[b + 1] = 20000000000LL;

    solve(a, b, q);

    return 0;
}
// End of Code
