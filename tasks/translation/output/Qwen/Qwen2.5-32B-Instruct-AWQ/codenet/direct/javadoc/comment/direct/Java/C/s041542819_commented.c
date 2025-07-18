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

ll solve(ll x, ll *arr, int len) {
    int lo = 0, hi = len - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    ll leftDist = abs(x - arr[lo]);
    ll rightDist = abs(arr[lo + 1] - x);
    return min(leftDist, rightDist);
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));

    s[0] = -10000000000LL;
    t[0] = -10000000000LL;

    for (int i = 1; i <= a; i++) {
        scanf("%lld", &s[i]);
    }

    for (int i = 1; i <= b; i++) {
        scanf("%lld", &t[i]);
    }

    s[a + 1] = 20000000000LL;
    t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);

        ll sl = solve(x, s, a + 2);
        ll tl = solve(x, t, b + 2);
        ll sr = solve(x, s, a + 2);
        ll tr = solve(x, t, b + 2);

        ll ans = min(min(max(sl, tl), max(sr, tr)),
                     min(2 * sl + tr, 2 * tl + sr));
        ans = min(ans, min(sl + 2 * tr, tl + 2 * sr));

        printf("%lld\n", ans);
    }

    return 0;
} // End of Code
