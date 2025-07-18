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
        if (arr[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    ll left = arr[lo] - x;
    ll right = x - arr[lo - 1];
    return min(left, right);
}

void process_queries(int a, int b, int q) {
    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);
        ll sl = solve(x, s, a + 2);
        ll tl = solve(x, t, b + 2);
        ll ans = LLONG_MAX;
        ans = min(ans, max(sl, tl));
        ans = min(ans, max(solve(x + 2 * sl, s, a + 2), tl));
        ans = min(ans, max(sl, solve(x + 2 * tl, t, b + 2)));
        ans = min(ans, max(solve(x + sl, s, a + 2), solve(x + 2 * tl, t, b + 2)));
        printf("%lld\n", ans);
    }
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    s[0] = -10000000000LL;
    t[0] = -10000000000LL;
    for (int i = 1; i <= a; i++)
        scanf("%lld", &s[i]);
    for (int i = 1; i <= b; i++)
        scanf("%lld", &t[i]);

    s[a + 1] = 20000000000LL;
    t[b + 1] = 20000000000LL;

    process_queries(a, b, q);

    return 0;
}
// End of Code
