#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class DLazyFaith {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int a, b, q;
        in >> a >> b >> q;
        vector<long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) {
            in >> s[i + 1];
        }
        for (int i = 0; i < b; ++i) {
            in >> t[i + 1];
        }
        s[a + 1] = t[b + 1] = 20000000000LL;
        for (int i = 0; i < q; ++i) {
            long x;
            in >> x;
            long sl = x - s[max(0, lower_bound(s.begin(), s.end(), x + 1) - s.begin() - 1)];
            long tl = x - t[max(0, lower_bound(t.begin(), t.end(), x + 1) - t.begin() - 1)];
            long sr = s[lower_bound(s.begin(), s.end(), x) - s.begin()] - x;
            long tr = t[lower_bound(t.begin(), t.end(), x) - t.begin()] - x;
            out << min({
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            }) << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    DLazyFaith solver;
    solver.solve(1, cin, cout);

    return 0;
}
// End of Code
