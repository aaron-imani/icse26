#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

class DLazyFaith {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int a, b, q;
        in >> a >> b >> q;
        vector<long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; i++) {
            in >> s[i + 1];
        }
        for (int i = 0; i < b; i++) {
            in >> t[i + 1];
        }
        s[a + 1] = t[b + 1] = 20000000000LL;
        for (int i = 0; i < q; i++) {
            long x;
            in >> x;
            long sl = x - s[max(0, lowerBound(s, x + 1) - 1)];
            long tl = x - t[max(0, lowerBound(t, x + 1) - 1)];
            long sr = s[lowerBound(s, x)] - x;
            long tr = t[lowerBound(t, x)] - x;
            out << min({
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            }) << "\n";
        }
    }

private:
    int lowerBound(const vector<long>& a, long t) {
        int min = 0, max = a.size();
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
};

int main() {
    istream& in = cin;
    ostream& out = cout;
    DLazyFaith solver;
    solver.solve(1, in, out);
    return 0;
}
// End of Code
