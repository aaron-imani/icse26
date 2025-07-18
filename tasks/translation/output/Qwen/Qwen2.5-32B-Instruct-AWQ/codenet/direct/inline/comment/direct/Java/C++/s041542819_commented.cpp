#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class DLazyFaith {
public:
    void solve(int testNumber) {
        int a, b, q;
        cin >> a >> b >> q;
        vector<long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; ++i) {
            cin >> s[i + 1];
        }
        for (int i = 0; i < b; ++i) {
            cin >> t[i + 1];
        }
        s[a + 1] = t[b + 1] = 20000000000LL;
        
        for (int i = 0; i < q; ++i) {
            long x;
            cin >> x;
            long sl = x - s[max(0, lower_bound(s.begin(), s.end(), x + 1) - s.begin() - 1)];
            long tl = x - t[max(0, lower_bound(t.begin(), t.end(), x + 1) - t.begin() - 1)];
            long sr = s[lower_bound(s.begin(), s.end(), x) - s.begin()] - x;
            long tr = t[lower_bound(t.begin(), t.end(), x) - t.begin()] - x;
            
            cout << min({
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            }) << '\n';
        }
    }

private:
    template<typename T>
    static T min(const initializer_list<T>& values) {
        return *min_element(values.begin(), values.end());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testNumber = 1;
    DLazyFaith solver;
    solver.solve(testNumber);
    
    return 0;
}

// End of Code
