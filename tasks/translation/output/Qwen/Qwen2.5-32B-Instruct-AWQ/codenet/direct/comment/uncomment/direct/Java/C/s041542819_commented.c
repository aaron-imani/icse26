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

void solve(int a, int b, int q) {
    for (int i = 0; i < q; i++) {
        ll x;
        scanf("%lld", &x);
        ll sl = x - s[(int)(lower_bound(s, s + a + 2, x + 1) - s) - 1];
        ll tl = x - t[(int)(lower_bound(t, t + b + 2, x + 1) - t) - 1];
        ll sr = s[(int)(lower_bound(s, s + a + 2, x) - s)] - x;
        ll tr = t[(int)(lower_bound(t, t + b + 2, x) - t)] - x;
        printf("%lld\n", min(min(max(sl, tl), max(sr, tr)),
                             min(2 * sl + tr, 2 * tl + sr),
                             min(sl + 2 * tr, tl + 2 * sr)));
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
