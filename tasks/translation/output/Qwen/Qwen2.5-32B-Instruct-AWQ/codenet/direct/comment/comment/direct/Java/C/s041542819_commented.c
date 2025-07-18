#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

typedef long long ll;

ll s[MAXN], t[MAXN];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll solve(ll x, ll a, ll b) {
    ll sl = x - s[a];
    ll tl = x - t[b];
    ll sr = s[a + 1] - x;
    ll tr = t[b + 1] - x;
    return min(min(max(sl, tl), max(sr, tr)),
               min(2 * sl + tr, 2 * tl + sr,
                   sl + 2 * tr, tl + 2 * sr));
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);

    s[0] = t[0] = -10000000000LL;
    for (int i = 1; i <= a; ++i) {
        scanf("%lld", &s[i]);
    }
    for (int i = 1; i <= b; ++i) {
        scanf("%lld", &t[i]);
    }
    s[a + 1] = t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; ++i) {
        ll x;
        scanf("%lld", &x);
        int sa = 0, sb = 0;
        while (sa <= a && s[sa] <= x) sa++;
        while (sb <= b && t[sb] <= x) sb++;
        sa--;
        sb--;
        printf("%lld\n", solve(x, sa, sb));
    }

    return 0;
}
// End of Code
