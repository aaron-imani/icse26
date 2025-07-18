#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, q;
    cin >> a >> b >> q;

    vector<long long> s(a + 2);
    s[0] = -10000000000LL;
    for (int i = 1; i <= a; ++i) {
        cin >> s[i];
    }
    s[a + 1] = 20000000000LL;

    vector<long long> t(b + 2);
    t[0] = -10000000000LL;
    for (int i = 1; i <= b; ++i) {
        cin >> t[i];
    }
    t[b + 1] = 20000000000LL;

    for (int i = 0; i < q; ++i) {
        long long x;
        cin >> x;

        auto it_s = lower_bound(s.begin(), s.end(), x + 1);
        int idx_s = it_s - s.begin();
        int prev_s = max(0, idx_s - 1);
        long long sl = x - s[prev_s];

        auto it_t = lower_bound(t.begin(), t.end(), x + 1);
        int idx_t = it_t - t.begin();
        int prev_t = max(0, idx_t - 1);
        long long tl = x - t[prev_t];

        auto it_s_r = lower_bound(s.begin(), s.end(), x);
        int idx_s_r = it_s_r - s.begin();
        long long sr = s[idx_s_r] - x;

        auto it_t_r = lower_bound(t.begin(), t.end(), x);
        int idx_t_r = it_t_r - t.begin();
        long long tr = t[idx_t_r] - x;

        long long candidates[6];
        candidates[0] = max(sl, tl);
        candidates[1] = max(sr, tr);
        candidates[2] = 2 * sl + tr;
        candidates[3] = 2 * tl + sr;
        candidates[4] = sl + 2 * tr;
        candidates[5] = tl + 2 * sr;

        long long min_val = candidates[0];
        for (int j = 1; j < 6; ++j) {
            if (candidates[j] < min_val) min_val = candidates[j];
        }
        cout << min_val << '\n';
    }

    return 0;
}
// End of Code
