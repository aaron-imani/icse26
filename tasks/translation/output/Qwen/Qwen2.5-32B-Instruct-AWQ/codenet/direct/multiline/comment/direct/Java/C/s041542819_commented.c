#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef long long ll;

ll s[MAXN], t[MAXN];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll solve(ll x, ll *a, int alen, ll *b, int blen) {
    int ai = 0, bi = 0;
    while (ai < alen && a[ai] < x) ai++;
    while (bi < blen && b[bi] < x) bi++;

    ll sl = x - a[ai - 1];
    ll sr = a[ai] - x;
    ll tl = x - b[bi - 1];
    ll tr = b[bi] - x;

    return min(min(min(min(min(min(
        max(sl, tl),
        max(sr, tr),
        2 * sl + tr,
        2 * tl + sr,
        sl + 2 * tr,
        tl + 2 * sr
    ), 0), 0), 0), 0), 0);
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

    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);
        printf("%lld\n", solve(x, s, a + 2, t, b + 2));
    }

    return 0;
}

// End of Code
